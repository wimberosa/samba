/*
   Python interface to passdb

   Copyright (C) Amitay Isaacs 2011

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

#include <Python.h>
#include <pytalloc.h>
#include "includes.h"
#include "lib/util/talloc_stack.h"
#include "libcli/security/security.h"
#include "passdb.h"
#include "secrets.h"

#ifndef Py_RETURN_NONE
#define Py_RETURN_NONE	return Py_INCREF(Py_None), Py_None
#endif

#ifndef PY_CHECK_TYPE
#define PY_CHECK_TYPE(type, var, fail) \
	if (!PyObject_TypeCheck(var, type)) {\
		PyErr_Format(PyExc_TypeError, __location__ ": Expected type '%s' for '%s' of type '%s'", (type)->tp_name, #var, Py_TYPE(var)->tp_name); \
		fail; \
	}
#endif


static PyTypeObject *dom_sid_Type = NULL;

staticforward PyTypeObject PySamu;
staticforward PyTypeObject PyPDB;

static PyObject *py_pdb_error;

void initpassdb(void);


/************************** PIDL Autogeneratd ******************************/

static PyObject *py_samu_get_logon_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_logon_time;

	py_logon_time = PyInt_FromLong(pdb_get_logon_time(sam_acct));
	return py_logon_time;
}

static int py_samu_set_logon_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_logon_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_logoff_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_logoff_time;

	py_logoff_time = PyInt_FromLong(pdb_get_logoff_time(sam_acct));
	return py_logoff_time;
}

static int py_samu_set_logoff_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_logoff_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_kickoff_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_kickoff_time;

	py_kickoff_time = PyInt_FromLong(pdb_get_kickoff_time(sam_acct));
	return py_kickoff_time;
}

static int py_samu_set_kickoff_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_kickoff_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_bad_password_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_bad_password_time;

	py_bad_password_time = PyInt_FromLong(pdb_get_bad_password_time(sam_acct));
	return py_bad_password_time;
}

static int py_samu_set_bad_password_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_bad_password_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_pass_last_set_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_pass_last_set_time;

	py_pass_last_set_time = PyInt_FromLong(pdb_get_pass_last_set_time(sam_acct));
	return py_pass_last_set_time;
}

static int py_samu_set_pass_last_set_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_pass_last_set_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_pass_can_change_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_pass_can_change_time;

	py_pass_can_change_time = PyInt_FromLong(pdb_get_pass_can_change_time(sam_acct));
	return py_pass_can_change_time;
}

static int py_samu_set_pass_can_change_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_pass_can_change_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_pass_must_change_time(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_pass_must_change_time;

	py_pass_must_change_time = PyInt_FromLong(pdb_get_pass_must_change_time(sam_acct));
	return py_pass_must_change_time;
}

