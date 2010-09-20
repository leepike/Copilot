#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned long long rnd;


static uint64_t __global_clock = 0;



struct {  /* copilotStatefib */
  struct {  /* fib */
    uint64_t prophVal__fib[3];
    bool outputVal__t;
    uint64_t outputVal__fib;
    uint64_t updateIndex__fib;
    uint64_t outputIndex__fib;
  } fib;
} copilotStatefib =
{  /* copilotStatefib */
  {  /* fib */
    /* prophVal__fib */
    { 0ULL
    , 1ULL
    , 0ULL
    },
    /* outputVal__t */  false,
    /* outputVal__fib */  0ULL,
    /* updateIndex__fib */  2ULL,
    /* outputIndex__fib */  0ULL
  }
};

/* fib.updateOutput__t */
static void __r0() {
  bool __0 = true;
  uint64_t __1 = 0ULL;
  uint64_t __2 = copilotStatefib.fib.outputIndex__fib;
  uint64_t __3 = __1 + __2;
  uint64_t __4 = 3ULL;
  uint64_t __5 = __3 % __4;
  uint64_t __6 = copilotStatefib.fib.prophVal__fib[__5];
  uint64_t __7 = 2ULL;
  uint64_t __8 = __6 % __7;
  bool __9 = __8 == __1;
  if (__0) {
  }
  copilotStatefib.fib.outputVal__t = __9;
}

/* fib.update__fib */
static void __r1() {
  bool __0 = true;
  uint64_t __1 = 0ULL;
  uint64_t __2 = copilotStatefib.fib.outputIndex__fib;
  uint64_t __3 = __1 + __2;
  uint64_t __4 = 3ULL;
  uint64_t __5 = __3 % __4;
  uint64_t __6 = copilotStatefib.fib.prophVal__fib[__5];
  uint64_t __7 = 1ULL;
  uint64_t __8 = __7 + __2;
  uint64_t __9 = __8 % __4;
  uint64_t __10 = copilotStatefib.fib.prophVal__fib[__9];
  uint64_t __11 = __6 + __10;
  uint64_t __12 = copilotStatefib.fib.updateIndex__fib;
  if (__0) {
  }
  copilotStatefib.fib.prophVal__fib[__12] = __11;
}

/* fib.incrUpdateIndex__fib */
static void __r3() {
  bool __0 = true;
  uint64_t __1 = copilotStatefib.fib.updateIndex__fib;
  uint64_t __2 = 1ULL;
  uint64_t __3 = __1 + __2;
  uint64_t __4 = 3ULL;
  uint64_t __5 = __3 % __4;
  if (__0) {
  }
  copilotStatefib.fib.updateIndex__fib = __5;
}

/* fib.output__fib */
static void __r2() {
  bool __0 = true;
  uint64_t __1 = copilotStatefib.fib.outputIndex__fib;
  uint64_t __2 = 1ULL;
  uint64_t __3 = __1 + __2;
  uint64_t __4 = 3ULL;
  uint64_t __5 = __3 % __4;
  uint64_t __6 = copilotStatefib.fib.prophVal__fib[__1];
  if (__0) {
  }
  copilotStatefib.fib.outputIndex__fib = __5;
  copilotStatefib.fib.outputVal__fib = __6;
}



void fib() {
  {
    static uint8_t __scheduling_clock = 0;
    if (__scheduling_clock == 0) {
      __r0();  /* fib.updateOutput__t */
      __r1();  /* fib.update__fib */
      __scheduling_clock = 1;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }
  {
    static uint8_t __scheduling_clock = 1;
    if (__scheduling_clock == 0) {
      __r3();  /* fib.incrUpdateIndex__fib */
      __r2();  /* fib.output__fib */
      __scheduling_clock = 1;
    }
    else {
      __scheduling_clock = __scheduling_clock - 1;
    }
  }

  __global_clock = __global_clock + 1;
}

// #pragma GCC diagnostic ignored "-Wformat"
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please pass a single argument to the simulator containing the number of rounds to execute it.\n" );
    return 1;
  }
  rnd = atoi(argv[1]);
  int i = 0;
  for(; i < rnd ; i++) {
    int j = 0;
    for (; j < 2 ; j++) {
      fib();
    }
    printf("period: %i   ", i);
    printf("fib: %llu   ", copilotStatefib.fib.outputVal__fib);
    printf("t: %i   ", copilotStatefib.fib.outputVal__t);
    printf("\n" );
    fflush(stdout);
  }
  return EXIT_SUCCESS;
}

