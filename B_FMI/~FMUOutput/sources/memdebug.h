/* Functions used for debugging memory leaks within libfmi. The idea is to wrap calls to calloc and free and monitor
   memory usage. */

#ifdef MEMLEAK_DEBUG

#ifndef memdebug_h

#include <stddef.h>

/* Setup memory debug (no teardown necessary). All calls but the first are ignored. */
void memdebug_setup();

/* Wrapper for calloc */
void* memdebug_calloc(size_t nobj, size_t size);

/* Wrapper for free */
void memdebug_free(void* obj);

/* Checks whether calloc:s and free:s used so far matches up. */
void memdebug_check();

#endif /* memdebug_h */

#endif /* MEMLEAK_DEBUG */
