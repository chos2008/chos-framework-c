# Microsoft Developer Studio Project File - Name="HIB_SERVER" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=HIB_SERVER - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HIB_SERVER.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HIB_SERVER.mak" CFG="HIB_SERVER - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HIB_SERVER - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "HIB_SERVER - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libmysql.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib pthreadVC2.lib liblog.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "HIB_SERVER - Win32 Release"
# Name "HIB_SERVER - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "xmpp No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\xmpp\EndpointListener.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\Stanzas.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\Stream.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPConnection.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPEndpoint.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPHandler.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPIMAccount.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPMessage.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPMessageHandler.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPStream.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# End Group
# Begin Group "http"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\http\Entity.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\EntityHeader.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\GenericHttpHeader.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpConnection.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpHandler.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpHeader.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpInputStream.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpMessage.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\http\HttpRequest.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpResponse.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\Message.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\RequestHeader.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\ResponseHeader.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\StatusLine.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\TextMessage.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# End Group
# Begin Group "sip"

# PROP Default_Filter "sip"
# Begin Source File

SOURCE=.\sip\LocationService.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\LocationServiceEndpoint.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\Registrar.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\RegistrarEndpoint.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipConnection.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SIPEndpoint.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipMessage.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipRequest.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipResponse.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\URI.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# End Group
# Begin Group "echo"

# PROP Default_Filter ""
# End Group
# Begin Group "ptp"

# PROP Default_Filter ""
# End Group
# Begin Group "collection"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\collection\ArrayList.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\Element.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\HashMap.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\HashSet.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\Hashtable.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\LinkedElement.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\LinkedList.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\List.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\Map.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\Object.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\Set.cpp
# End Source File
# Begin Source File

SOURCE=.\collection\Vector.cpp
# End Source File
# End Group
# Begin Group "sock No. 1"

# PROP Default_Filter ""
# End Group
# Begin Group "net"

# PROP Default_Filter ""
# Begin Group "socket"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\net\socket\HardSocket.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\InetAddress.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\LightSocket.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\PlainSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\Socket.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketConnection.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketConnectionEventHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketEventHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketException.cpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketInputStream.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketOutputStream.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketProvider.cpp
# End Source File
# End Group
# Begin Group "usb No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\net\usb\UsbDeviceList.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\net\AsyncSelectSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\net\DataBufferQueue.cpp
# End Source File
# Begin Source File

SOURCE=.\net\Select.cpp
# End Source File
# Begin Source File

SOURCE=.\net\SelectEventHandler.cpp
# End Source File
# End Group
# Begin Group "test"

# PROP Default_Filter ""
# Begin Group "sip No. 2"

# PROP Default_Filter ""
# End Group
# Begin Group "http No. 2"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\test\hello.c

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/test"

!ENDIF 

# End Source File
# End Group
# Begin Group "gs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gs\AbstractExecutor.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Account.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Actor.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Attacker.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Barrier.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\BarrierWithXObject.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Battle.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\BinaryRequest.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\BinaryResponse.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Boss.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Callable.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\CAttacker.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\cbarrier.c

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\CDefender.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Clan.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Defender.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Equipment.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Executor.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\fb_level.c

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\GenericStatementCallable.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\GRequestListener.cpp
# End Source File
# Begin Source File

SOURCE=.\gs\Hero.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Instance.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\InstanceBarrier.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\InstanceWithXObject.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Legion.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\LoadBalance.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\MobileNpc.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\NameValue.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\NonBlockRegistorServer.cpp
# End Source File
# Begin Source File

SOURCE=.\gs\Npc.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\OriginServer.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\PreparedStatementCallable.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Prop.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\RegistorServer.cpp
# End Source File
# Begin Source File

