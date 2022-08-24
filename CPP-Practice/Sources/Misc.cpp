#include "../Headers/Misc.h"
#include <corecrt_memory.h>

void PlayWithPointers() {
	char* buffer = new char[8];
	memset(buffer, 0, 8);

	delete[] buffer;

}