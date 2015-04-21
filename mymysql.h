/*
 * mymysql.h
 *
 *  Created on: 2014年5月4日
 *      Author: huashu
 */
#ifndef MYMYSQL_H_
#define MYMYSQL_H_

#define __WIN__
#ifdef __WIN__
#include <windows.h>
#include <C:/mysql/include/mysql.h>
#else
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#endif /* __WIN__ */

#include <QStandardItemModel>
#include <QStringList>

class mymysql
{
public:
	mymysql();
	virtual ~mymysql();
    int sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName);
    int sql_open(const char *DySQL, QStandardItemModel **model1);
    int sql_open_str(const char *SQL, QStringList &list);
    int sql_exec(const char *DySQL);
    void sql_disconnect();
    const char *get_error();
private:
	MYSQL *connection;
	MYSQL mysql;
    char errorbuf[1024];

};


#endif /* MYMYSQL_H_ */
