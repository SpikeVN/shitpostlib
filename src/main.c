/************************************************************************
 * Copyright (c) 2022 SpikeBonjour.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "gaylib.h"
#include "utf8.h"

void show_help() {
	// TODO - localization and manpage
	puts("Usage: shitpostlib [option] text...\nShitpost utilities for professional shitposter.\nOptions\n  -h, --help               Shows this help message.\n  -g, --gaylang            Generate text in a copypasta-like style.\n\nBugs can be reported at https://github.com/SpikeVN/shitpostlib/issues.");
}


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	// +1 for a space character.
	// Sometimes unicode character takes more than 1 byte (less than 4 in most cases)
	// so it have to be multiplied by 4 to have a margin for error (segfault if not).
	char *content = malloc(u8_strlen(argv[2])*4);
	if (argc < 3) {
		fprintf(stderr, "not enough arguments. expected more than 3 (found %d). exiting...\n", argc);
		exit(-1);
	} else if (argc == 3) {
		strcpy(content, argv[2]);
	} else {
		// TODO - seperate this into a function.
		char *tmp;
		strcpy(content, argv[2]);
		strcat(content, " ");
		for (int i = 3; i <= (argc - 1); i++) {
			// Sometimes unicode character takes more than 1 byte (less than 4 in most cases)
			// so it have to be multiplied by 4 to have a margin for error (segfault if not).
			tmp = realloc(content, u8_strlen(content)*4 + 1 + u8_strlen(argv[i])*4);
			if (!tmp) {
				free(content);
				content = NULL;
				return -1;
			}

			content = tmp;
			strcat(content, argv[i]);
			if (i < (argc - 1))
				strcat(content, " ");
		}
	}
	// TODO - struct and switch based optiona mapping (like in GNU coreutils)
	if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--gaylang") == 0) {
		if (glb_init_dict()) {
			fprintf(stderr, "error when reading gaylang dict. exiting...");
			exit(-1);
		}
		puts(glb_generate(content));
	} else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)

	return 0;
}
