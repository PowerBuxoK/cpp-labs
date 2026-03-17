#include <iostream>

// Add overflow check

int signed_division(int a, int b)
{
  int result;
  asm (
      "movl %1, %%eax\n\t"    // Move dividend into EAX
      "cdq\n\t"               // Sign-extend EAX into EDX (EDX:EAX = dividend)
      "idivl %2\n\t"          // Signed divide by divisor
      "movl %%eax, %0\n\t"    // Move result from EAX to output variable
      : "=r"(result)          // Output operands
      : "r"(a), "r"(b)        // Input operands
      : "%eax", "%edx", "cc"  // Clobbered registers and condition codes
  );
  return result;
}

int main(int argc, char const* argv[])
{
  std::cout << signed_division(-100, -25) << std::endl;
  return 0;
}
