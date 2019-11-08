/* Implementation of memdebug.h */

#include "conf.h"

#ifdef MEMLEAK_DEBUG

#include "memdebug.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/* ----------------- configuration ----------------- */

#define NCHUNKS 8092

/* --------------- type definitions -------------- */

typedef struct {
	void* ptr;
	size_t size;
} MemChunk;

/* ----------------- local function declarations ----------------- */

static void logmsg(const char *msg, ...);

/* ----------------- local variables ----------------- */

static MemChunk mem_chunks[NCHUNKS];
static size_t mem_tot;
static size_t n_allocs;
static size_t n_frees;

/* --------------------------------------- */
void memdebug_setup()
{
	/* handle multiple calls */
	static int setup_done = 0;
	int i;

	if (setup_done) {
		return;
	}

	for (i = 0; i < NCHUNKS; i++) {
		mem_chunks[i].ptr = NULL;
		mem_chunks[i].size = 0;
	}
	mem_tot = 0;
	n_allocs = 0;
	n_frees = 0;
	setup_done = 1;
}

/* --------------------------------------- */
void* memdebug_calloc(size_t nobj, size_t size)
{
	void *obj = calloc(nobj, size);
	++n_allocs;

	if (obj != NULL) {
		size_t tot_size = nobj * size;
		int i = 0;

		while (i < NCHUNKS && mem_chunks[i].ptr != NULL) {
			++i;
		}
		assert(i < NCHUNKS);
		mem_chunks[i].ptr = obj;
		mem_chunks[i].size = tot_size;
		mem_tot += tot_size;
	} else {
		logmsg("calloc failed!");
		assert(0);
	}

	return obj;
}

/* --------------------------------------- */
void memdebug_free(void* obj)
{
	int i = 0;

	if (obj == NULL) {
		return;
	}

	while (i < NCHUNKS && mem_chunks[i].ptr != obj) {
		++i;
	}
	if (i == NCHUNKS) {
		logmsg("free attempted on un-allocated pointer: %p!", obj);
		assert(0);
		return;
	}
	assert(i < NCHUNKS);
	free(obj);
	++n_frees;
	mem_chunks[i].ptr = NULL;
	mem_tot -= mem_chunks[i].size;
}

/* --------------------------------------- */
void memdebug_check()
{
	int i;
	for (i = 0; i < NCHUNKS; i++) {
		if (mem_chunks[i].ptr != NULL) {
			logmsg("memory on index %d: %p not freed: %d bytes", i, mem_chunks[i].ptr, mem_chunks[i].size);
		}
	}
	if (mem_tot > 0) {
		logmsg("memory leak: %u bytes", mem_tot);
	} else {
		logmsg("no memory leaks");
	}
}

/* ----------------- local function definitions ----------------- */

static void logmsg(const char *msg, ...)
{
	char buf[256];
	va_list ap;

	va_start(ap, msg);
	vsnprintf(buf, sizeof(buf) - 1, msg, ap);
	va_end(ap);

	printf("MEMORY DEBUG: %s\n", buf);
}

#endif