SOURCE=.\gs\Request.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\RequestDataBuffer.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\RequestProcessor.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Response.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Role.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Script.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\ServerEndpoint.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Session.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Skill.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\SocketConnectionHandler.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\SocketStreamHandler.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Team.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\UserData.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Value.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Warmer.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\World.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\WorldBarrier.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\XMap.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\XObject.cpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\zoom.c

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\ZoomServerSelectEventHandler.cpp
# End Source File
# End Group
# Begin Group "xml"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\xml\Attribute.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\ChildTag.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\ComplexTag.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\EndTag.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\LPTagAttribute.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\SimpleTag.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\StartLine.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\StartTag.cpp
# End Source File
# Begin Source File

SOURCE=.\xml\Tag.cpp
# End Source File
# End Group
# Begin Group "linux"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\AbstractBarrier.cpp
# End Source File
# Begin Source File

SOURCE=.\AbstractLinkedBarrier.cpp
# End Source File
# Begin Source File

SOURCE=.\AbstractModule.cpp
# End Source File
# Begin Source File

SOURCE=.\CModule.c
# End Source File
# Begin Source File

SOURCE=.\ConfigurationManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Connection.cpp
# End Source File
# Begin Source File

SOURCE=.\csocket.c
# End Source File
# Begin Source File

SOURCE=.\cthread.c
# End Source File
# Begin Source File

SOURCE=.\DataLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\Delete.cpp
# End Source File
# Begin Source File

SOURCE=.\Endpoint.cpp
# End Source File
# Begin Source File

SOURCE=.\ernie.c
# End Source File
# Begin Source File

SOURCE=.\EventLock.cpp
# End Source File
# Begin Source File

SOURCE=.\GameServer.cpp
# End Source File
# Begin Source File

SOURCE=.\HttpServer.cpp
# End Source File
# Begin Source File

SOURCE=.\ini.cpp
# End Source File
# Begin Source File

SOURCE=.\Insert.cpp
# End Source File
# Begin Source File

SOURCE=.\Interactive.cpp
# End Source File
# Begin Source File

SOURCE=.\Job.cpp
# End Source File
# Begin Source File

SOURCE=.\LinkedBarrier.cpp
# End Source File
# Begin Source File

SOURCE=.\MethodModule.cpp
# End Source File
# Begin Source File

SOURCE=.\Module.cpp
# End Source File
# Begin Source File

SOURCE=.\ModuleEcho.cpp
# End Source File
# Begin Source File

SOURCE=.\ModuleGameServer.cpp
# End Source File
# Begin Source File

SOURCE=.\ModuleHTTP.cpp
# End Source File
# Begin Source File

SOURCE=.\ModuleSIP.cpp
# End Source File
# Begin Source File

SOURCE=.\ModuleTime.cpp
# End Source File
# Begin Source File

SOURCE=.\ModuleXMPP.cpp
# End Source File
# Begin Source File

SOURCE=.\Mssql.cpp
# End Source File
# Begin Source File

SOURCE=.\MssqlConnection.cpp
# End Source File
# Begin Source File

SOURCE=.\MutexLock.cpp
# End Source File
# Begin Source File

SOURCE=.\Mysql.cpp
# End Source File
# Begin Source File

SOURCE=.\MysqlConnection.cpp
# End Source File
# Begin Source File

SOURCE=.\MysqlResultSet.cpp
# End Source File
# Begin Source File

SOURCE=.\MysqlStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\Nat.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectModule.cpp
# End Source File
# Begin Source File

SOURCE=.\Operation.cpp
# End Source File
# Begin Source File

SOURCE=.\Oracle.cpp
# End Source File
# Begin Source File

SOURCE=.\OracleConnection.cpp
# End Source File
# Begin Source File

SOURCE=.\Posix.cpp
# End Source File
# Begin Source File

SOURCE=.\PreparedStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\pthread.c
# End Source File
# Begin Source File

SOURCE=.\PThreadModule.cpp
# End Source File
# Begin Source File

SOURCE=.\Query.cpp
# End Source File
# Begin Source File

SOURCE=.\RequestDataBufferQueueListener.cpp
# End Source File
# Begin Source File

