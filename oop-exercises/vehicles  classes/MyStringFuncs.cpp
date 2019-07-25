#include "MyStringFuncs.h"

/*Providing definitions for the functions*/

int StrLen(const char* srce) {
	int lenght = 0;

	if (srce == nullptr) {
		return lenght;
	}
	else {
		while (*(srce) != '\0') {
			srce++;
			lenght++;
		}
	}
	return lenght;
}

char* StrCopy(char* dest, int destLen, const char* srce) {

	/*
	do {
	*dest = *srce;
	dest++;
	} while (*srce++ != '\0');

	*dest = '\0';		//adding the terminating null

	return dest;
	*/

	for (int i = 0; i < destLen; i++) {
		dest[i] = srce[i];
	}
	dest[destLen] = '\0';		//destLen is the last index of the char array, so adding the terminating null

	return dest;

}