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
    //초기화   환경 만들어야 연결가능 ,해야 명령 핸들 가능
       //환경 핸들 - >할당 - >해제 윈속 초기화랑 같다.
       if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &g_hEnv) != SQL_SUCCESS)
           return false;
       if (SQLSetEnvAttr(g_hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)// 연결
           return false;


       //연결 핸들 - >할당 - >해제
       if (SQLAllocHandle(SQL_HANDLE_DBC, g_hEnv, &g_hDbc) != SQL_SUCCESS) //접속
           return false;
       TCHAR Dir[256] = { 0 };
       GetCurrentDirectory(MAX_PATH, Dir); //현재 디렉토리 를 반환 한다.
       TCHAR InCon[256] = { 0 };
       std::cin >> _T("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=%s\\cigarette.accdb"),Dir >> InCon ;  //어떻게 바꿀지 확인해 보자.   Col  콜럼 [뭔지 찾아보자.]
       SQLSMALLINT cbOutLen;
       SQLDriverConnect(g_hDbc,NULL,InCon,_countof(InCon),NULL,0,&cbOutLen,SQL_DRIVER_NOPROMPT);//연결
       
       
       //명령 핸들 - >할당 - >해제
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