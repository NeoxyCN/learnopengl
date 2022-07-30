#include <stdio.h>

int logInfo(char* info);
int logWarning(char* warning);
int logError(char* error);

int logInfo(char* info) {
	printf("[info]");
	printf(info);
	printf("\n");
	return 0;
}

int logWarning(char* warning) {
	printf("[warning]");
	printf(warning);
	printf("\n");
	return 0;
}

int logError(char* error) {
	printf("[error]");
	printf(error);
	printf("\n");
	return 0;
}