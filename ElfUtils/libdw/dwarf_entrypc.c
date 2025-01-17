/* Return entry PC attribute of DIE.
   Copyright (C) 2003, 2005 Red Hat, Inc.
   This file is part of elfutils.

   This file is free software; you can redistribute it and/or modify
   it under the terms of either

     * the GNU Lesser General Public License as published by the Free
       Software Foundation; either version 3 of the License, or (at
       your option) any later version

   or

     * the GNU General Public License as published by the Free
       Software Foundation; either version 2 of the License, or (at
       your option) any later version

   or both in parallel, as here.

   elfutils is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received copies of the GNU General Public License and
   the GNU Lesser General Public License along with this program.  If
   not, see <http://www.gnu.org/licenses/>.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <dwarf.h>
#include "libdwP.h"


int
dwarf_entrypc (Dwarf_Die *die, Dwarf_Addr *return_addr)
{
  Dwarf_Attribute attr_mem;

	Dwarf_Attribute *attr = INTUSE(dwarf_attr) (die, DW_AT_entry_pc,
							&attr_mem);
  return INTUSE(dwarf_formaddr) (attr
				 ?attr: INTUSE(dwarf_attr) (die, DW_AT_low_pc,
							&attr_mem),
				 return_addr);
}
INTDEF(dwarf_entrypc)
