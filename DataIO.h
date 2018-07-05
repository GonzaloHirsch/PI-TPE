#include <stdlib.h>

#ifndef PI_TPE_DATAIO_H
#define PI_TPE_DATAIO_H

/*
 * Alternative for strtok. separateToken replaces delimiter with NULL and stores each token in an array.
 * Parameters:
 * char * str --> Source string. This string will be modified, can't be const.
 * char del --> Character delimiter.
 * char ** strArr --> Array of strings which will store all the strings separated by the delimiter.
 * size_t dim --> Max dimension of strArr.
 * Returns size_t --> New size of strArr.
 */
size_t separateToken(char *str, char del, char ** strArr, size_t dim);


#endif