SOURCE=.\ResourceLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\RunMode.cpp
# End Source File
# Begin Source File

SOURCE=.\Server.cpp
# End Source File
# Begin Source File

SOURCE=.\SIPServer.cpp
# End Source File
# Begin Source File

SOURCE=.\SQLException.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=.\Sybase.cpp
# End Source File
# Begin Source File

SOURCE=.\SybaseConnection.cpp
# End Source File
# Begin Source File

SOURCE=.\Sync.cpp
# End Source File
# Begin Source File

SOURCE=.\Thread.cpp
# End Source File
# Begin Source File

SOURCE=.\Update.cpp
# End Source File
# Begin Source File

SOURCE=.\WinAPIThreadModule.cpp
# End Source File
# Begin Source File

SOURCE=.\XMPPServer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "xmpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\xmpp\EndpointListener.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\Stanzas.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\Stream.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPConnection.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPEndpoint.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPHandler.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPIMAccount.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPMessage.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPMessageHandler.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xmpp\XMPPStream.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/xmpp"

!ENDIF 

# End Source File
# End Group
# Begin Group "http No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\http\CPPHttpMessage.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\Entity.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\EntityHeader.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\GenericHttpHeader.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpConnection.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpHandler.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpHeader.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpInputStream.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\httpmessage.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpProxy.hpp
# End Source File
# Begin Source File

SOURCE=.\http\HttpRequest.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\HttpResponse.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\Message.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\RequestHeader.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\ResponseHeader.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\StatusLine.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\http\TextMessage.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/http"

!ENDIF 

# End Source File
# End Group
# Begin Group "sip No. 1"

# PROP Default_Filter "sip"
# Begin Source File

SOURCE=.\sip\AbstractElement.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\LocationDataAccessObject.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\LocationDataSource.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\LocationMysqlAccessObject.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\LocationService.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\LocationServiceEndpoint.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\NetworkElement.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\Registrar.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\RegistrarEndpoint.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipConnection.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SIPEndpoint.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipMessage.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipRequest.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\SipResponse.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\sip\URI.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/sip"

!ENDIF 

# End Source File
# End Group
# Begin Group "echo No. 1"

# PROP Default_Filter ""
# End Group
# Begin Group "collection No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\collection\ArrayList.h
# End Source File
# Begin Source File

SOURCE=.\collection\Element.h
# End Source File
# Begin Source File

SOURCE=.\collection\HashMap.h
# End Source File
# Begin Source File

SOURCE=.\collection\HashSet.h
# End Source File
# Begin Source File

SOURCE=.\collection\Hashtable.h
# End Source File
# Begin Source File

SOURCE=.\collection\LinkedElement.h
# End Source File
# Begin Source File

SOURCE=.\collection\LinkedList.h
# End Source File
# Begin Source File

SOURCE=.\collection\List.h
# End Source File
# Begin Source File

SOURCE=.\collection\Map.h
# End Source File
# Begin Source File

SOURCE=.\collection\Object.h
# End Source File
# Begin Source File

SOURCE=.\collection\Set.h
# End Source File
# Begin Source File

SOURCE=.\collection\Vector.h
# End Source File
# End Group
# Begin Group "sock"

# PROP Default_Filter ""
# End Group
# Begin Group "sctp"

# PROP Default_Filter ""
# End Group
# Begin Group "net No. 1"

# PROP Default_Filter ""
# Begin Group "socket No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\net\socket\HardSocket.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\InetAddress.hpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\LightSocket.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\PlainSocket.h
# End Source File
# Begin Source File

SOURCE=.\net\socket\Socket.h
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketConnection.h
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketConnectionEventHandler.hpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketEventHandler.hpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketException.hpp
# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketInputStream.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketOutputStream.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/net/socket"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\net\socket\SocketProvider.h
# End Source File
# End Group
# Begin Group "usb"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\net\usb\UsbDeviceList.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\net\AsyncSelectSocket.hpp
# End Source File
# Begin Source File

