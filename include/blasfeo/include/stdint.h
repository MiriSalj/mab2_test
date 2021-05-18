/* Copyright (C) 1997,1998,1999,2000,2001,2006 Free Software Foundation, Inc.
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
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	ISO C99: 7.18 Integer types <stdint.h>
 */

#ifndef _STDINT_H
#define _STDINT_H	1

//#include <features.h>
//#include <bits/wchar.h>
//#include <bits/wordsize.h>

/* Exact integral types.  */

/* Signed.  */

/* There is some amount of overlap with <sys/types.h> as known by inet code */
#ifndef __int8_t_defined
# define __int8_t_defined
typedef signed char		int8_t;
typedef short int		int16_t;
typedef int			int32_t;
#endif

/* Unsigned.  */
#ifndef __uint8_t_defined
  typedef unsigned char		uint8_t;
# define __uint8_t_defined
#endif

#ifndef __uint16_t_defined
  typedef unsigned short int	uint16_t;
# define __uint16_t_defined
#endif

#ifndef __uint32_t_defined
  typedef unsigned int		uint32_t;
# define __uint32_t_defined
#endif


/* Small types.  */

/* Signed.  */
typedef signed char		int_least8_t;
typedef short int		int_least16_t;
typedef int			int_least32_t;

/* Unsigned.  */
typedef unsigned char		uint_least8_t;
typedef unsigned short int	uint_least16_t;
typedef unsigned int		uint_least32_t;


/* Types for `void *' pointers.  */
#if __WORDSIZE == 64
# ifndef __intptr_t_defined
typedef long int		intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned long int	uintptr_t;
#else
# ifndef __intptr_t_defined
typedef int			intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned int		uintptr_t;
#endif

#endif /* stdint.h */
