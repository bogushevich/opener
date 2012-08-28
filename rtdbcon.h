#if !defined(__rtdbcon_h)
//asdfasdfasd
#define __rtdbcon_h

#include <windows.h>
#include "oiknt.h"
#include "oiktype.h"
#include "rtdbmsg.h"
#include "Event_str.h"

struct Data_Size
{
	void* ptr ;
	uint32 size ;
} ;

struct AsyncQuery
{
	uint32 type ;
	char oicat ;
	uint32 TStart ;
	uint32 TStop ;
	uint32 step ;
	uint32 number ;
	uint32 mask ;
	uint16 mask_send ;
	uint16 mask_on ;
	uint32 query_size ;
	void* query_buf ;
	HANDLE handle ;
	BOOL is_thread ;
	uint32 msg ;
	uint32 answer_size ;
	void* answer_buf ;
} ;

struct AsyncQuery_V7
{
	uint32 type ;
	char oicat ;
	uint64 TStart ;
	uint64 TStop ;
	uint32 step ;
	uint32 number ;
	uint32 mask ;
	uint16 mask_send ;
	uint16 mask_on ;
	uint32 query_size ;
	void* query_buf ;
	HANDLE handle ;
	BOOL is_thread ;
	uint32 msg ;
} ;

struct SyncQuery
{
	uint32 type ;
	char oicat ;
	BOOL no_answer ;
	uint32 TStart ;
	uint32 TStop ;
	uint32 step ;
	uint32 number ;
	uint32 mask ;
	uint16 mask_send ;
	uint16 mask_on ;
	uint32 query_size ;
	void* query_buf ;
} ;

struct SyncQuery_V7
{
	uint32 type ;
	char oicat ;
	BOOL no_answer ;
	uint64 TStart ;
	uint64 TStop ;
	uint32 step ;
	uint32 number ;
	uint32 mask ;
	uint16 mask_send ;
	uint16 mask_on ;
	uint32 query_size ;
	void* query_buf ;
} ;

struct OIKInf
{
	char Comment[25] ;
	char Abr_OIK[5] ;
	char rbd_name[10] ;
} ;

struct DomainGroupInf
{
	char m_sz_Domain[33] ;
	char m_sz_GrpName[33] ;
	char m_sz_Comment[65] ;
} ;

struct SQLInf
{
	uint32 m_ui32_Id ;
	char m_sz_Description[50] ;
	char m_sz_Host[20] ;
	char m_sz_RealName[32] ;
	uint16 m_ui16_State ;
} ;

#define	LIST_SUCCESS		0
#define	LIST_ERR_CONNECT	1
#define	LIST_ERR_SIZE		2
#define	LIST_SMALL_SIZE	3
#define	LIST_ERR_COPY		4