SOURCE=.\net\DataBufferQueue.h
# End Source File
# Begin Source File

SOURCE=.\net\Select.hpp
# End Source File
# Begin Source File

SOURCE=.\net\SelectEventHandler.hpp
# End Source File
# Begin Source File

SOURCE=.\net\sp.h
# End Source File
# End Group
# Begin Group "gs No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gs\AbstractExecutor.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Account.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Actor.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Attacker.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Barrier.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\BarrierWithXObject.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Battle.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\BinaryRequest.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\BinaryResponse.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Boss.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Callable.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\CAttacker.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\cbarrier.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\CDefender.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Clan.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Defender.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Equipment.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Executor.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\GenericStatementCallable.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\GRequestListener.hpp
# End Source File
# Begin Source File

SOURCE=.\gs\Hero.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Instance.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\InstanceBarrier.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\InstanceWithXObject.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Legion.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\LoadBalance.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\MobileNpc.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\NameValue.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\NonBlockRegistorServer.hpp
# End Source File
# Begin Source File

SOURCE=.\gs\Npc.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\OriginServer.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\PreparedStatementCallable.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Prop.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\RegistorServer.hpp
# End Source File
# Begin Source File

SOURCE=.\gs\Request.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\RequestDataBuffer.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\RequestProcessor.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Response.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Role.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Script.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\ServerEndpoint.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Session.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Skill.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\SocketConnectionHandler.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\SocketStreamHandler.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Team.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\UserData.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Value.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\Warmer.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\World.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\WorldBarrier.hpp

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\XMap.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\XObject.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\zoom.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/gs"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gs\ZoomServerSelectEventHandler.hpp
# End Source File
# End Group
# Begin Group "test No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\test\hello.h

!IF  "$(CFG)" == "HIB_SERVER - Win32 Release"

!ELSEIF  "$(CFG)" == "HIB_SERVER - Win32 Debug"

# PROP Intermediate_Dir "Debug/test"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\test\TestEventLockMessageConsumer.hpp
# End Source File
# Begin Source File

SOURCE=.\test\TestEventLockMessageDestination.hpp
# End Source File
# Begin Source File

SOURCE=.\test\TestEventLockMessageProducer.hpp
# End Source File
# End Group
# Begin Group "xml No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\xml\Attribute.h
# End Source File
# Begin Source File

SOURCE=.\xml\ChildTag.h
# End Source File
# Begin Source File

SOURCE=.\xml\ComplexTag.h
# End Source File
# Begin Source File

SOURCE=.\xml\LPTagAttribute.h
# End Source File
# Begin Source File

SOURCE=.\xml\SimpleTag.h
# End Source File
# Begin Source File

SOURCE=.\xml\StartLine.h
# End Source File
# Begin Source File

SOURCE=.\xml\StartTag.h
# End Source File
# Begin Source File

SOURCE=.\xml\Tag.h
# End Source File
# End Group
# Begin Group "linux No. 1"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\AbstractBarrier.hpp
# End Source File
# Begin Source File

SOURCE=.\AbstractLinkedBarrier.hpp
# End Source File
# Begin Source File

SOURCE=.\AbstractModule.hpp
# End Source File
# Begin Source File

SOURCE=.\CModule.h
# End Source File
# Begin Source File

SOURCE=.\Connection.hpp
# End Source File
# Begin Source File

SOURCE=.\csocket.h
# End Source File
# Begin Source File

SOURCE=.\cthread.h
# End Source File
# Begin Source File

SOURCE=.\DefaultAlignTest.h
# End Source File
# Begin Source File

SOURCE=.\Delete.h
# End Source File
# Begin Source File

SOURCE=.\Endpoint.h
# End Source File
# Begin Source File

SOURCE=.\ernie.h
# End Source File
# Begin Source File

SOURCE=.\EventLock.hpp
# End Source File
# Begin Source File

SOURCE=.\GameServer.h
# End Source File
# Begin Source File

SOURCE=.\HttpServer.h
# End Source File
# Begin Source File

