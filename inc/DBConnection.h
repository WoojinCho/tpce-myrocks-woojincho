// DBConnection.h
//   2008 Yasufumi Kinoshita

#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

namespace TPCE
{

enum eCESUTStmt
{
    CESUT_STMT_ISO_L1 = 0,
    CESUT_STMT_ISO_L2,
    CESUT_STMT_ISO_L3,
    CESUT_STMT_CPF1_1,
    CESUT_STMT_CPF1_2,
    CESUT_STMT_CPF1_3,
    CESUT_STMT_CPF2_1,
    CESUT_STMT_MWF1_1a,
    CESUT_STMT_MWF1_1b,
    CESUT_STMT_MWF1_1c,
    CESUT_STMT_SDF1_1,
    CESUT_STMT_SDF1_2,
    CESUT_STMT_SDF1_3,
    CESUT_STMT_SDF1_4,
    CESUT_STMT_SDF1_5,
    CESUT_STMT_SDF1_6,
    CESUT_STMT_SDF1_7,
    CESUT_STMT_TLF1_1,
    CESUT_STMT_TLF1_2,
    CESUT_STMT_TLF1_3,
    CESUT_STMT_TLF1_4,
    CESUT_STMT_TLF2_1,
    CESUT_STMT_TLF2_2,
    CESUT_STMT_TLF2_3,
    CESUT_STMT_TLF2_4,
    CESUT_STMT_TLF3_1,
    CESUT_STMT_TLF3_2,
    CESUT_STMT_TLF3_3,
    CESUT_STMT_TLF3_4,
    CESUT_STMT_TLF4_1,
    CESUT_STMT_TLF4_2,
    CESUT_STMT_TOF1_1,
    CESUT_STMT_TOF1_2,
    CESUT_STMT_TOF1_3,
    CESUT_STMT_TOF2_1,
    CESUT_STMT_TOF3_1a,
    CESUT_STMT_TOF3_2a,
    CESUT_STMT_TOF3_1b,
    CESUT_STMT_TOF3_2b,
    CESUT_STMT_TOF3_3,
    CESUT_STMT_TOF3_4,
    CESUT_STMT_TOF3_5,
    CESUT_STMT_TOF3_6a,
    CESUT_STMT_TOF3_6b,
    CESUT_STMT_TOF3_7,
    CESUT_STMT_TOF3_8,
    CESUT_STMT_TOF3_9,
    CESUT_STMT_TOF3_10,
    CESUT_STMT_TOF3_11,
    CESUT_STMT_TOF4_1,
    CESUT_STMT_TOF4_2,
    CESUT_STMT_TOF4_3,
    CESUT_STMT_TSF1_1,
    CESUT_STMT_TSF1_2,
    CESUT_STMT_TUF1_1,
    CESUT_STMT_TUF1_2,
    CESUT_STMT_TUF1_3,
    CESUT_STMT_TUF1_4,
    CESUT_STMT_TUF1_5,
    CESUT_STMT_TUF1_6,
    CESUT_STMT_TUF2_1,
    CESUT_STMT_TUF2_2,
    CESUT_STMT_TUF2_3,
    CESUT_STMT_TUF2_4,
    CESUT_STMT_TUF2_5,
    CESUT_STMT_TUF2_6,
    CESUT_STMT_TUF3_1,
    CESUT_STMT_TUF3_2,
    CESUT_STMT_TUF3_3,
    CESUT_STMT_TUF3_4,
    CESUT_STMT_TUF3_5,
    CESUT_STMT_TUF3_6,
    CESUT_STMT_MAX
};

enum eMEESUTStmt
{
    MEESUT_STMT_ISO_L1 = 0,
    MEESUT_STMT_ISO_L2,
    MEESUT_STMT_ISO_L3,
    MEESUT_STMT_TRF1_1,
    MEESUT_STMT_TRF1_2,
    MEESUT_STMT_TRF1_3,
    MEESUT_STMT_TRF2_1,
    MEESUT_STMT_TRF2_2a,
    MEESUT_STMT_TRF2_2b,
    MEESUT_STMT_TRF2_3a,
    MEESUT_STMT_TRF2_3b,
    MEESUT_STMT_TRF2_4,
    MEESUT_STMT_TRF2_5a,
    MEESUT_STMT_TRF2_5b,
    MEESUT_STMT_TRF2_6,
    MEESUT_STMT_TRF2_7a,
    MEESUT_STMT_TRF2_7b,
    MEESUT_STMT_TRF3_1,
    MEESUT_STMT_TRF3_2,
    MEESUT_STMT_TRF4_1,
    MEESUT_STMT_TRF4_2,
    MEESUT_STMT_TRF4_3,
    MEESUT_STMT_TRF5_1,
    MEESUT_STMT_TRF5_2,
    MEESUT_STMT_TRF5_3,
    MEESUT_STMT_TRF6_1,
    MEESUT_STMT_TRF6_2,
    MEESUT_STMT_TRF6_3,
    MEESUT_STMT_TRF6_4,
    MEESUT_STMT_MFF1_1,
    MEESUT_STMT_MFF1_2,
    MEESUT_STMT_MFF1_3,
    MEESUT_STMT_MFF1_4,
    MEESUT_STMT_MFF1_5,
    MEESUT_STMT_MAX
};

enum eDMSUTStmt
{
    DMSUT_STMT_ISO_L1 = 0,
    DMSUT_STMT_ISO_L2,
    DMSUT_STMT_ISO_L3,
    DMSUT_STMT_TCF1_2,
    DMSUT_STMT_TCF1_5,
    DMSUT_STMT_MAX
};

class CDBConnection
{
public:
    SQLHENV                 m_Env;
    SQLHDBC                 m_Conn;
    SQLHSTMT                m_Stmt;
    SQLHSTMT                m_Stmt2;

    int                     m_PrepareType;
    SQLHSTMT                *m_pPrepared;

    CDBConnection(const char *szHost, const char *szDBName,
		  const char *szDBUser, const char *szDBPass, int szPrepareType);
    ~CDBConnection();

    void BeginTxn();
    void CommitTxn();
    void RollbackTxn();
    void ThrowError( CODBCERR::ACTION eAction, SQLSMALLINT HandleType, SQLHANDLE Handle,
		     const char* FileName = NULL, unsigned int Line = 0);
    void ThrowError( CODBCERR::ACTION eAction,
		     const char* FileName = NULL, unsigned int Line = 0)
	{
	    ThrowError(eAction, 0, SQL_NULL_HANDLE, FileName, Line);
	};
};

}   // namespace TPCE

#endif //DB_CONNECTION_H
