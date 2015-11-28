//--------------------------------------------------------------------
#include "../FKLogger/FKLogger.h"
#include <stdio.h>
#include <string>
using std::string;
//--------------------------------------------------------------------
#if defined (DEBUG) || defined (_DEBUG)
#pragma comment( lib, "FKLoggerD.lib")
#pragma comment( lib, "Ws2_32.lib")
#else
#pragma comment( lib, "FKLogger.lib")
#pragma comment( lib, "Ws2_32.lib")
#endif
//--------------------------------------------------------------------
int main()
{
    // Ĭ��Console���
    LogError( "�������n�ǿ϶����֔߀��");
    LogDebug( "����LogDebug����LogDebug����LogDebug����LogDebug����LogDebug" );
    LogTrace( "12dsdsads" );
    string szTest = "dsadasd���";
    LogInfo( "%s", szTest.c_str() );

    // ��ʼ�ļ����
    FKLogger::SFileLoggerInitParams tagParams;
    tagParams.m_pFileName = "MyLog.txt";
    if( InitFKLogger( FKLogger::ELOM_File, (void*)&tagParams ) < 0 )
    {
        return -1;
    }
    LogError( "�����ɿ�ش�");
    LogDebug( "߀�������e837�����������ƻ�*������&*&����  �����Ͼ���\n" );
    LogTrace( "12dsdsads" );
    szTest = "�����vjsd";
    LogInfo( "%s", szTest.c_str() );

    DeInitFKLogger();

    // Զ��Sock����
    FKLogger::SSocketLoggerInitParams tagSockParams;
    tagSockParams.m_pServer = "127.0.0.1";
    tagSockParams.m_nPort = 9999;
    if( InitFKLogger( FKLogger::ELOM_Socket, (void*)&tagSockParams ) < 0 )
    {
        return -2;
    }
    LogError( "�����ɿ�ش�");
    LogDebug( "߀�������e837�����������ƻ�*������&*&����  �����Ͼ���\n" );
    LogTrace( "12dsdsads" );
    szTest = "�����vjsd";
    LogInfo( "%s", szTest.c_str() );

    DeInitFKLogger();

    getchar();
    return 0;
}
//--------------------------------------------------------------------