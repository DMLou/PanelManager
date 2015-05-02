/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "DbWrapper.h"

/**
 * @brief Default constructor
 */
DbWrapper::DbWrapper() : m_db(NULL)
{

}

/**
 * @brief Constructor with a specified filename
 * @param filename
 */
DbWrapper::DbWrapper(const std::string& filename)
{
    open(filename);
}

/**
 * @brief Destructor
 *
 * Closes the database if it has been opened
 */
DbWrapper::~DbWrapper()
{
    if (m_db)
    {
        sqlite3_close(m_db);
    }
}

/**
 * @brief Opens a database with the specified file name. If a database is
 * already open, the old one is closed and the new one is opened in its place.
 *
 * @param filename
 */
void DbWrapper::open(const std::string& filename) throw(DbWrapper::Error)
{
    if (m_db)
    {
        sqlite3_close(m_db);
    }

    int rc = sqlite3_open(filename.c_str(), &m_db);
    if (rc)
    {
        Error ex(sqlite3_errmsg(m_db));
        throw ex;
    }
}

/**
 * @brief DbWrapper::execute
 * @param sql
 */
void DbWrapper::execute(const std::string& sql) throw(DbWrapper::Error)
{
    char* errMsg(NULL);
    int rc = sqlite3_exec(m_db, sql.c_str(), DbWrapper::callback, this, &errMsg);
    if (rc != SQLITE_OK)
    {
        Error ex(errMsg);
        sqlite3_free(errMsg);
        throw ex;
    }
}

int DbWrapper::callback(void* wrapper, int argc, char** argv, char** azColName)
{
    (void)wrapper;
    (void)argc;
    (void)argv;
    (void)azColName;
    return 0;
}

