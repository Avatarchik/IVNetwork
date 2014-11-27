//================= IV:Network - https://github.com/GTA-Network/IV-Network =================
//
// File: Common.h
// Project: (Shared)
// Author: CrackHD
// License: See LICENSE in root directory
//
//==============================================================================

#ifndef Common_h
#define Common_h

// Common definitions for both client and server, windows and linux (structs, etc).

#ifdef _WIN32
#include <WinSock2.h>
#include <Windows.h>
#include <windowsx.h>
#endif

// include
#include "CColor.h"
#include "CString.h"

// typedef
//typedef CString string;							// CString class defined is in /Shared/CString.h
typedef unsigned short EntityId;

#ifdef _CLIENT
using namespace std; // Conflicts with string(std::string) in network stuff
#include	<aclapi.h>
#include	<algorithm>
#include	<assert.h>
#include	<ctime>
#include	<d3d9.h>
#include	<list>
#include	<map>
#include	<queue>
#include	<process.h>
#include	<Psapi.h>
#include	<stdio.h>
#include	<stdio.h>
#include	<string>
#include	<tchar.h>
#include	<vector>
#include	"Game\eGame.h"
#include	"Network\CBitStream.h"
#endif

#include "CNetSync.h"

// If compiling in debug mode force mod debug mode
#ifdef _DEBUG
#undef IVN_DEBUG
#define IVN_DEBUG 1
#endif

// DirectX Input version
#define DIRECTINPUT_VERSION 0x0800

// Forced debug
#ifdef FORCE_DEBUG
#ifndef IVN_DEBUG
#define IVN_DEBUG 1
#endif
#endif

// Forced release
#ifdef FORCE_RELEASE
#ifdef IVN_DEBUG
#undef IVN_DEBUG
#endif
#endif

// Version defines
#ifdef IVN_DEBUG
#define DEBUG_IDENTIFIER " - Debug"
#else
#define DEBUG_IDENTIFIER
#endif

#define INVALID_ENTITY_ID ((EntityId)0xFFFF)
#define NETWORK_VERSION 0x1

// Mod version string
#define MOD_VERSION_STRING "1.0.0 DEV EFLC"

// Masterlist Information
#define MASTERLIST_URL 		"www.gta-network.net/masterlist/iv"
#define MASTERLIST_TIMEOUT	50000

// Version identifiers
#define VERSION_IDENTIFIER MOD_VERSION_STRING DEBUG_IDENTIFIER " [" __DATE__ ", " __TIME__ "]"
#define VERSION_IDENTIFIER_2 MOD_VERSION_STRING DEBUG_IDENTIFIER

// Operating system string
#ifdef _WIN32
#define OS_STRING "Windows"
#else
#define OS_STRING "Linux"
#endif

// Library debug suffix
#ifdef _DEBUG
#define DEBUG_SUFFIX // ".Debug"
#else
#define DEBUG_SUFFIX
#endif

// ExitProcess macro for linux
#ifndef _WIN32
#define ExitProcess exit
#endif

// Library extension
#ifdef _WIN32
#define LIBRARY_EXTENSION ".dll"
#else
#define LIBRARY_EXTENSION ".so"
#endif

// Basic Names
#define _DEV
//#define CHEAP_RELEASE
#define MOD_NAME "IV:Network"
#define MOD_SHORT_NAME "IVN"
#define MOD_SHORT_NAME_ILLEGAL "IV:Net"
#define CLIENT_CORE_NAME "IVNetwork"
#define SERVER_CORE_NAME "Server.Core"
#define NETWORK_MODULE_NAME "Network.Core"
#define REGISTRY_AREA "Software\\IVNetwork"
#define GAME_DIRECTORY "GrandTheftAutoDirectory"
#define MP_START_EXECUTABLE "LaunchIVNetwork.exe"
#define GAME_DEFAULT_EXECUTABLE "EFLC.exe"
#define SHORT_URI_LAUNCH_1 "ivn://"
#define SHORT_URI_LAUNCH_2 "ivnetwork://"
#define SHORT_URI_LAUNCH_3 "ivn"
#define SHORT_URI_LAUNCH_4 "ivnetwork"
#define SHORT_COMMANDLINE_LAUNCH_1 "-ivn"
#define DEFAULT_REGISTRY_GAME_DIRECTORY "Software\\Rockstar Games\\EFLC"

// Library Exports
#ifdef EXPORT
#undef EXPORT
#endif
#ifdef _WIN32
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT extern "C"
#endif

// Include all defines for game limits
#include "GameLimits.h"

// Warning disable
#pragma warning(disable:4996) // Disables _s warning
#pragma warning(disable:4409) // Disable illegal instruction warning(asm)
#pragma warning(disable:4042) // Disable LNK 4042 extra objects
#pragma warning(disable:4099) // Disable PDB not found warnings
#pragma warning(disable:4244) // Disable converstion error warnings

// Macros
#define ARRAY_LENGTH(array)	(sizeof(array) / sizeof(array[0]))
#define	SAFE_DELETE(memory)	{ delete memory; memory = nullptr; }
#define	SAFE_RELEASE(p)	{ if ( (p) ) { (p)->Release(); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(memory) if(memory) { delete [] memory; memory = nullptr; }
#define SAFE_FREE(memory) if(memory) { free(memory); memory = nullptr; }
#define	PAD(prefix, name, size) unsigned char prefix##_##name##[size]

// Bit manipulation macros
#define SET_BIT(a, b) a |= b
#define IS_BIT_SET(a, b) ((a & b) != 0)
#define UNSET_BIT(a, b) a &= ~(b)

// Logfile definitions
#define CLIENT_LOG_FILE "multiplayer//IVN-Client.log"
#define CLIENT_CHATLOG_FILE "multiplayer//IVN-Chat.log"
#define CLIENT_SETTINGS_FILE "multiplayer//IVN-Settings.xml"

// Chat definitions
#define	CHAT_MAX_CHAT_LENGTH 128
#define	CHAT_RENDER_LINES 10
#define	CHAT_MAX_LINES 200

// Spawn position
#define DEFAULT_SPAWN_POSITION -547.40f, -961.30f, 4.84f

// XLive Hook
#define FAKE_MAGIC 0xDEADDEAD

// Camera defs
#define CVEC_TO_D3DVEC(vec) &D3DXVECTOR3(vec.fX, vec.fY, vec.fZ)
#define D3DVEC_TO_CVEC(vec) &CVector3(vec.x, vec.y, vec.z)

// Macros
#define GET_RPC_CODEX(x) CString("IVN0xF%dF", int(x)).Get()
#define CHECK_VALID(x) if(!x) return false;
#define CHECK_VALID_VOID(x) if(!x) return;

#endif // Common_h