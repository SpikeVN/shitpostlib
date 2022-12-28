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

/**
 * @file
 *
 * Purpose:  The gaylib algorithm implementation.
 *
 * Author:   SpikeBonjour.
 *
 */
#include "gaylib.h"

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cJSON.h"
#include "utf8.h"

char *dictionary_text;
cJSON *dictionary;

int glb_init_dict()
{
	char *dt = NULL, *tmp = NULL;
	FILE *f = fopen("../assets/gaydict.json", "r");
	if (errno != 0) {
		return errno;
	}
	size_t size = 0, index = 0;
	int ch = EOF;
	while (ch) {
		ch = getc(f);
		// Check for EOF
		if (ch == EOF) ch = 0;
		if (size > index) {
			dt[index++] = ch;
			continue;
		}
		// If the buffer is not enough, expand the size.
		size += 4;  // only UTF-8 input, so max is 4 bytes.
		tmp = realloc(dt, size);
		if (!tmp) {
			free(dt);
			dt = NULL;
			break;
		}
		dt = tmp;
		// Store the character
		dt[index++] = ch;
	}
	dictionary_text = dt;
	dictionary = cJSON_Parse(dictionary_text);
	return 0;
}

char *glb_get(char *source)
{
	const cJSON *result = cJSON_GetObjectItemCaseSensitive(dictionary, source);
	if (cJSON_IsString(result))
		return result->valuestring;
	return source;
}

char *glb_generate(char *source)
{
	char *token,
	     *output,
	     *tmp = NULL;
	fflush(stdout);
	token = strtok(source, " ");
	output = malloc(u8_strlen(token));
	strcpy(output, token);
	// Ignore these warnings, it is compatible.
	for (;;) {
		token = strtok(NULL, " ");
		if (token == NULL) {
			break;
		}
		// 1 for the space character.
		tmp = realloc(output, u8_strlen(output) + 1 + u8_strlen(token));
		if (!tmp) {
			free(output);
			output = NULL;
			return 0;
		}
		output = tmp;
		strcat(output, " ");
		strcat(output, glb_get(token));
	}
	return output;
}

