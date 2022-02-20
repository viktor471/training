#include "rec_sh.h"
#include "inner.h"
void rec(int iteration, int *n){
		  if(iteration > 1) rec(iteration - 1, n);
		  else inner(n);
}
