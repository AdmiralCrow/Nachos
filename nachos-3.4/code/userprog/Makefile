# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the multiprogramming assignment
#    Defines set up assuming multiprogramming is done before the file system.
#    If not, use the "filesys first"  defines below. 
#
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS_STUB
INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H)
CFILES = $(THREAD_C) $(USERPROG_C)
C_OFILES = $(THREAD_O) $(USERPROG_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS
# INCPATH = -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/pcb.h ../threads/list.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/synch.h ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
list.o: ../threads/list.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
scheduler.o: ../threads/scheduler.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/scheduler.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 /usr/include/c++/4.8.2/map /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/system.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
synch.o: ../threads/synch.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synch.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 /usr/include/c++/4.8.2/map /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h ../userprog/memorymanager.h ../userprog/pcbmanager.h
synchlist.o: ../threads/synchlist.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synchlist.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/pcb.h ../threads/list.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/synch.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h
system.o: ../threads/system.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
thread.o: ../threads/thread.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/thread.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/pcb.h \
 ../threads/list.h ../userprog/pcbmanager.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../threads/synch.h ../threads/list.h \
 /usr/include/c++/4.8.2/map /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/switch.h \
 ../threads/synch.h ../threads/system.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../userprog/pcbmanager.h
utility.o: ../threads/utility.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/stdarg.h
semaphore_ping.o: ../threads/semaphore_ping.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
lockTest.o: ../threads/lockTest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
ping.o: ../threads/ping.cc /usr/include/stdc-predef.h
threadtest.o: ../threads/threadtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
interrupt.o: ../machine/interrupt.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/interrupt.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/pcb.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
sysdep.o: ../machine/sysdep.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h \
 /usr/include/xlocale.h /usr/include/sys/types.h /usr/include/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h \
 /usr/include/string.h /usr/include/signal.h /usr/include/bits/signum.h \
 /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h \
 /usr/include/bits/sigcontext.h /usr/include/bits/sigstack.h \
 /usr/include/sys/ucontext.h /usr/include/bits/sigthread.h \
 /usr/include/sys/time.h /usr/include/sys/socket.h /usr/include/sys/uio.h \
 /usr/include/bits/uio.h /usr/include/bits/socket.h \
 /usr/include/bits/socket_type.h /usr/include/bits/sockaddr.h \
 /usr/include/asm/socket.h /usr/include/asm-generic/socket.h \
 /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h \
 /usr/include/sys/file.h /usr/include/fcntl.h /usr/include/bits/fcntl.h \
 /usr/include/bits/fcntl-linux.h /usr/include/linux/falloc.h \
 /usr/include/bits/stat.h /usr/include/sys/un.h /usr/include/sys/mman.h \
 /usr/include/bits/mman.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../userprog/pcbmanager.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../threads/synch.h ../threads/list.h \
 /usr/include/c++/4.8.2/map /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
stats.o: ../machine/stats.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/stats.h
timer.o: ../machine/timer.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/timer.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/pcb.h ../threads/list.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/synch.h ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
elevator.o: ../threads/elevator.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h \
 ../threads/elevator.h
ElevatorTest.o: ../threads/ElevatorTest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h \
 ../threads/elevator.h
addrspace.o: ../userprog/addrspace.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h \
 ../userprog/addrspace.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h
memorymanager.o: ../userprog/memorymanager.cc /usr/include/stdc-predef.h \
 ../userprog/memorymanager.h ../userprog/bitmap.h ../threads/copyright.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h
pcbmanager.o: ../userprog/pcbmanager.cc /usr/include/stdc-predef.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../threads/copyright.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h ../userprog/pcb.h \
 ../threads/list.h ../threads/utility.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/synch.h \
 ../threads/list.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h
pcb.o: ../userprog/pcb.cc /usr/include/stdc-predef.h ../userprog/pcb.h \
 ../threads/list.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/pcbmanager.h ../userprog/bitmap.h \
 ../threads/utility.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h
exception.o: ../userprog/exception.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h \
 ../userprog/syscall.h
progtest.o: ../userprog/progtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../userprog/pcbmanager.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/synch.h \
 ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h \
 ../machine/console.h ../userprog/addrspace.h
console.o: ../machine/console.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/console.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/pcb.h ../threads/list.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/synch.h ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
machine.o: ../machine/machine.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/pcb.h ../threads/list.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/synch.h ../threads/list.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
mipssim.o: ../machine/mipssim.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../machine/mipssim.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/pcb.h \
 ../threads/list.h ../userprog/pcbmanager.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../threads/synch.h ../threads/list.h \
 /usr/include/c++/4.8.2/map /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../userprog/memorymanager.h ../threads/synch.h ../userprog/pcbmanager.h
translate.o: ../machine/translate.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/pcb.h ../threads/list.h ../threads/utility.h \
 ../userprog/pcbmanager.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/synch.h ../threads/list.h ../threads/thread.h \
 ../machine/machine.h /usr/include/c++/4.8.2/map \
 /usr/include/c++/4.8.2/bits/stl_tree.h \
 /usr/include/c++/4.8.2/bits/stl_algobase.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++config.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/os_defines.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/cpu_defines.h \
 /usr/include/c++/4.8.2/bits/functexcept.h \
 /usr/include/c++/4.8.2/bits/exception_defines.h \
 /usr/include/c++/4.8.2/bits/cpp_type_traits.h \
 /usr/include/c++/4.8.2/ext/type_traits.h \
 /usr/include/c++/4.8.2/ext/numeric_traits.h \
 /usr/include/c++/4.8.2/bits/stl_pair.h \
 /usr/include/c++/4.8.2/bits/move.h \
 /usr/include/c++/4.8.2/bits/concept_check.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.8.2/debug/debug.h \
 /usr/include/c++/4.8.2/bits/stl_iterator.h \
 /usr/include/c++/4.8.2/bits/allocator.h \
 /usr/include/c++/4.8.2/x86_64-redhat-linux/32/bits/c++allocator.h \
 /usr/include/c++/4.8.2/ext/new_allocator.h /usr/include/c++/4.8.2/new \
 /usr/include/c++/4.8.2/exception \
 /usr/include/c++/4.8.2/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.8.2/bits/memoryfwd.h \
 /usr/include/c++/4.8.2/bits/stl_function.h \
 /usr/include/c++/4.8.2/backward/binders.h \
 /usr/include/c++/4.8.2/bits/stl_map.h \
 /usr/include/c++/4.8.2/bits/stl_multimap.h \
 /usr/include/c++/4.8.2/bits/range_access.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h ../userprog/memorymanager.h ../threads/synch.h \
 ../userprog/pcbmanager.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
