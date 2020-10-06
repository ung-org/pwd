/*
 * UNG's Not GNU
 *
 * Copyright (c) 2011-2020, Jakob Kaivo <jkk@ung.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _XOPEN_SOURCE 700
#include <locale.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	enum { LOGICAL, PHYSICAL } output = LOGICAL;
	int c;
	while ((c = getopt(argc, argv, "LP")) != -1) {
		switch (c) {
		case 'L':
			output = LOGICAL;
			break;

		case 'P':
			output = PHYSICAL;
			break;

		default:
			return 1;
		}
	}

	char *pwd = getenv("PWD");
	char cwd[PATH_MAX];
	if (pwd == NULL || pwd[0] == '\0') {
		pwd = getcwd(cwd, sizeof(cwd));
	}

	if (output == LOGICAL) {
		/* TODO: remove dot and dot-dot */
	}

	if (output == PHYSICAL) {
		/* TODO: get rid of symlinks */
		/* TODO: clean up slashes */
	}

	printf("%s\n", pwd);
	return 0;
}
