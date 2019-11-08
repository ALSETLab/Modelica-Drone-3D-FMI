#ifndef fmi2ImportUtils_h
#define fmi2ImportUtils_h
/* 
 *	Common utility functions for import of FMUs in Modelica. Currently only used on Linux.
*/

#if defined(__linux__) && !defined(NO_FILE)

#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
/* might need access to non-standard function dladdr */
#define __USE_GNU
#include <dlfcn.h>
#undef __USE_GNU

/* Linux shared object implementations of Windows specific DLL handling functions */
static void* LoadLibrary(const char* lpFileName)
{
	char* pathFMU;
	int len;
	char* soDirs = NULL;
	char* dirName;
	void* handle = NULL;
	void* depHandles[128];
	int nrOfDephandles = 0;

	/* Search the binary directories for the FMU. */
	/* Cannot rely on the internal search in dlopen since it uses LD_LIBRARY_PATH
	value set when process starts, which is too early. */
	pathFMU = getenv("LD_LIBRARY_PATH_FMU");
	if (pathFMU == NULL) {
		ModelicaError("Failed to get environment variable LD_LIBRARY_PATH_FMU");
		goto done;
	}

	soDirs = strdup(pathFMU);
	if (soDirs == NULL) {
		ModelicaFormatError("Out of memory when loading %s", lpFileName);
		goto done;
	}
	dirName = strtok(soDirs, ":");
	while (dirName != NULL) {
		char soPath[1024];
		struct stat sb;

		if (snprintf(soPath, sizeof(soPath), "%s/%s", dirName, lpFileName) == sizeof(soPath)) {
			ModelicaFormatError("Internal buffer soPath too small when loading %s", lpFileName);
			goto done;
		}
		if (stat(soPath, &sb) == 0) {
			/* to succeed, we first need to open possible dependencies (typical scenario is FMU import) */
			DIR *dir;
			struct dirent *ent;
			if ((dir = opendir(dirName)) != NULL) {
				/* print all the files and directories within directory */
				while ((ent = readdir(dir)) != NULL) {
					/* skip special directories (avoiding use of d_type since not supported everywhere)
					and the main file to load */
					if (strcmp(ent->d_name, ".") != 0 &&
						strcmp(ent->d_name, "..") != 0 &&
						strcmp(ent->d_name, lpFileName) != 0) {
						char soDepPath[1024];
						if (snprintf(soDepPath, sizeof(soDepPath), "%s/%s", dirName, ent->d_name) == sizeof(soDepPath)) {
							ModelicaFormatError("Internal buffer soPath too small when loading %s", lpFileName);
							goto done;
						}
						depHandles[nrOfDephandles] = dlopen(soDepPath, RTLD_NOW);
						if (depHandles[nrOfDephandles] == NULL) {
							ModelicaError(dlerror());
						}
						else {
							if (++nrOfDephandles >= sizeof(depHandles)) {
								ModelicaFormatError("Too many files in %s", dirName);
								/* do the best of it: reuse last */
								dlclose(depHandles[--nrOfDephandles]);
							}
						}
					}
				}
				closedir(dir);

				handle = dlopen(soPath, RTLD_NOW);
				if (handle != NULL) {
					int i;
					for (i = 0; i < nrOfDephandles; ++i) {
						/* close all dependency file handles */
						dlclose(depHandles[i]);
					}
					goto done;
				}
				ModelicaError(dlerror());
			}
			else {
				/* could not open directory */
				ModelicaFormatError("Failed to open directory %s", dirName);
			}
		}
		dirName = strtok(NULL, ":");
	}
	ModelicaFormatError("Did not find %s in the paths in \"%s\"", lpFileName, soDirs);

done:
	free(soDirs);
	return handle;
}

static void* GetProcAddress(void* hModule, char* lpProcName)
{
	return dlsym(hModule, lpProcName); 
}
static void FreeLibrary(void* hModule)
{
	dlclose(hModule); 
}
#endif /* defined(__linux__) && !defined(NO_FILE) */

#endif