SOURCE=.\ini.h
# End Source File
# Begin Source File

SOURCE=.\Insert.h
# End Source File
# Begin Source File

SOURCE=.\Interactive.h
# End Source File
# Begin Source File

SOURCE=.\Job.h
# End Source File
# Begin Source File

SOURCE=.\json.h
# End Source File
# Begin Source File

SOURCE=.\LinkedBarrier.hpp
# End Source File
# Begin Source File

SOURCE=.\LinkedLibrary.h
# End Source File
# Begin Source File

SOURCE=.\Lock.hpp
# End Source File
# Begin Source File

SOURCE=.\MethodModule.hpp
# End Source File
# Begin Source File

SOURCE=.\micro.h
# End Source File
# Begin Source File

SOURCE=.\Module.hpp
# End Source File
# Begin Source File

SOURCE=.\ModuleEcho.h
# End Source File
# Begin Source File

SOURCE=.\ModuleGameServer.h
# End Source File
# Begin Source File

SOURCE=.\ModuleHTTP.h
# End Source File
# Begin Source File

SOURCE=.\ModuleSIP.h
# End Source File
# Begin Source File

SOURCE=.\ModuleTime.h
# End Source File
# Begin Source File

SOURCE=.\ModuleXMPP.h
# End Source File
# Begin Source File

SOURCE=.\Mssql.h
# End Source File
# Begin Source File

SOURCE=.\MssqlConnection.h
# End Source File
# Begin Source File

SOURCE=.\MutexLock.hpp
# End Source File
# Begin Source File

SOURCE=.\Mysql.hpp
# End Source File
# Begin Source File

SOURCE=.\MysqlConnection.h
# End Source File
# Begin Source File

SOURCE=.\MysqlResultSet.hpp
# End Source File
# Begin Source File

SOURCE=.\MysqlStatement.hpp
# End Source File
# Begin Source File

SOURCE=.\Nat.h
# End Source File
# Begin Source File

SOURCE=.\ObjectModule.hpp
# End Source File
# Begin Source File

SOURCE=.\Operation.h
# End Source File
# Begin Source File

SOURCE=.\Oracle.h
# End Source File
# Begin Source File

SOURCE=.\OracleConnection.h
# End Source File
# Begin Source File

SOURCE=.\Posix.h
# End Source File
# Begin Source File

SOURCE=.\PreparedStatement.h
# End Source File
# Begin Source File

SOURCE=.\pthread.h
# End Source File
# Begin Source File

SOURCE=.\PThreadModule.hpp
# End Source File
# Begin Source File

SOURCE=.\Query.h
# End Source File
# Begin Source File

SOURCE=.\RequestDataBufferQueueListener.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\ResourceLoader.hpp
# End Source File
# Begin Source File

SOURCE=.\ResultSet.hpp
# End Source File
# Begin Source File

SOURCE=.\RunMode.h
# End Source File
# Begin Source File

SOURCE=.\Runnable.hpp
# End Source File
# Begin Source File

SOURCE=.\Select.h
# End Source File
# Begin Source File

SOURCE=.\SIPServer.h
# End Source File
# Begin Source File

SOURCE=.\SQLException.hpp
# End Source File
# Begin Source File

SOURCE=.\Statement.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Sybase.h
# End Source File
# Begin Source File

SOURCE=.\SybaseConnection.h
# End Source File
# Begin Source File

SOURCE=.\Sync.hpp
# End Source File
# Begin Source File

SOURCE=.\targetver.h
# End Source File
# Begin Source File

SOURCE=.\Thread.hpp
# End Source File
# Begin Source File

SOURCE=.\Update.h
# End Source File
# Begin Source File

SOURCE=.\WinAPIThreadModule.hpp
# End Source File
# Begin Source File

SOURCE=.\XMPPServer.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\logo.ico
# End Source File
# Begin Source File

SOURCE=.\Script2.rc
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "root"

# PROP Default_Filter ""
# End Group
# End Target
# End Project
