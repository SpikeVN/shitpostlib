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
 * Purpose:  The gaylib library.
 *
 * Author:   SpikeBonjour.
 *
 */

#ifndef GAYLIB_H
#define GAYLIB_H

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Initializes the gaylib dictionary.
 * 	  This must be the first function to be called.
 * @return `0` if succeeds, `1` if fails.
 */
int glb_init_dict();

/**
 * @brief Gets an entry from the gaylib dictionary.
 *
 * @return char*
 */
char *glb_get(char *source);

/**
 * @brief Generates text that mimic the style often found in copy-pasta or shitpost.
 *
 * @param source_text the original text.
 * @return generated text.
 */
char *glb_generate(char *source);

#endif /* GAYLIB_H */
