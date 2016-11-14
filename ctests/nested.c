#include <stdio.h>
#include <omp.h>
#include <gptl.h>

int main ()
{
  int i, j;
  int ret;
  int iter;

  ret = GPTLinitialize ();

  omp_set_nested (1);  // Enable nested OMP
  for (iter = 0; iter < 10; ++iter) {
#pragma omp parallel for private (j)
    for (j = 0; j < 3; ++j) {
#pragma omp parallel for private (i,ret)
      for (i = 0; i < 2; ++i) {
	ret = GPTLstart ("nested");
	ret = GPTLstop ("nested");
      }
    }
  }
  ret = GPTLpr (0);
  return 0;
}