extern "C" {
void WINAPI OIKSetHost( LPSTR host ) ;
BOOL WINAPI OIKSetHostEx( uint16 id, LPSTR host ) ;
void WINAPI OIKSetPort( uint32 port ) ;
BOOL WINAPI OIKSetPortEx( uint16 id, uint32 port ) ;
void WINAPI OIKSetPassword( LPSTR pswd ) ;
BOOL WINAPI OIKSetPasswordEx( uint16 id, LPSTR pswd ) ;
uint32 WINAPI SetOIK( LPSTR abr ) ;
uint32 WINAPI SetOIKEx( uint16 id, LPSTR abr ) ;
uint32 WINAPI SetDefOIK() ;
uint32 WINAPI SetDefOIKEx( uint16 id ) ;
uint32 WINAPI SetDefOIKForDomainGroup( LPSTR dmn_grp) ;
uint32 WINAPI SetDefOIKForDomainGroupEx( uint16 id, LPSTR dmn_grp) ;
void WINAPI SetFromIni() ;
BOOL WINAPI SetFromIniEx( uint16 id ) ;
LPCSTR WINAPI GetDefOIKAbr() ;
LPCSTR WINAPI GetDefOIKAbrEx( uint16 id ) ;
LPCSTR WINAPI GetDomain() ;
LPCSTR WINAPI GetDomainEx( uint16 id ) ;
LPCSTR WINAPI GetGroup() ;
LPCSTR WINAPI GetGroupEx( uint16 id ) ;
LPCSTR WINAPI GetRTDBAbr() ;
LPCSTR WINAPI GetRTDBAbrEx( uint16 id ) ;
BOOL WINAPI SelectOIK() ;
BOOL WINAPI SelectOIKEx( uint16 ) ;
uint32 WINAPI GetOIKList( OIKInf* lst, uint32* size ) ;
uint32 WINAPI GetOIKListEx( uint16 id, OIKInf* lst, uint32* size ) ;
uint32 WINAPI GetDomainGroupList( DomainGroupInf* lst, uint32* size ) ;
uint32 WINAPI GetDomainGroupListEx( uint16 id, DomainGroupInf* lst, uint32* size ) ;
void WINAPI SetDomainGroup( LPSTR Domain, LPSTR Group ) ;
BOOL WINAPI SetDomainGroup2( LPSTR Domain, LPSTR Group ) ;
BOOL WINAPI SetDomainGroup2Ex( uint16 id, LPSTR Domain, LPSTR Group ) ;
uint32 WINAPI GetSQLList( SQLInf* lst, uint32* size ) ;
uint32 WINAPI GetSQLListEx( uint16 id, SQLInf* lst, uint32* size ) ;
LPCSTR WINAPI GetOIKBD() ;
LPCSTR WINAPI GetOIKBDEx( uint16 id ) ;
LPCSTR WINAPI GetOIKKrnl() ;
LPCSTR WINAPI GetOIKKrnlEx( uint16 id ) ;
uint32 WINAPI GetRTDBPort() ;
uint32 WINAPI GetRTDBPortEx( uint16 id ) ;
LPCSTR WINAPI GetRTDBHost() ;
LPCSTR WINAPI GetRTDBHostEx( uint16 id ) ;
LPCSTR WINAPI GetDefNSQL() ;
LPCSTR WINAPI GetDefNSQLEx( uint16 id ) ;
LPCSTR WINAPI GetMainGroupForDomain( LPSTR domain ) ;
LPCSTR WINAPI GetMainGroupForDomainEx( uint16 id, LPSTR domain ) ;
BOOL WINAPI UpdateInfo() ;
BOOL WINAPI UpdateInfoEx( uint16 id ) ;
BOOL WINAPI RTDBOpen( LPSTR code_str ) ;
BOOL WINAPI RTDBOpenEx( uint16 id, LPSTR code_str ) ;
void WINAPI RTDBClose() ;
void WINAPI RTDBCloseEx( uint16 id ) ;
BOOL WINAPI RTDBIsConnected() ;
BOOL WINAPI RTDBIsConnectedEx( uint16 id ) ;

uint32 WINAPI RTDBGetNCon() ;
uint32 WINAPI RTDBGetNConEx( uint16 id ) ;
void WINAPI RTDBEvent( Event_hd* ptr, double* ParVal, LPSTR str ) ;
void WINAPI RTDBEventEx( uint16 id, Event_hd* ptr, double* ParVal, LPSTR str ) ;
uint32 WINAPI RTDBQueryAsync( AsyncQuery* query ) ;
uint32 WINAPI RTDBQueryAsyncEx( uint16 id, AsyncQuery* query ) ;
uint32 WINAPI RTDBQueryAsyncV2( AsyncQuery* query ) ;
uint32 WINAPI RTDBQueryAsyncV2Ex( uint16 id, AsyncQuery* query ) ;
uint32 WINAPI RTDBQueryAsyncV7( AsyncQuery_V7* query ) ;
uint32 WINAPI RTDBQueryAsyncV7Ex( uint16 id, AsyncQuery_V7* query ) ;
void WINAPI RTDBMsg( HANDLE hndl, BOOL Thread ) ;
void WINAPI RTDBMsgEx( uint16 id, HANDLE hndl, BOOL Thread ) ;
void WINAPI RTDBMsg2( HANDLE hndl, BOOL Thread, uint32 msg ) ;
void WINAPI RTDBMsg2Ex( uint16 id, HANDLE hndl, BOOL Thread, uint32 msg ) ;
LPVOID WINAPI RTDBQuery( SyncQuery* query ) ;
LPVOID WINAPI RTDBQueryEx( uint16 id, SyncQuery* query ) ;
LPVOID WINAPI RTDBQueryV7( SyncQuery_V7* query ) ;
LPVOID WINAPI RTDBQueryV7Ex( uint16 id, SyncQuery_V7* query ) ;
void WINAPI RTDBDeleteData( LPVOID data ) ;
void WINAPI RTDBDeleteDataEx( uint16 id, LPVOID data ) ;
uint32 WINAPI RTDBSyncQueryResult( LPVOID data ) ;
uint32 WINAPI RTDBSyncQueryResultEx( uint16 id, LPVOID data ) ;

uint32 WINAPI OpenSyncQueryChannel() ;
void WINAPI CloseSyncQueryChannel( uint32 chan ) ;
uint32 WINAPI OpenSyncQueryChannelEx( uint16 id ) ;
void WINAPI CloseSyncQueryChannelEx( uint16 id, uint32 chan ) ;
LPVOID WINAPI RTDBQueryChannel( uint32 chan, SyncQuery* query ) ;
LPVOID WINAPI RTDBQueryChannelEx( uint16 id, uint32 chan, SyncQuery* query ) ;
LPVOID WINAPI RTDBQueryChannelV7( uint32 chan, SyncQuery_V7* query ) ;
LPVOID WINAPI RTDBQueryChannelV7Ex( uint16 id, uint32 chan, SyncQuery_V7* query ) ;
BOOL WINAPI IsOpenSyncQueryChannel( uint32 chan ) ;
BOOL WINAPI IsOpenSyncQueryChannelEx( uint16 id, uint32 chan ) ;

BOOL WINAPI RTDBSendAsync( uint32 hQuery, uint32 size, LPVOID data ) ;
BOOL WINAPI RTDBAsyncIsConnect( uint32 hQuery ) ;
void WINAPI RTDBQueryData( uint32 hQuery ) ;
uint32 WINAPI RTDBQueryDataV2( uint32 hQuery, void* ptr, uint32 size ) ;
uint32 WINAPI RTDBQueryDataV7( uint32 hQuery, void* ptr, uint32 size ) ;
void WINAPI RTDBQueryEnd( uint32 hQuery ) ;
void WINAPI RTDBQueryChangeBuffer( uint32 hQuery, LPVOID answer_buf, uint32 answer_size ) ;

void WINAPI FileTimeToUnix( FILETIME* pFT, uint32* pInt ) ;
void WINAPI FileTimeToUnixL( FILETIME* pFT, uint64* pInt ) ;
void WINAPI UnixToFileTime( uint32* pInt, FILETIME* pFT ) ;
void WINAPI UnixLToFileTime( uint64* pInt, FILETIME* pFT ) ;
void WINAPI SystemTimeToUnix( SYSTEMTIME* pST, uint32 *pInt ) ;
void WINAPI SystemTimeToUnixL( SYSTEMTIME* pST, uint64 *pInt ) ;
void WINAPI LocalTimeToUnix( SYSTEMTIME* pST, uint32 *pInt ) ;
void WINAPI LocalTimeToUnixEx( SYSTEMTIME* pST, uint32 *pInt, BOOL IsSummer ) ;
void WINAPI LocalTimeToUnixL( SYSTEMTIME* pST, uint64 *pInt ) ;
void WINAPI LocalTimeToUnixLEx( SYSTEMTIME* pST, uint64 *pInt, BOOL IsSummer ) ;
void WINAPI UnixToSystemTime( uint32* pInt, SYSTEMTIME* pST ) ;
void WINAPI UnixLToSystemTime( uint64* pInt, SYSTEMTIME* pST ) ;
void WINAPI UnixToLocalTime( uint32* pInt, SYSTEMTIME* pST ) ;
void WINAPI UnixToLocalTimeEx( uint32* pInt, SYSTEMTIME* pST, uint32* IsSummer ) ;
void WINAPI UnixLToLocalTime( uint64* pInt, SYSTEMTIME* pST ) ;
void WINAPI UnixLToLocalTimeEx( uint64* pInt, SYSTEMTIME* pST, uint32* IsSummer ) ;
uint32 WINAPI CurrentUnixTime() ;
uint64 WINAPI CurrentUnixLTime() ;
uint32 WINAPI SystemTimeToUnixTime( SYSTEMTIME* pST ) ;
uint64 WINAPI SystemTimeToUnixLTime( SYSTEMTIME* pST ) ;
uint32 WINAPI LocalTimeToUnixTime( SYSTEMTIME* pST ) ;
uint64 WINAPI LocalTimeToUnixLTime( SYSTEMTIME* pST ) ;
uint32 WINAPI SummerAge( int year, uint32* start, uint32* end ) ;
void DllExport WINAPI InitSummerTable() ;
 
BOOL WINAPI ReturnData( LPSTR param, uint32 size, void* ptr ) ;

uint32 WINAPI MergeOIId( char oi, uint32 id ) ;
uint32 WINAPI SplitOIId( uint32 oiid, char *oi ) ;

uint32 WINAPI IsSetOIKOption( LPSTR opt ) ;
uint32 WINAPI IsSetOIKOptionEx( uint16 id, LPSTR opt ) ;

uint16 WINAPI CreateNewRTDBConnection() ;
void WINAPI DestroyRTDBConnection( uint16 id ) ;
}

#endif

