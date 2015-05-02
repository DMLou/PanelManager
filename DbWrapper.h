/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef DBWRAPPER_H
#define DBWRAPPER_H

#include <string>
#include <stdexcept>
#include <external/sqlite/sqlite3.h>

class DbWrapper
{
public:
    /// Database error exception class
    class Error : public std::exception
    {
    public:
        Error(const std::string& msg) throw() : m_msg(msg) { }
        virtual ~Error() throw() { }
        virtual const char* what() const throw() { return m_msg.c_str(); }

    private:
        std::string m_msg;      ///< Error message
    };

    DbWrapper();
    DbWrapper(const std::string& filename);
    ~DbWrapper();

    static int callback(void* wrapper, int argc, char** argv, char** azColName);

    void open(const std::string& filename) throw(Error);
    void execute(const std::string& sql) throw(Error);

private:
    sqlite3* m_db;      ///< Database pointer
};

#endif // DBWRAPPER_H
