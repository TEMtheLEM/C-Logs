#include "logger.h"
#include "colours.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	LogInfo("A VERY informative message");
	LogOk("Everything works!");
	LogWarning("But something appears janky...");
	LogError("And something broke.");

	Log(NULL, "Blank message, no colouring", NULL, "Custom suffix!");
	Log(BOLD_BLUE, "Bold blue message!!!", NULL, "Still a boring suffix");
	printf("Doesn't mess with printf!\n");

	char *fun_msg = RainbowString("Do amazing things!", 1);
	Log(NULL, fun_msg, UL_BG_MAGENTA, "Fun stuff!");
	free(fun_msg);

	Log(NULL, NULL, BACKG_MAGENTA, NULL);

	return 0;
}
