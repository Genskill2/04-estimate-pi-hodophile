#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0=0.0;
  float pi1=0.0;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}

float mc_pi(int n){
	int as = 0;
	int ac = 0;
	float pi;
	for(int i=1;i<=n;i++){
		float x=frandom();
		float y=frandom();
		float d=(x*x)+(y*y);
		as+=1;
		d=sqrt(d);
		
		if (d<=1.0){
			ac+=1; // area of square
		}
		//printf("x : %f\n",x);
		//printf("y : %f \n",y);
		//printf("d : %f\n",d);
		//printf("ac : %d\n",ac);
		//printf("as : %d\n",as);
		pi = 4*((float)ac/(float)as);
		//printf("pi : %f\n\n",pi);		
	}
	return pi;
}
