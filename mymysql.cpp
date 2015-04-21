/*
 * mymysql.cpp
 *
 *  Created on: 2014年5月27日
 *      Author: huashu
 */

#include "mymysql.h"

mymysql::mymysql()
{
    memset(errorbuf, 0, sizeof(errorbuf));
    connection = NULL;
    mysql_init(&mysql);
}

mymysql::~mymysql()
{
    if (connection)
    {
        mysql_close(connection);
    }
}

//连接到mysql数据库
int mymysql::sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName)
{

    connection = mysql_real_connect(&mysql, Hostname, User, Password,
                                    DBName, 0, 0, 0);

    if (connection == NULL)
    {
        memset(errorbuf, 0, sizeof(errorbuf));
        strcpy(errorbuf, mysql_error(&mysql));
        return -1;
    }
    return 0;
}

//断开数据库连接
void mymysql::sql_disconnect()
{
    if (connection)
    {
        mysql_close(connection);
        connection = NULL;
    }
}

//执行SELECT语句
int mymysql::sql_open(const char *SQL, QStandardItemModel **model1)//执行有返回数据集的SQL语句
{
    int state = mysql_query(connection, SQL);//执行SQL语句
    if (state != 0)
    {
        memset(errorbuf, 0, sizeof(errorbuf));
        strcpy(errorbuf, mysql_error(&mysql));
        return -1;//执行失败，返回-1
    }

    MYSQL_RES *result = mysql_store_result(connection);//得到查询结果
    if (result == (MYSQL_RES *) NULL)
    {
        memset(errorbuf, 0, sizeof(errorbuf));
        strcpy(errorbuf, mysql_error(&mysql));
        return -1;//执行失败，返回-1
    } else
    {
        //根据表中行，列的数量建立model
        *model1 = new QStandardItemModel(mysql_affected_rows(connection),
                                         mysql_field_count(connection));
        MYSQL_FIELD *sqlField;
        int iFieldCount = 0;
        while (1)//循环遍历所有字段
        {
            sqlField = mysql_fetch_field(result);
            if (sqlField == NULL)
                break;
            (*model1)->setHeaderData(iFieldCount, Qt::Horizontal, sqlField->name);//将表的列名，放入model1的列名中
            iFieldCount++;
        }

        MYSQL_ROW sqlRow;
        int j = 0;
        while (1)//循环遍历每一行
        {
            sqlRow = mysql_fetch_row(result);
            if (sqlRow == NULL)
                break;
            int i;
            for (i = 0; i < iFieldCount; i++)//循环得到每一行中的每个字段
            {
                if (sqlRow[i] == NULL)//如果值为NULL，向model中插入字符串"NULL"
                {
                    (*model1)->setData((*model1)->index(j, i, QModelIndex()), "NULL");//将行中的每一列的值放入model1中
                }else
                {
                    (*model1)->setData((*model1)->index(j, i, QModelIndex()), (const char *)sqlRow[i]);//将行中的每一列的值放入model1中
                }
            }
            j++;

        }
        //printf("query is ok, %u rows affected\n", (unsigned int)mysql_affected_rows(connection));
        mysql_free_result(result);
    }
    return 0;
}

//执行SELECT语句，将查询结果放入QStringList当中
int mymysql::sql_open_str(const char *SQL, QStringList &list)
{
    int state = mysql_query(connection, SQL);//执行SQL语句
    if (state != 0)
    {
        memset(errorbuf, 0, sizeof(errorbuf));
        strcpy(errorbuf, mysql_error(&mysql));
        return -1;//执行失败，返回-1
    }

    MYSQL_RES *result = mysql_store_result(connection);//得到查询结果
    if (result == (MYSQL_RES *) NULL)
    {
        memset(errorbuf, 0, sizeof(errorbuf));
        strcpy(errorbuf, mysql_error(&mysql));
        return -1;//执行失败，返回-1
    } else
    {
        MYSQL_ROW sqlRow;
        sqlRow = mysql_fetch_row(result);
        if (sqlRow == NULL)
            return -1;
        int icount = mysql_field_count(connection);
        int i;
        for (i = 0; i < icount; i++)//循环得到一行中的每个字段
        {
            if (sqlRow[i] == NULL)//如果值为NULL，向model中插入字符串"NULL"
            {
                list.append("NULL");//将行中的每一列的值放入list中
            }else
            {
                list.append((const char *)sqlRow[i]);//将行中的每一列的值放入list中
            }
        }
        //printf("query is ok, %u rows affected\n", (unsigned int)mysql_affected_rows(connection));
        mysql_free_result(result);
    }
    return 0;
}



//执行没有返回结果的SQL语句
int mymysql::sql_exec(const char *SQL)//执行没有返回数据集的SQL语句
{
    int state = mysql_query(connection, SQL);//执行SQL语句
    if (state != 0)
    {
        memset(errorbuf, 0, sizeof(errorbuf));
        strcpy(errorbuf, mysql_error(connection));
        return -1;
    }
    //printf("query is ok, %u rows affected\n", (unsigned int)mysql_affected_rows(connection));
    return 0;
}

const char *mymysql::get_error()
{
    return errorbuf;
}

