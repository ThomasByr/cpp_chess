#pragma once

#define IX(file, rank) ((file) + (rank) * int(8))
#define FILE(ix) ((ix) % int(8))
#define RANK(ix) ((ix) / int(8))
