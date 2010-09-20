#include <stdbool.h>
#include <stdint.h>

void fib();

extern struct {  /* copilotStatefib */
  struct {  /* fib */
    uint64_t prophVal__fib[3];
    bool outputVal__t;
    uint64_t outputVal__fib;
    uint64_t updateIndex__fib;
    uint64_t outputIndex__fib;
  } fib;
} copilotStatefib;

