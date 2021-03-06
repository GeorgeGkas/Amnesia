/**
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2017 George Gkasdrogkas
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

#include "amnesia.h"

static int nftwCallback(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
  /**
   * If item is file then open it for binary writing, which
   * automatically clear all it's content.
   */
  fopen(fpath, "wb"); 

  /**
    * Give the processor a small breath.
    */
  usleep(200);

  /**
   * Proceed to next item (file, folder, symbolic link, etc).
   */
  return 0;
}

int main() {
  /**
   * nftw() walks through the directory tree that is located under the directory (ROOT), 
   * and calls nftwCallback() once for each entry in the tree. 
   * By default, directories are handled before the files and subdirectories 
   * they contain (preorder traversal). 
   * FTW_PHYS is passed as a flag. That allows us not to follow symbolic links.
   */
  if (nftw(ROOT, nftwCallback, 20, FTW_PHYS) == -1) {
    perror("nftw");
  }
  
  return 0;
}
