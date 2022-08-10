#include <stdlib.h>

void *ft_calloc(size_t n, size_t size)
{
    if (n == 0 || size == 0)
        return NULL;
    void *allocated = malloc(n * size);
    if (allocated == NULL)
        return NULL;
    return (allocated);
}