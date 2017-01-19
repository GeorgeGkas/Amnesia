/**
 *	The MIT License (MIT)
 *
 *	Copyright (c) 2017 George G. Gkasdrogkas
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
#ifndef AMNESIA_AMNESIA_H
#define AMNESIA_AMNESIA_H

/**
 * fopen() gives an error if there is not an lvalue
 * before it. We don't care. We just want to open
 * the file.
 */
#pragma GCC diagnostic ignored "-Wunused-result"

/**
 * The bellow define is required for
 * nftw().
 */
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <ftw.h> /* For nftw(). */
#include <stdio.h> /* For fopen(). */
#include <unistd.h> /* For usleep(). */

/**
 * ROOT path is the same as the executable file.
 */
#define ROOT "."

#endif