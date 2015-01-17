# Microsoft Developer Studio Project File - Name="boost_1_34_0_serialization" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=boost_1_34_0_serialization - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "boost_1_34_0_serialization.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "boost_1_34_0_serialization.mak" CFG="boost_1_34_0_serialization - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "boost_1_34_0_serialization - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "boost_1_34_0_serialization - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "boost_1_34_0_serialization - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "boost_1_34_0_serialization - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "boost_1_34_0_serialization - Win32 Release"
# Name "boost_1_34_0_serialization - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\basic_archive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_archive_impl.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_iarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_iserializer.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_oarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_oserializer.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_pointer_iserializer.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_pointer_oserializer.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_serializer_map.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_text_iprimitive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_text_oprimitive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_text_wiprimitive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_text_woprimitive.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_xml_archive.cpp
# End Source File
# Begin Source File

SOURCE=.\binary_iarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\binary_oarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\binary_wiarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\binary_woarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\codecvt_null.cpp
# End Source File
# Begin Source File

SOURCE=.\extended_type_info.cpp
# End Source File
# Begin Source File

SOURCE=.\extended_type_info_no_rtti.cpp
# End Source File
# Begin Source File

SOURCE=.\extended_type_info_typeid.cpp
# End Source File
# Begin Source File

SOURCE=.\polymorphic_iarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\polymorphic_oarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\stl_port.cpp
# End Source File
# Begin Source File

SOURCE=.\text_iarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\text_oarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\text_wiarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\text_woarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\utf8_codecvt_facet.cpp
# End Source File
# Begin Source File

SOURCE=.\void_cast.cpp
# End Source File
# Begin Source File

SOURCE=.\xml_grammar.cpp
# End Source File
# Begin Source File

SOURCE=.\xml_iarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\xml_oarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\xml_wgrammar.cpp
# End Source File
# Begin Source File

SOURCE=.\xml_wiarchive.cpp
# End Source File
# Begin Source File

SOURCE=.\xml_woarchive.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
