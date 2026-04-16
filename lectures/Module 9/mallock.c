void *x // void pointer
int memsize;
x = malloc(memsize)

//when you are done with the block, return it to the pool using the free() function.
free (x);

Every call to malloc() must be balanced by a call to free(). a missing or double free() call is considered a bug (a missing free() statement creates a memory leak)

After freeing the pointer, the pointer should be set to NULL as an extra precaution.
