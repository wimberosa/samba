/*
   Unix SMB/CIFS implementation.
   Database interface wrapper
   Copyright (C) Jim McDonough <jmcd@us.ibm.com> 2006

   Major code contributions from Aleksey Fedoseev (fedoseev@ru.ibm.com)

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "includes.h"
#include "dbwrap/dbwrap.h"
#include "dbwrap/dbwrap_private.h"
#include "util_tdb.h"

/*
 * Fall back using fetch if no genuine exists operation is provided
 */

static int dbwrap_fallback_exists(struct db_context *db, TDB_DATA key)
{
	NTSTATUS status = dbwrap_parse_record(db, key, NULL, NULL);
	return NT_STATUS_IS_OK(status) ? 1 : 0;
}

static int delete_record(struct db_record *rec, void *data)
{
	NTSTATUS status = dbwrap_record_delete(rec);
	return NT_STATUS_IS_OK(status) ? 0 : -1;
}

/*
 * Fallback wipe implementation using traverse and delete if no genuine
 * wipe operation is provided
 */
static int dbwrap_fallback_wipe(struct db_context *db)
{
	NTSTATUS status = dbwrap_trans_traverse(db, delete_record, NULL);
	return NT_STATUS_IS_OK(status) ? 0 : -1;
}


/*
 * Wrapper functions for the backend methods
 */

TDB_DATA dbwrap_record_get_key(const struct db_record *rec)
{
	return rec->key;
}

TDB_DATA dbwrap_record_get_value(const struct db_record *rec)
{
	return rec->value;
}

NTSTATUS dbwrap_record_store(struct db_record *rec, TDB_DATA data, int flags)
{
	return rec->store(rec, data, flags);
}

NTSTATUS dbwrap_record_delete(struct db_record *rec)
{
	return rec->delete_rec(rec);
}

struct db_record *dbwrap_fetch_locked(struct db_context *db,
				      TALLOC_CTX *mem_ctx,
				      TDB_DATA key)
{
	return db->fetch_locked(db, mem_ctx, key);
}

struct dbwrap_fetch_state {
	TALLOC_CTX *mem_ctx;
	TDB_DATA data;
};

static void dbwrap_fetch_parser(TDB_DATA key, TDB_DATA data,
				void *private_data)
{
	struct dbwrap_fetch_state *state =
		(struct dbwrap_fetch_state *)private_data;

	state->data.dsize = data.dsize;
	state->data.dptr = (uint8_t *)talloc_memdup(state->mem_ctx, data.dptr,
						    data.dsize);
}

NTSTATUS dbwrap_fetch(struct db_context *db, TALLOC_CTX *mem_ctx,
		      TDB_DATA key, TDB_DATA *value)
{
	struct dbwrap_fetch_state state;
	NTSTATUS status;

	if (value == NULL) {
		return NT_STATUS_INVALID_PARAMETER;
	}

	state.mem_ctx = mem_ctx;

	status = dbwrap_parse_record(db, key, dbwrap_fetch_parser, &state);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}
	if ((state.data.dsize != 0) && (state.data.dptr == NULL)) {
		return NT_STATUS_NO_MEMORY;
	}
	*value = state.data;
	return NT_STATUS_OK;
}

bool dbwrap_exists(struct db_context *db, TDB_DATA key)
{
	int result;
	if (db->exists != NULL) {
		result = db->exists(db, key);
	} else {
		result = dbwrap_fallback_exists(db,key);
	}
	return (result == 1);
}

NTSTATUS dbwrap_store(struct db_context *db, TDB_DATA key,
		      TDB_DATA data, int flags)
{
	struct db_record *rec;
	NTSTATUS status;

	rec = dbwrap_fetch_locked(db, talloc_tos(), key);
	if (rec == NULL) {
		return NT_STATUS_NO_MEMORY;
	}

	status = dbwrap_record_store(rec, data, flags);
	TALLOC_FREE(rec);
	return status;
}

NTSTATUS dbwrap_delete(struct db_context *db, TDB_DATA key)
{
	struct db_record *rec;
	NTSTATUS status;

	rec = dbwrap_fetch_locked(db, talloc_tos(), key);
	if (rec == NULL) {
		return NT_STATUS_NO_MEMORY;
	}
	status = dbwrap_record_delete(rec);
	TALLOC_FREE(rec);
	return status;
}

NTSTATUS dbwrap_traverse(struct db_context *db,
			 int (*f)(struct db_record*, void*),
			 void *private_data,
			 int *count)
{
	int ret = db->traverse(db, f, private_data);

	if (ret < 0) {
		return NT_STATUS_INTERNAL_DB_CORRUPTION;
	}

	if (count != NULL) {
		*count = ret;
	}

	return NT_STATUS_OK;
}

NTSTATUS dbwrap_traverse_read(struct db_context *db,
			      int (*f)(struct db_record*, void*),
			      void *private_data,
			      int *count)
{
	int ret = db->traverse_read(db, f, private_data);

	if (ret < 0) {
		return NT_STATUS_INTERNAL_DB_CORRUPTION;
	}

	if (count != NULL) {
		*count = ret;
	}

	return NT_STATUS_OK;
}

static void dbwrap_null_parser(TDB_DATA key, TDB_DATA val, void* data)
{
	return;
}

NTSTATUS dbwrap_parse_record(struct db_context *db, TDB_DATA key,
			     void (*parser)(TDB_DATA key, TDB_DATA data,
					    void *private_data),
			     void *private_data)
{
	if (parser == NULL) {
		parser = dbwrap_null_parser;
	}
	return db->parse_record(db, key, parser, private_data);
}

int dbwrap_wipe(struct db_context *db)
{
	if (db->wipe == NULL) {
		return dbwrap_fallback_wipe(db);
	}
	return db->wipe(db);
}

int dbwrap_get_seqnum(struct db_context *db)
{
	return db->get_seqnum(db);
}

int dbwrap_get_flags(struct db_context *db)
{
	return db->get_flags(db);
}

int dbwrap_transaction_start(struct db_context *db)
{
	return db->transaction_start(db);
}

int dbwrap_transaction_commit(struct db_context *db)
{
	return db->transaction_commit(db);
}

int dbwrap_transaction_cancel(struct db_context *db)
{
	return db->transaction_cancel(db);
}
