#pragma once

#define IX(i, j) ((i) + (j)*8)
#define FILE(i) ((i)&7)
#define RANK(i) ((i) >> 3)
