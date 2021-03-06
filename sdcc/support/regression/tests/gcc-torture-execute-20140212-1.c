/*
   20140212-1.c from the execute part of the gcc torture suite.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#endif

/* PR rtl-optimization/60116 */
/* Reported by Zhendong Su <su@cs.ucdavis.edu> */

int a, b, c, d = 1, e, f = 1, h, i, k;
char g, j;

#ifndef __SDCC_ds390 // Enable when ds390 supports long long
void
fn1 (void)
{
  int l;
  e = 0;
  c = 0;
  for (;;)
    {
      k = a && b;
      j = k * 54;
      g = j * 147;
      l = ~g + (long long) e && 1;
      if (d)
	c = l;
      else
	h = i = l * 9UL;
      if (f)
	return;
    }
}
#endif

void
testTortureExecute (void)
{
#ifndef __SDCC_ds390 // Enable when ds390 supports long long
  fn1 ();
  if (c != 1)
    ASSERT (0);
#endif
}
