* Assumptions
  * Integers are represented in two's-complement form.
  * Right shifts of signed data are performed arithmetically.
  * Data type int is w bits long. Unless other size specified, the length of w will be a multiple of 8. We can compute it by sizeof(int) << 3.
* Forbidden
  * Conditionals (if or ?:), loops, switch statements, function calls, and macro invocations.
  * Division, modulus, and multiplication.
  * Relative comparison operations (<, >, <=, and >=).
* Allowed operations
  * All bit-level and logic operations.
  * Left and right shifts, but only with shift amounts between 0 and w - 1.
  * Addition and subtraction.
  * Equality (==) and inequality (!=) tests. (Some of the problems do not allow these).
  * Integer constants INT_MIN and INT_MAX.
  * Casting between data types int and unsigned, either explicitly or implicitly.