static int py_samu_set_pass_must_change_time(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_pass_must_change_time(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_username(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_username;
	const char *username;

	username = pdb_get_username(sam_acct);
	if (username == NULL) {
		Py_RETURN_NONE;
	}

	py_username = PyString_FromString(username);
	return py_username;
}

static int py_samu_set_username(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_username(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_domain(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_domain;
	const char *domain;

	domain = pdb_get_domain(sam_acct);
	if (domain == NULL) {
		Py_RETURN_NONE;
	}

	py_domain = PyString_FromString(domain);
	return py_domain;
}

static int py_samu_set_domain(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_domain(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_nt_username(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_nt_username;
	const char *nt_username;

	nt_username = pdb_get_nt_username(sam_acct);
	if (nt_username == NULL) {
		Py_RETURN_NONE;
	}

	py_nt_username = PyString_FromString(nt_username);
	return py_nt_username;
}

static int py_samu_set_nt_username(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_nt_username(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_full_name(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_full_name;
	const char *full_name;

	full_name = pdb_get_fullname(sam_acct);
	if (full_name == NULL) {
		Py_RETURN_NONE;
	}

	py_full_name = PyString_FromString(full_name);
	return py_full_name;
}

static int py_samu_set_full_name(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_fullname(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_home_dir(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_home_dir;
	const char *home_dir;

	home_dir = pdb_get_homedir(sam_acct);
	if (home_dir == NULL) {
		Py_RETURN_NONE;
	}

	py_home_dir = PyString_FromString(home_dir);
	return py_home_dir;
}

static int py_samu_set_home_dir(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_homedir(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_dir_drive(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_dir_drive;
	const char *dir_drive;

	dir_drive = pdb_get_dir_drive(sam_acct);
	if (dir_drive == NULL) {
		Py_RETURN_NONE;
	}

	py_dir_drive = PyString_FromString(dir_drive);
	return py_dir_drive;
}

static int py_samu_set_dir_drive(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_dir_drive(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_logon_script(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_logon_script;
	const char *logon_script;

	logon_script = pdb_get_logon_script(sam_acct);
	if (logon_script == NULL) {
		Py_RETURN_NONE;
	}

	py_logon_script = PyString_FromString(logon_script);
	return py_logon_script;
}

static int py_samu_set_logon_script(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_logon_script(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_profile_path(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_profile_path;
	const char *profile_path;

	profile_path = pdb_get_profile_path(sam_acct);
	if (profile_path == NULL) {
		Py_RETURN_NONE;
	}

	py_profile_path = PyString_FromString(profile_path);
	return py_profile_path;
}

static int py_samu_set_profile_path(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_profile_path(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_acct_desc(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_acct_desc;
	const char *acct_desc;

	acct_desc = pdb_get_acct_desc(sam_acct);
	if (acct_desc == NULL) {
		Py_RETURN_NONE;
	}

	py_acct_desc = PyString_FromString(acct_desc);
	return py_acct_desc;
}

static int py_samu_set_acct_desc(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_acct_desc(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_workstations(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_workstations;
	const char *workstations;

	workstations = pdb_get_workstations(sam_acct);
	if (workstations == NULL) {
		Py_RETURN_NONE;
	}

	py_workstations = PyString_FromString(workstations);
	return py_workstations;
}

static int py_samu_set_workstations(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_workstations(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_comment(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_comment;
	const char *comment;

	comment = pdb_get_comment(sam_acct);
	if (comment == NULL) {
		Py_RETURN_NONE;
	}

	py_comment = PyString_FromString(comment);
	return py_comment;
}

static int py_samu_set_comment(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_comment(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_munged_dial(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_munged_dial;
	const char *munged_dial;

	munged_dial = pdb_get_munged_dial(sam_acct);
	if (munged_dial == NULL) {
		Py_RETURN_NONE;
	}

	py_munged_dial = PyString_FromString(munged_dial);
	return py_munged_dial;
}

static int py_samu_set_munged_dial(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_munged_dial(sam_acct, PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_user_sid(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_user_sid;
	const struct dom_sid *user_sid;
	struct dom_sid *copy_user_sid;
	TALLOC_CTX *mem_ctx;

	user_sid = pdb_get_user_sid(sam_acct);
	if(user_sid == NULL) {
		Py_RETURN_NONE;
	}

	mem_ctx = talloc_new(NULL);
	if (mem_ctx == NULL) {
		PyErr_NoMemory();
		return NULL;
	}
	copy_user_sid = dom_sid_dup(mem_ctx, user_sid);
	if (copy_user_sid == NULL) {
		PyErr_NoMemory();
		talloc_free(mem_ctx);
		return NULL;
	}

	py_user_sid = pytalloc_steal(dom_sid_Type, copy_user_sid);

	talloc_free(mem_ctx);

	return py_user_sid;
}

static int py_samu_set_user_sid(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(dom_sid_Type, value, return -1;);
	if (!pdb_set_user_sid(sam_acct, (struct dom_sid *)pytalloc_get_ptr(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_group_sid(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_group_sid;
	const struct dom_sid *group_sid;
	struct dom_sid *copy_group_sid;
	TALLOC_CTX *mem_ctx;

	group_sid = pdb_get_group_sid(sam_acct);
	if (group_sid == NULL) {
		Py_RETURN_NONE;
	}

	mem_ctx = talloc_new(NULL);
	if (mem_ctx == NULL) {
		PyErr_NoMemory();
		return NULL;
	}
	copy_group_sid = dom_sid_dup(mem_ctx, group_sid);
	if (copy_group_sid == NULL) {
		PyErr_NoMemory();
		talloc_free(mem_ctx);
		return NULL;
	}

	py_group_sid = pytalloc_steal(dom_sid_Type, copy_group_sid);

	talloc_free(mem_ctx);

	return py_group_sid;
}

static int py_samu_set_group_sid(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(dom_sid_Type, value, return -1;);
	if (!pdb_set_group_sid(sam_acct, (struct dom_sid *)pytalloc_get_ptr(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_lanman_passwd(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_lm_pw;
	const char *lm_pw;

	lm_pw = (const char *)pdb_get_lanman_passwd(sam_acct);
	if (lm_pw == NULL) {
		Py_RETURN_NONE;
	}

	py_lm_pw = PyString_FromString(lm_pw);
	return py_lm_pw;
}

static int py_samu_set_lanman_passwd(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyString_Type, value, return -1;);
	if (!pdb_set_lanman_passwd(sam_acct, (uint8_t *)PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_nt_passwd(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_nt_pw;
	const char *nt_pw;

	nt_pw = (const char *)pdb_get_nt_passwd(sam_acct);
	if (nt_pw == NULL) {
		Py_RETURN_NONE;
	}

	py_nt_pw = PyString_FromString(nt_pw);
	return py_nt_pw;
}

static int py_samu_set_nt_passwd(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	if (!pdb_set_nt_passwd(sam_acct, (uint8_t *)PyString_AsString(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_pw_history(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_nt_pw_his;
	const char *nt_pw_his;
	uint32_t hist_len;

	nt_pw_his = (const char *)pdb_get_pw_history(sam_acct, &hist_len);
	if (nt_pw_his == NULL) {
		Py_RETURN_NONE;
	}

	py_nt_pw_his = PyString_FromStringAndSize(nt_pw_his, hist_len);
	return py_nt_pw_his;
}

static int py_samu_set_pw_history(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	char *nt_pw_his;
	Py_ssize_t len;
	uint32_t hist_len;

	PyString_AsStringAndSize(value, &nt_pw_his, &len);
	hist_len = len;
	if (!pdb_set_pw_history(sam_acct, (uint8_t *)nt_pw_his, hist_len, PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_plaintext_passwd(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_plaintext_pw;
	const char *plaintext_pw;

	plaintext_pw = pdb_get_plaintext_passwd(sam_acct);
	if (plaintext_pw == NULL) {
		Py_RETURN_NONE;
	}

	py_plaintext_pw = PyString_FromString(plaintext_pw);
	return py_plaintext_pw;
}

static int py_samu_set_plaintext_passwd(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	if (!pdb_set_plaintext_passwd(sam_acct, PyString_AsString(value))) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_acct_ctrl(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_acct_ctrl;

	py_acct_ctrl = PyInt_FromLong(pdb_get_acct_ctrl(sam_acct));
	return py_acct_ctrl;
}

static int py_samu_set_acct_ctrl(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_acct_ctrl(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_logon_divs(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_logon_divs;

	py_logon_divs = PyInt_FromLong(pdb_get_logon_divs(sam_acct));
	return py_logon_divs;
}

static int py_samu_set_logon_divs(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_logon_divs(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_hours_len(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_hours_len;

	py_hours_len = PyInt_FromLong(pdb_get_hours_len(sam_acct));
	return py_hours_len;
}

static int py_samu_set_hours_len(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_hours_len(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_hours(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_hours;
	const char *hours;
	int i;

	hours = (const char *)pdb_get_hours(sam_acct);
	if(! hours) {
		Py_RETURN_NONE;
	}

	if ((py_hours = PyList_New(MAX_HOURS_LEN)) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	for (i=0; i<MAX_HOURS_LEN; i++) {
		PyList_SetItem(py_hours, i, PyInt_FromLong(hours[i]));
	}
	return py_hours;
}

static int py_samu_set_hours(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	int i;
	uint8_t *hours;
	int hours_len;
	bool status;

	PY_CHECK_TYPE(&PyList_Type, value, return -1;);

	hours_len = PyList_GET_SIZE(value);

	hours = talloc_array(pytalloc_get_mem_ctx(obj), uint8_t, hours_len);
	if (!hours) {
		PyErr_NoMemory();
		return -1;
	}

	for (i=0; i < hours_len; i++) {
		PY_CHECK_TYPE(&PyInt_Type, PyList_GET_ITEM(value,i), return -1;);
		hours[i] = PyInt_AsLong(PyList_GET_ITEM(value, i));
	}

	status = pdb_set_hours(sam_acct, hours, hours_len, PDB_CHANGED);
	talloc_free(hours);

	if(! status) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_bad_password_count(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_bad_password_count;

	py_bad_password_count = PyInt_FromLong(pdb_get_bad_password_count(sam_acct));
	return py_bad_password_count;
}

static int py_samu_set_bad_password_count(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_bad_password_count(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_logon_count(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_logon_count;

	py_logon_count = PyInt_FromLong(pdb_get_logon_count(sam_acct));
	return py_logon_count;
}

static int py_samu_set_logon_count(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_logon_count(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_country_code(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_country_code;

	py_country_code = PyInt_FromLong(pdb_get_country_code(sam_acct));
	return py_country_code;
}

static int py_samu_set_country_code(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_country_code(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyObject *py_samu_get_code_page(PyObject *obj, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);
	PyObject *py_code_page;

	py_code_page = PyInt_FromLong(pdb_get_code_page(sam_acct));
	return py_code_page;
}

static int py_samu_set_code_page(PyObject *obj, PyObject *value, void *closure)
{
	struct samu *sam_acct = (struct samu *)pytalloc_get_ptr(obj);

	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	if (!pdb_set_code_page(sam_acct, PyInt_AsLong(value), PDB_CHANGED)) {
		return -1;
	}
	return 0;
}

static PyGetSetDef py_samu_getsetters[] = {
	{ discard_const_p(char, "logon_time"), py_samu_get_logon_time, py_samu_set_logon_time },
	{ discard_const_p(char, "logoff_time"), py_samu_get_logoff_time, py_samu_set_logoff_time },
	{ discard_const_p(char, "kickoff_time"), py_samu_get_kickoff_time, py_samu_set_kickoff_time },
	{ discard_const_p(char, "bad_password_time"), py_samu_get_bad_password_time, py_samu_set_bad_password_time },
	{ discard_const_p(char, "pass_last_set_time"), py_samu_get_pass_last_set_time, py_samu_set_pass_last_set_time },
	{ discard_const_p(char, "pass_can_change_time"), py_samu_get_pass_can_change_time, py_samu_set_pass_can_change_time },
	{ discard_const_p(char, "pass_must_change_time"), py_samu_get_pass_must_change_time, py_samu_set_pass_must_change_time },
	{ discard_const_p(char, "username"), py_samu_get_username, py_samu_set_username },
	{ discard_const_p(char, "domain"), py_samu_get_domain, py_samu_set_domain },
	{ discard_const_p(char, "nt_username"), py_samu_get_nt_username, py_samu_set_nt_username },
	{ discard_const_p(char, "full_name"), py_samu_get_full_name, py_samu_set_full_name },
	{ discard_const_p(char, "home_dir"), py_samu_get_home_dir, py_samu_set_home_dir },
	{ discard_const_p(char, "dir_drive"), py_samu_get_dir_drive, py_samu_set_dir_drive },
	{ discard_const_p(char, "logon_script"), py_samu_get_logon_script, py_samu_set_logon_script },
	{ discard_const_p(char, "profile_path"), py_samu_get_profile_path, py_samu_set_profile_path },
	{ discard_const_p(char, "acct_desc"), py_samu_get_acct_desc, py_samu_set_acct_desc },
	{ discard_const_p(char, "workstations"), py_samu_get_workstations, py_samu_set_workstations },
	{ discard_const_p(char, "comment"), py_samu_get_comment, py_samu_set_comment },
	{ discard_const_p(char, "munged_dial"), py_samu_get_munged_dial, py_samu_set_munged_dial },
	{ discard_const_p(char, "user_sid"), py_samu_get_user_sid, py_samu_set_user_sid },
	{ discard_const_p(char, "group_sid"), py_samu_get_group_sid, py_samu_set_group_sid },
	{ discard_const_p(char, "lanman_passwd"), py_samu_get_lanman_passwd, py_samu_set_lanman_passwd },
	{ discard_const_p(char, "nt_passwd"), py_samu_get_nt_passwd, py_samu_set_nt_passwd },
	{ discard_const_p(char, "pw_history"), py_samu_get_pw_history, py_samu_set_pw_history },
	{ discard_const_p(char, "plaintext_passwd"), py_samu_get_plaintext_passwd, py_samu_set_plaintext_passwd },
	{ discard_const_p(char, "acct_ctrl"), py_samu_get_acct_ctrl, py_samu_set_acct_ctrl },
	{ discard_const_p(char, "logon_divs"), py_samu_get_logon_divs, py_samu_set_logon_divs },
	{ discard_const_p(char, "hours_len"), py_samu_get_hours_len, py_samu_set_hours_len },
	{ discard_const_p(char, "hours"), py_samu_get_hours, py_samu_set_hours },
	{ discard_const_p(char, "bad_password_count"), py_samu_get_bad_password_count, py_samu_set_bad_password_count },
	{ discard_const_p(char, "logon_count"), py_samu_get_logon_count, py_samu_set_logon_count },
	{ discard_const_p(char, "country_code"), py_samu_get_country_code, py_samu_set_country_code },
	{ discard_const_p(char, "code_page"), py_samu_get_code_page, py_samu_set_code_page },
	{ NULL }
};


/************************** PIDL Autogeneratd ******************************/

static PyObject *py_samu_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	struct samu *sam_acct;

	sam_acct = samu_new(NULL);
	if (!sam_acct) {
		PyErr_NoMemory();
		return NULL;
	}

	return pytalloc_steal(type, sam_acct);
}

static PyTypeObject PySamu = {
	.tp_name = "passdb.samu",
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_getset = py_samu_getsetters,
	.tp_methods = NULL,
	.tp_new = py_samu_new,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_doc = "samu() -> samu object\n",
};


static PyObject *py_pdb_domain_info(pytalloc_Object *self, PyObject *args)
{
	struct pdb_methods *methods;
	struct pdb_domain_info *domain_info;
	PyObject *py_domain_info;

	methods = pytalloc_get_ptr(self);

	domain_info = methods->get_domain_info(methods, pytalloc_get_mem_ctx(self));
	if (! domain_info) {
		Py_RETURN_NONE;
	}

	if ((py_domain_info = PyDict_New()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	PyDict_SetItemString(py_domain_info, "name", PyString_FromString(domain_info->name));
	PyDict_SetItemString(py_domain_info, "dns_domain", PyString_FromString(domain_info->name));
	PyDict_SetItemString(py_domain_info, "dns_forest", PyString_FromString(domain_info->name));
	/*
	struct dom_sid sid;
	struct GUID guid;
	*/

	talloc_free(domain_info);

	return py_domain_info;
}


static PyObject *py_pdb_getsampwnam(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	const char *username;
	struct pdb_methods *methods;
	struct samu *sam_acct;
	PyObject *py_sam_acct;
	TALLOC_CTX *tframe;

	if (!PyArg_ParseTuple(args, "s:getsampwnam", &username)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	py_sam_acct = py_samu_new(&PySamu, NULL, NULL);
	if (py_sam_acct == NULL) {
		PyErr_NoMemory();
		talloc_free(tframe);
		return NULL;
	}
	sam_acct = (struct samu *)pytalloc_get_ptr(py_sam_acct);

	status = methods->getsampwnam(methods, sam_acct, username);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to get user information for '%s', (%d,%s)",
				username,
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		Py_DECREF(py_sam_acct);
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	return py_sam_acct;
}

static PyObject *py_pdb_getsampwsid(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	struct samu *sam_acct;
	PyObject *py_sam_acct;
	TALLOC_CTX *tframe;
	PyObject *py_user_sid;

	if (!PyArg_ParseTuple(args, "O:getsampwsid", &py_user_sid)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	py_sam_acct = py_samu_new(&PySamu, NULL, NULL);
	if (py_sam_acct == NULL) {
		PyErr_NoMemory();
		talloc_free(tframe);
		return NULL;
	}
	sam_acct = (struct samu *)pytalloc_get_ptr(py_sam_acct);

	status = methods->getsampwsid(methods, sam_acct, pytalloc_get_ptr(py_user_sid));
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to get user information from SID, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		Py_DECREF(py_sam_acct);
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	return py_sam_acct;
}

static PyObject *py_pdb_create_user(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	const char *username;
	unsigned int acct_flags;
	unsigned int rid;
	TALLOC_CTX *tframe;

	if (!PyArg_ParseTuple(args, "sI:create_user", &username, &acct_flags)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	status = methods->create_user(methods, tframe, username, acct_flags, &rid);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to create user (%s), (%d,%s)",
				username,
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	return PyInt_FromLong(rid);
}

static PyObject *py_pdb_delete_user(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	TALLOC_CTX *tframe;
	struct samu *sam_acct;
	PyObject *py_sam_acct;

	if (!PyArg_ParseTuple(args, "O!:delete_user", &PySamu, &py_sam_acct)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	sam_acct = pytalloc_get_ptr(py_sam_acct);

	status = methods->delete_user(methods, tframe, sam_acct);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to delete user, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	Py_RETURN_NONE;
}

static PyObject *py_pdb_add_sam_account(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	TALLOC_CTX *tframe;
	struct samu *sam_acct;
	PyObject *py_sam_acct;

	if (!PyArg_ParseTuple(args, "O!:add_sam_account", &PySamu, &py_sam_acct)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	sam_acct = pytalloc_get_ptr(py_sam_acct);

	status = methods->add_sam_account(methods, sam_acct);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to add sam account, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	Py_RETURN_NONE;
}

static PyObject *py_pdb_update_sam_account(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	TALLOC_CTX *tframe;
	struct samu *sam_acct;
	PyObject *py_sam_acct;

	if (!PyArg_ParseTuple(args, "O!:update_sam_account", &PySamu, &py_sam_acct)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	sam_acct = pytalloc_get_ptr(py_sam_acct);

	status = methods->update_sam_account(methods, sam_acct);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to update sam account, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	Py_RETURN_NONE;
}

static PyObject *py_pdb_delete_sam_account(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	TALLOC_CTX *tframe;
	struct samu *sam_acct;
	PyObject *py_sam_acct;

	if (!PyArg_ParseTuple(args, "O!:delete_sam_account", &PySamu, &py_sam_acct)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	sam_acct = pytalloc_get_ptr(py_sam_acct);

	status = methods->delete_sam_account(methods, sam_acct);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to delete sam account, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	Py_RETURN_NONE;
}

static PyObject *py_pdb_rename_sam_account(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	TALLOC_CTX *tframe;
	struct samu *sam_acct;
	const char *new_username;
	PyObject *py_sam_acct;

	if (!PyArg_ParseTuple(args, "O!s:rename_sam_account", &PySamu, &py_sam_acct,
					&new_username)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	sam_acct = pytalloc_get_ptr(py_sam_acct);

	status = methods->rename_sam_account(methods, sam_acct, new_username);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Unable to rename sam account, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	talloc_free(tframe);
	Py_RETURN_NONE;
}

static PyObject *py_pdb_search_users(pytalloc_Object *self, PyObject *args)
{
	NTSTATUS status;
	struct pdb_methods *methods;
	TALLOC_CTX *tframe;
	unsigned int acct_flags;
	struct pdb_search *search;
	struct samr_displayentry *entry;
	PyObject *py_userlist, *py_dict;

	if (!PyArg_ParseTuple(args, "I:search_users", &acct_flags)) {
		return NULL;
	}

	methods = pytalloc_get_ptr(self);

	if ((tframe = talloc_stackframe()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	search = talloc_zero(tframe, struct pdb_search);
	if (search == NULL) {
		PyErr_NoMemory();
		talloc_free(tframe);
		return NULL;
	}

	if (!methods->search_users(methods, search, acct_flags)) {
		PyErr_Format(py_pdb_error, "Unable to search users, (%d,%s)",
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		talloc_free(tframe);
		return NULL;
	}

	entry = talloc_zero(tframe, struct samr_displayentry);
	if (entry == NULL) {
		PyErr_NoMemory();
		talloc_free(tframe);
		return NULL;
	}

	py_userlist = PyList_New(0);
	if (py_userlist == NULL) {
		PyErr_NoMemory();
		talloc_free(tframe);
		return NULL;
	}

	while (search->next_entry(search, entry)) {
		py_dict = PyDict_New();
		if (py_dict == NULL) {
			PyErr_NoMemory();
		} else {
			PyDict_SetItemString(py_dict, "idx", PyInt_FromLong(entry->idx));
			PyDict_SetItemString(py_dict, "rid", PyInt_FromLong(entry->rid));
			PyDict_SetItemString(py_dict, "acct_flags", PyInt_FromLong(entry->acct_flags));
			PyDict_SetItemString(py_dict, "account_name", PyString_FromString(entry->account_name));
			PyDict_SetItemString(py_dict, "fullname", PyString_FromString(entry->fullname));
			PyDict_SetItemString(py_dict, "description", PyString_FromString(entry->description));
			PyList_Append(py_userlist, py_dict);
		}
	}
	search->search_end(search);

	talloc_free(tframe);

	return py_userlist;
}

static PyMethodDef py_pdb_methods[] = {
	{ "domain_info", (PyCFunction)py_pdb_domain_info, METH_NOARGS,
		"domain_info() -> str\n\n \
		Get domain for the database." },
	{ "getsampwnam", (PyCFunction)py_pdb_getsampwnam, METH_VARARGS,
		"getsampwnam(username) -> samu object\n\n \
		Get user information." },
	{ "getsampwsid", (PyCFunction)py_pdb_getsampwsid, METH_VARARGS,
		"getsampwsid(sid) -> samu object\n\n \
		Get user information from user_sid (dcerpc.security.dom_sid object)." },
	{ "create_user", (PyCFunction)py_pdb_create_user, METH_VARARGS,
		"create_user(username, acct_flags) -> rid\n\n \
		Create user. acct_flags are samr account control flags." },
	{ "delete_user", (PyCFunction)py_pdb_delete_user, METH_VARARGS,
		"delete_user(samu object) -> None\n\n \
		Delete user." },
	{ "add_sam_account", (PyCFunction)py_pdb_add_sam_account, METH_VARARGS,
		"add_sam_account(samu object) -> None\n\n \
		Add SAM account." },
	{ "update_sam_account", (PyCFunction)py_pdb_update_sam_account, METH_VARARGS,
		"update_sam_account(samu object) -> None\n\n \
		Update SAM account." },
	{ "delete_sam_account", (PyCFunction)py_pdb_delete_sam_account, METH_VARARGS,
		"delete_sam_account(samu object) -> None\n\n \
		Delete SAM account." },
	{ "rename_sam_account", (PyCFunction)py_pdb_rename_sam_account, METH_VARARGS,
		"rename_sam_account(samu object1, new_username) -> None\n\n \
		Rename SAM account." },
	{ "search_users", (PyCFunction)py_pdb_search_users, METH_VARARGS,
		"search_users(acct_flags) -> List\n\n \
		Search users. acct_flags are samr account control flags.\n \
		Each entry in the list is a dictionary with keys - \
		idx, rid, acct_flags, account_name, fullname, description." },
	{ NULL },
};


static PyObject *py_pdb_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	const char *url = NULL;
	PyObject *pypdb;
	NTSTATUS status;
	struct pdb_methods *methods;

	if (!PyArg_ParseTuple(args, "s", &url)) {
		return NULL;
	}

	/* Initalize list of methods */
	status = make_pdb_method_name(&methods, url);
	if (!NT_STATUS_IS_OK(status)) {
		PyErr_Format(py_pdb_error, "Cannot load backend methods for '%s' backend (%d,%s)",
				url,
				NT_STATUS_V(status),
				get_friendly_nt_error_msg(status));
		return NULL;
	}

	if ((pypdb = pytalloc_steal(type, methods)) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	return pypdb;
}


static PyTypeObject PyPDB = {
	.tp_name = "passdb.PDB",
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_pdb_new,
	.tp_flags = Py_TPFLAGS_DEFAULT,
	.tp_methods = py_pdb_methods,
	.tp_doc = "PDB(url[, read_write_flags]) -> Password DB object\n",
};


/*
 * Return a list of passdb backends
 */
static PyObject *py_passdb_backends(PyObject *self)
{
	PyObject *py_blist;
	const struct pdb_init_function_entry *entry;

	entry = pdb_get_backends();
	if(! entry) {
		Py_RETURN_NONE;
	}

	if((py_blist = PyList_New(0)) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	while(entry) {
		PyList_Append(py_blist, PyString_FromString(entry->name));
		entry = entry->next;
	}

	return py_blist;
}


static PyObject *py_set_smb_config(PyObject *self, PyObject *args)
{
	const char *smb_config;

	if (!PyArg_ParseTuple(args, "s", &smb_config)) {
		return NULL;
	}

	/* Load smbconf parameters */
	if (!lp_load_global(smb_config)) {
		PyErr_Format(py_pdb_error, "Cannot open '%s'", smb_config);
		return NULL;
	}

	Py_RETURN_NONE;
}


static PyObject *py_set_secrets_dir(PyObject *self, PyObject *args)
{
	const char *private_dir;

	if (!PyArg_ParseTuple(args, "s", &private_dir)) {
		return NULL;
	}

	/* Initialize secrets database */
	if (!secrets_init_path(private_dir)) {
		PyErr_Format(py_pdb_error, "Cannot open secrets file database in '%s'",
				private_dir);
		return NULL;
	}

	Py_RETURN_NONE;
}


static PyMethodDef py_passdb_methods[] = {
	{ "get_backends", (PyCFunction)py_passdb_backends, METH_NOARGS,
		"get_backends() -> list\n\n \
		Get a list of password database backends supported." },
	{ "set_smb_config", (PyCFunction)py_set_smb_config, METH_VARARGS,
		"set_smb_config(path) -> None\n\n \
		Set path to smb.conf file to load configuration parameters." },
	{ "set_secrets_dir", (PyCFunction)py_set_secrets_dir, METH_VARARGS,
		"set_secrets_dir(private_dir) -> None\n\n \
		Set path to private directory to load secrets database from non-default location." },
	{ NULL },
};

void initpassdb(void)
{
	PyObject *m, *mod;
	char exception_name[] = "passdb.error";

	PyTypeObject *talloc_type = pytalloc_GetObjectType();
	if (talloc_type == NULL) {
		return;
	}

	PyPDB.tp_base = talloc_type;
	if (PyType_Ready(&PyPDB) < 0) {
		return;
	}

	PySamu.tp_base = talloc_type;
	if (PyType_Ready(&PySamu) < 0) {
		return;
	}

	m = Py_InitModule3("passdb", py_passdb_methods, "SAMBA Password Database");
	if (m == NULL) {
	    return;
	}

	/* Create new exception for passdb module */
	py_pdb_error = PyErr_NewException(exception_name, NULL, NULL);
	Py_INCREF(py_pdb_error);
	PyModule_AddObject(m, "error", py_pdb_error);

	Py_INCREF(&PyPDB);
	PyModule_AddObject(m, "PDB", (PyObject *)&PyPDB);

	/* Import dom_sid type from dcerpc.security */
	mod = PyImport_ImportModule("samba.dcerpc.security");
	if (mod == NULL) {
		return;
	}

	dom_sid_Type = (PyTypeObject *)PyObject_GetAttrString(mod, "dom_sid");
	Py_DECREF(mod);
	if (dom_sid_Type == NULL) {
		return;
	}

	/* FIXME: Load passdb backends
	 *        Currently there is no equivalent public function for lazy_initialize_passdb()
	 */
}