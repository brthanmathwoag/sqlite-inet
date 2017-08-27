/*
** 2017-05-12
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
******************************************************************************
**
** This SQLite extension implements inet_aton() and inet_ntoa() functions.
*/
#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT1

#ifdef _WIN32

#include <winsock2.h>

#else

#include <arpa/inet.h>

#endif

#include <assert.h>
#include <string.h>

static void inet_aton_impl(
    sqlite3_context *context,
    int argc,
    sqlite3_value **argv)
{
    const char *zIn;
    in_addr_t addr;

    assert(argc == 1);
    if (sqlite3_value_type(argv[0]) == SQLITE_NULL)
    {
        return;
    }

    zIn = (const char*)sqlite3_value_text(argv[0]);
    addr = inet_addr(zIn);

    if (addr == INADDR_NONE)
    {
        sqlite3_result_error(context, "Passed a malformed IP address", -1);
        return;
    }

    sqlite3_result_int64(context, ntohl(addr));
}

static void inet_ntoa_impl(
    sqlite3_context *context,
    int argc,
    sqlite3_value **argv)
{
    struct in_addr sInAddr;
    int nIn;
    char* zOut;
    int nOut = 0;

    assert(argc == 1);
    if (sqlite3_value_type(argv[0]) == SQLITE_NULL)
    {
        return;
    }

    nIn = sqlite3_value_int(argv[0]);
    sInAddr.s_addr = htonl(nIn);
    zOut = inet_ntoa(sInAddr);
    nOut = strlen(zOut);
    sqlite3_result_text(context, (char*)zOut, nOut, SQLITE_TRANSIENT);
}

#ifdef _WIN32
__declspec(dllexport)
#endif

int sqlite3_inet_init(
    sqlite3 *db,
    char **pzErrMsg,
    const sqlite3_api_routines *pApi)
{
    int rc = SQLITE_OK;

    SQLITE_EXTENSION_INIT2(pApi);
    (void)pzErrMsg;  /* Unused parameter */

    rc = sqlite3_create_function(
        db,
        "inet_aton",
        1,
        SQLITE_UTF8,
        0,
        inet_aton_impl,
        0,
        0);

    if (rc != SQLITE_OK) {
        return rc;
    }

    rc = sqlite3_create_function(
        db,
        "inet_ntoa",
        1,
        SQLITE_UTF8,
        0,
        inet_ntoa_impl,
        0,
        0);

    return rc;
}
