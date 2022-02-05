#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "colours.h"
#include "logger.h"

char *CurrentTimeInfo() {
	// Get time info
	time_t now = time(NULL);
	struct tm tinfo = *localtime(&now);

	// 1024 bytes (1023 characters + null) are more than safe,
	// but if a buffer overflow occours just bump this up.
	const int strbuf = 1024;

	// Allocate the string and move info into it.
	char *ftime = malloc(strbuf);
	snprintf(ftime, strbuf, "%d-%02d-%02d %02d:%02d:%02d", tinfo.tm_year + 1900, tinfo.tm_mon + 1, tinfo.tm_mday, tinfo.tm_hour, tinfo.tm_min, tinfo.tm_sec);

	return ftime;
}

void Log(const char *msg_clr, const char *msg, const char *suff_clr, const char *suff) {
	/** 7 bytes more are added to the buffer to accomadate for;
	 *  a null character (1),
	 *  ": " (2),
	 *  and COLOUR_RESET; "\033[0m" (4)
	 */
	char suffix[(suff ? strlen(suff) : 0) + (suff_clr ? strlen(suff_clr) : 0) + 7];
	if (suff)
		sprintf(suffix, "%s%s%s%s", suff_clr ? suff_clr : "", suff, COLOUR_RESET, ": ");
	else
		strcpy(suffix, "");

	// Get time and make it colourful
	char *ftime = CurrentTimeInfo();
	char *coloured_time = ColourString(ftime, BRIGHT_GREY);
	free(ftime);

	// Print everything
	printf("[%s%s%s]: %s%s%s\n", suffix, coloured_time, COLOUR_RESET, msg_clr ? msg_clr : "", msg, COLOUR_RESET);
	free(coloured_time);
}

void LogInfo(const char *msg) {
	Log(ITALIC_WHITE, msg, BOLD_BLUE, "INFO");
}

void LogOk(const char *msg) {
	Log(ITALIC_WHITE, msg, BOLD_GREEN, "OK");
}

void LogWarning(const char *msg) {
	Log(ITALIC_WHITE, msg, BOLD_YELLOW, "WARN");
}

void LogError(const char *msg) {
	Log(ITALIC_WHITE, msg, BOLD_RED, "ERROR");
}
