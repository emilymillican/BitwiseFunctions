/* 
 * CS:APP Data Lab 
 * 
 * Emily Millican emmi5856
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    int nx = ~x;
    int ny = ~y;
    int or = nx & ny;
    or = ~or;   
    return or;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {   
    int y = 85;
    int ny = y << 8;
    ny = ny | y;
    y = ny << 16;
    ny = y | ny;
    return ny;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  int x = 0;
  x = x << 24;
  x = ~x;
  return x;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
    int y = 85;
    int mask = y << 8;
    mask = mask | y;
    y = mask << 16;
    mask = y | mask;
    x = mask & x;
    return !(x ^ mask);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    int y = 170;
    int mask = y << 8;
    mask = mask | y;
    y = mask << 16;
    mask = y | mask;
    x = mask & x;
    return (!!x);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int y = 0xff;
    int mask1 = (y << ((n) << 3));
    int mask2 = (y << ((m) << 3));
    int clear = ~(mask1 | mask2);
    int swap;
    mask1 = mask1 & x;
    mask2 = mask2 & x;
    mask1 = mask1 >>(n << 3);
    mask2 = mask2 >>(m << 3);
    mask1 = mask1 & y;
    mask2 = mask2 & y;
    x = x & clear;
    mask1 = mask1 << (m << 3);
    mask2 = mask2 << (n << 3);
    swap = mask1 | mask2;
    swap = swap | x;
    return swap;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    int s = x + y;
    int mask = 1;
    int same;
    x = x >> 31;
    y = y >> 31;
    x = x & mask;
    y = y & mask;
    s = s >> 31;
    s = s & mask;
    same = !(x ^ y);
    return (!(same & (x ^ s)));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int nx, mask1, mask2;
    x = !!x;
    nx = x << 1;
    x = x | nx;
    nx = x << 2;
    x = x | nx;
    nx = x << 4;
    x = x | nx;
    nx = x << 8;
    x = x | nx;
    nx = x << 16;
    x = x | nx;
    mask1 = x & y;
    mask2 = (~x) & z;
    return(mask1 | mask2);
}
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
    int lowerBound = 0x30;
    int upperBound = 0x39;
    int mask = 0x1;
    upperBound = ((~x) + 1) + upperBound;
    lowerBound = x + ((~lowerBound) + 1);
    upperBound = upperBound >> 31;
    lowerBound = lowerBound >> 31;
    upperBound = upperBound & mask;
    lowerBound = lowerBound & mask;
    return((!lowerBound) & (!upperBound));
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
    int y = 0xff;
    int add = (c << (n << 3));
    int mask = (y << (n << 3));
    int clear = ~mask;
    x = x & clear;
    x = x | add;
    return x;
}
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x) {
    unsigned odd, mask2, pair2, mask3, four2, mask4, eight2, mask5, sixteen2;
    unsigned even = 0x55;
    unsigned pair = 0x33;
    unsigned four = 0x0f;
    unsigned eight = 0xff;
    unsigned sixteen = 0xff;
    unsigned mask = even << 8;
    even = mask | even;
    mask = even << 16;
    even = even | mask;
    odd = even << 1;
    even = even & x;
    odd = odd & x;
    even = even << 1;
    odd = odd >> 1;
    x = odd | even;
    mask2 = pair << 8;
    pair = mask2 | pair;
    mask2 = pair << 16;
    pair = pair | mask2;
    pair2 = pair << 2;
    pair = pair & x;
    pair2 = pair2 & x;
    pair = pair << 2;
    pair2 = pair2 >> 2;
    x = pair | pair2;
    mask3 = four << 8;
    four = mask3 | four;
    mask3 = four << 16;
    four = four | mask3;
    four2 = four << 4;
    four = four & x;
    four2 = four2 & x;
    four = four << 4;
    four2 = four2 >> 4;
    x = four | four2;
    mask4 = eight << 8;
    mask4 = mask4 << 8;
    eight = mask4 | eight;
    eight2 = eight << 8;
    eight = eight & x;
    eight2 = eight2 & x;
    eight = eight << 8;
    eight2 = eight2 >> 8;
    x = eight | eight2;
    mask5 = sixteen << 8;
    sixteen = mask5 | sixteen;
    sixteen2 = sixteen << 16;
    sixteen = sixteen & x;
    sixteen2 = sixteen2 & x;
    sixteen = sixteen << 16;
    sixteen2 = sixteen2 >> 16;
    x = sixteen | sixteen2;
    return x;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
    int overflow, same, ssign, overflowv, max, s;
    int min = 1;
    min = min << 31;
    max = ~min;
    s = x + y;
    x = (x >> 31);
    y = (y >> 31);
    ssign = (s >> 31);
    same = ~(x ^ y);
    overflow = (same & (x ^ ssign));
    overflowv = (overflow & ((ssign & max) | (~ssign & min))) | ((~overflow) & s);
    return overflowv;
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
    int frac, exp, mask;
    mask = 0x80000000;
    mask = mask & uf;
    exp = ((0x7f800000)& uf);
    frac = 0x7fffff;
    frac = frac & uf;
    if((exp == 0x7f800000 && frac != 0))
    {
        return uf;
    }
    else
    {
       mask = ~mask;
       uf = mask & uf;
       return uf; 
    }
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
    int E, M, bias, i;
    int V = 1;
    int two = 1;
    int sign = 0x80000000 & uf;
    int exp = ((0x7f800000)& uf)>>23;
    int frac = (0x7fffff & uf) >>23;
    bias = 127;
    if(exp == 0xff)
    {
        return 0x80000000u;
    }
    else if(exp == 0)
    {
        E = 1 - bias;
        M = frac;
    }
    else
    {
        E = (exp - bias);
        M = frac + 1;
    }
    for(i = 0; i < E && two > 0; i++)
    {
        two = two * 2;
    }
    for(i = E; i < 0; i++)
    {
        two = two/2;
    }
    V = two *(M);
    if(sign == 0x80000000)
    {
        V = ~V + 1;
    }
    return V;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
    int E, M, i;
    int half = 0x3f000000;
    int V = 1;
    int two = 1;
    int sign = 0x80000000 & uf;
    int exp = ((0x7f800000)& uf)>>23;
    int frac = ((0x7fffff & uf) >>23);
    int bias = 127;
    int halfsign = 0x80000000 & half;
    int halfE = (((0x7f800000)& half)>>23) - bias;
    int halfM = ((0x7fffff & half) >>23) + 1;
    
    if(exp == 0)
    {
        E = 1 - bias;
        M = frac;
    }
    else
    {
        E = (exp - bias);
        M = frac + 1;
    }
    E = E + halfE + bias;
    M = M * halfM;
    for(i = 0; i < E && two > 0; i++)
    {
        two = two * 2;
    }
    for(i = E; i < 0; i++)
    {
        two = two/2;
    }
    V = two *(M);
    sign = sign ^ halfsign;
    if(sign == 0x80000000)
    {
        V = ~V + 1;
    }
    return V;
}
