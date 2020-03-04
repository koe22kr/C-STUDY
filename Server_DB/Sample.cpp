#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <tchar.h>
SQLHENV g_hEnv;     //
SQLHDBC g_hDbc;
SQLHSTMT g_hStmt;

bool Init()
{
    //�ʱ�ȭ   ȯ�� ������ ���ᰡ�� ,�ؾ� ��� �ڵ� ����
       //ȯ�� �ڵ� - >�Ҵ� - >���� ���� �ʱ�ȭ�� ����.
       if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &g_hEnv) != SQL_SUCCESS)
           return false;
       if (SQLSetEnvAttr(g_hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)// ����
           return false;


       //���� �ڵ� - >�Ҵ� - >����
       if (SQLAllocHandle(SQL_HANDLE_DBC, g_hEnv, &g_hDbc) != SQL_SUCCESS) //����
           return false;
       TCHAR Dir[256] = { 0 };
       GetCurrentDirectory(MAX_PATH, Dir); //���� ���丮 �� ��ȯ �Ѵ�.
       TCHAR InCon[256] = { 0 };
       std::cin >> _T("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=%s\\cigarette.accdb"),Dir >> InCon ;  //��� �ٲ��� Ȯ���� ����.   Col  �ݷ� [���� ã�ƺ���.]
       SQLSMALLINT cbOutLen;
       SQLDriverConnect(g_hDbc,NULL,InCon,_countof(InCon),NULL,0,&cbOutLen,SQL_DRIVER_NOPROMPT);//����
       
       
       //��� �ڵ� - >�Ҵ� - >����
       if (SQLAllocHandle(SQL_HANDLE_STMT, g_hDbc, &g_hStmt) != SQL_SUCCESS)
           return false;


}
bool Relsease()
{
    SQLFreeHandle(SQL_HANDLE_STMT, g_hStmt);
    SQLFreeHandle(SQL_HANDLE_DBC, g_hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, g_hEnv);
    return true;
}



void main()
{
   
    







}