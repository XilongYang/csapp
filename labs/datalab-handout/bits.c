/* 
 * CS:APP Data Lab 
 * 
 * Xilong Yang
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(x & y) & ~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(~((x + 1) ^ x) + !(x ^ ~0));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  x = x & (x >> 16);
  x = x & (x >> 8);
  x = x & (x >> 4);
  x = x & (x >> 2);
  return (x >> 1) & 1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int inrange = x & ~0x3F;
  int not0 = !x;
  int leadding3 = ((x >> 4) ^ 3);
  int out09 = !(x & 0x06) | !(x & 0x08);
  return !(inrange + not0 + leadding3 + !out09);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask_x = ((!x) << 31) >> 31;
  y = ~mask_x & y;
  z = mask_x & z;
  return y + z;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // Check the sign bits.
  // x <= y is possible when any of following condition is satisfied:
  // 1. The 2 sign bits of x and y are same
  // 2. The sign bits are not same but the x's sign bit is set to 1 
  //    (which means x is negative and y is positive).
  // If any of those condition is satisfied, the sign_check will be set to 0.
  int sign_x = (x >> 31) & 1;
  int sign_y = (y >> 31) & 1;
  int diff_sign = sign_x ^ sign_y;
  int sign_check = diff_sign & (!sign_x);

  // Compare x and y.
  // For both positive number and negative number, the number which 
  // contains the most significant 1 will be the greater one.
  // Get the different bits between x and y.
  int compare = x ^ y;
  // Transfer the compare result to the form '00..011..1', which means 
  // all of the bits in the right of the most significant bit should set to 1.
  compare = compare | (compare >> 1);
  compare = compare | (compare >> 2);
  compare = compare | (compare >> 4);
  compare = compare | (compare >> 8);
  compare = compare | (compare >> 16);
  // Erase all but the most significant bit.
  // For example, consider the formalized number 00001111, there are
  //   (compare >> 1): 00000111
  //   (compare &  1): 1
  //   (compare >> 1) + (compare & 1): 00001000
  // There are two special cases:
  // 1. When x == y, compare will be 0 and the result of the expression (compare & 1) will also be 0.
  //    Thus the result of the expression (compare >> 1) + (compare & 1) will be 0.
  //
  // 2. When the sign bit is difference, the result of the express (compare >> 1) will be 0xFFFFFFFFFFFFFFFF.
  //    Thus the result of the expression (compare >> 1) + (compare & 1) will be 0.
  //    That is, the expression is invalid in this case, but at least it will not interference the sign check.
  //    So it still works.
  compare = (compare >> 1) + (compare & 1);
  // If the most significant bit is contained by x, result will be 0.
  // Otherwise it will be 1.
  compare = compare & x;

  // The x <= y if and only if
  // the most significant different bit is contained by x
  // and the sign_check is passed.
  return !(compare + sign_check);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  x = (x >> 16) | x;
  x = (x >> 8) | x;
  x = (x >> 4) | x;
  x = (x >> 2) | x;
  x = (x >> 1) | x;
  return ~x & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int mask_2bit = 0x55;
  int mask_4bit = 0x33;
  int mask_8bit = 0x0f;
  int mask_16bit = 0xff;
  int mask_32bit = 0xff;

  // Inverse negative
  x = (x >> 31) ^ x;

  // Set the bits in the right of most significant 1 to 1.
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  // Count 1s
  // Generate a 2 bit mask 0x55555555(0101....)
  mask_2bit += mask_2bit << 8;
  mask_2bit += mask_2bit << 16;

  // Group each 2 bits to present the sum of 1s in those bits.
  x = (x & mask_2bit) + ((x >> 1) & mask_2bit);

  // Generate a 4 bit mask 0x33333333(00110011....)
  mask_4bit += mask_4bit << 8;
  mask_4bit += mask_4bit << 16;

  // Group each 4 bits to present the sum of 1s in those bits.
  x = (x & mask_4bit) + ((x >> 2) & mask_4bit);

  // Generate a 8 bit mask 0x0f0f0f0f(0000111100001111....)
  mask_8bit += mask_8bit << 8;
  mask_8bit += mask_8bit << 16;

  // Group each 8 bits to present the sum of 1s in those bits.
  x = (x & mask_8bit) + ((x >> 4) & mask_8bit);

  // Generate a 16 bit mask 0x00ff00ff(00000000111111110000000011111111)
  mask_16bit += mask_16bit << 16;

  // Group each 16 bits to present the sum of 1s in those bits.
  x = (x & mask_16bit) + ((x >> 8) & mask_16bit);

  // Generate a 32 bit mask 0x00ff00ff(00000000000000001111111111111111)
  mask_32bit += mask_32bit << 8;

  // Group each 32 bits to present the sum of 1s in those bits.
  x = (x & mask_32bit) + ((x >> 16) & mask_32bit);

  // Minimum bits to present the number should be numbers of 1s + 1.
  return x + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x007FFFFF;

  if (exp == 0xFF) {
    // NaN, Inf
    return uf;
  } else if (exp == 0 && frac != 0) {
    // Denormalized.
    exp = frac >> 22 ;
    frac = (frac << 1) & 0x007FFFFF;
  } else if (exp != 0) {
    // Normalized
    exp = (exp + 1) & 0xFF;
    frac = (exp == 0xFF) ? 0 : frac;
  }

  return sign << 31 | exp << 23 | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x007FFFFF;

  int result = 0x80000000;

  if (exp == 0xFF) {
    // NaN, Inf
    return 0x80000000;
  } else if (exp == 0) {
    // Denormalized.
    return 0;
  } else if (exp != 0) {
    // Normalized
    int bias = 127;
    int e = exp - bias;
    if (e < 0) {
        return 0;
    } else if (e >= 31) {
        return 0x80000000;
    }
    frac |= 0x00800000;
    result = e > 23 ? (frac << (e - 23)) : (frac >> (23 - e));
  }

  // Negative value
  if (sign) {
    result = (0x80000000 - result) | 0x80000000;
  }

  return result;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    unsigned exp = 0;
    unsigned frac = 0;
    if (x > 127) {
      return 0x7f800000;
    } else if (x < -149) {
      return 0;
    } else if (x > -127) {
      exp = x + 127;
    } else {
      frac = 1 << (23 - (-126 - x));
    }
    return exp << 23 | frac;
}
