to change date 
use touch -d for changing date
touch [file] -d 2023-11-06

ls -lRa *MaRV*      
-l is long === -R is recursive... -a is for all so do not ignore entries starting with ,  

a abs macro wth ternary
#define ABS(Value) (Value < 0 ? ((Value * (-1))) : Value)

with bit shifting
https://stackoverflow.com/a/12041874
Let's assume a twos-complement number (as it's the usual case and you don't say otherwise) and let's assume 32-bit:

First, we perform an arithmetic right-shift by 31 bits. This shifts in all 1s for a negative number or all 0s for a positive one (but note that the actual >>-operator's behaviour in C or C++ is implementation defined for negative numbers, but will usually also perform an arithmetic shift, but let's just assume pseudocode or actual hardware instructions, since it sounds like homework anyway):

mask = x >> 31;

So what we get is 111...111 (-1) for negative numbers and 000...000 (0) for positives

Now we XOR this with x, getting the behaviour of a NOT for mask=111...111 (negative) and a no-op for mask=000...000 (positive):

x = x XOR mask;

And finally subtract our mask, which means +1 for negatives and +0/no-op for positives:

x = x - mask;

So for positives we perform an XOR with 0 and a subtraction of 0 and thus get the same number. And for negatives, we got (NOT x) + 1, which is exactly -x when using twos-complement representation.

#define ABS(V) ((V ^ (V >> 31)) - (V >> 31))

norminette -R CheckDefine 
this is for the header check

MAKEFILE
The -fpic or -fPIC flags can be used to generate position-independent code. -fPIC is guaranteed to generate working code, but the code is slower on m68k, m88k, and SPARC chips.


Linux only allows you to make hard links to files, not directories. So for directories, always use symbolic links, since you don't have a choice.

ln -s /<path to file/folder to be linked> <path of the link to be created>

ln is the link command. The –s flag specifies that the link should be soft. –s can also be entered as –symbolic. Please note, ln command creates hard links by default. 



List Currently Defined Aliases in Linux

You can see a list of defined aliases on your profile by simply executing the alias command.

$ alias

Here you can see the default aliases defined for your user in the Ubuntu system.

Creating Permanent Aliases in Linux

To keep aliases between sessions, you can save them in your user’s shell configuration profile file. This can be:

    Bash – ~/.bashrc
    
alias ll="ls -alF"

while "shell" is a broad term that refers to any program that provides a command-line interface, "Bash" is a specific type of shell that is widely used in Unix/Linux systems. 

sh (or the Shell Command Language) is a programming language described by the POSIX standard. It has many implementations (ksh88, Dash, ...). Bash can also be considered an implementation of sh (see below).

Because sh is a specification, not an implementation, /bin/sh is a symlink (or a hard link) to an actual implementation on most POSIX systems.
What is Bash?

Bash started as an sh-compatible implementation (although it predates the POSIX standard by a few years), but as time passed it has acquired many extensions. Many of these extensions may change the behavior of valid POSIX shell scripts, so by itself Bash is not a valid POSIX shell. Rather, it is a dialect of the POSIX shell language.

Bash supports a --posix switch, which makes it more POSIX-compliant. It also tries to mimic POSIX if invoked as sh.

https://stackoverflow.com/questions/5725296/difference-between-sh-and-bash

Shebang line

Ultimately, it's up to you to decide which one to use, by writing the «shebang» line as the very first line of the script.

E.g.

#!/bin/sh

will use sh (and whatever that happens to point to),

#!/bin/bash

will use /bin/bash if it's available (and fail with an error message if it's not). Of course, you can also specify another implementation, e.g.

#!/bin/dash
Which one to use

For my own scripts, I prefer sh for the following reasons:

    it is standardized
    it is much simpler and easier to learn
    it is portable across POSIX systems — even if they happen not to have bash, they are required to have sh

There are advantages to using bash as well. Its features make programming more convenient and similar to programming in other modern programming languages. These include things like scoped local variables and arrays. Plain sh is a very minimalistic programming language.

https://man.cx/sh

dash is the Debian Almquist shell: a small, fast, and POSIX compliant shell. It is well-suited for startup scripts, and is used on Debian (and derivative distributions) as /bin/sh.

to see what shell i have
file -h /bin/sh

https://kb.iu.edu/d/aeee
To determine your shell, enter:

echo $SHELL

Use source (or its shortcut . ) to reprocess the initialization files in your home directory:
source ~/.zshrc

Effectively, a hard link gives you two, separate files that behave like different files. But it's better that you don't think of a hard link as a copy. Because there's an exception to the idea that they behave like separate files: if you make a change to File 1, File 2 will automatically be edited. That happens because they're two separate files, but they're pointing to the exact same spot on the hard drive.
But there's a very important functional difference between soft links and hard links. Because a soft link points to the original file, if you delete File 1, File 2 will be completely useless, because it's going to be pointing to something that doesn't exist.

On the contrary, if you're working with hard links, which act as separate files that point to the same data on the hard drive and delete the original File 1, File 2 is still perfectly viable. File 2 keeps on pointing to the same spot on the hard drive where the data is stored.

Delete a hard linked file and the data remains intact. But with a symbolic link, if you delete the original file, the symbolic link is rendered useless.

Symbolic links have lrwxrwxrwx permissions, which are default permissions for symbolic links and cannot be changed. While lrwxrwxrwx permissions usually mean maximum allowable permissions in Linux, it is a dummy permission as symbolic links inherit the permissions of the file to which it links.


my makefile

CFLAGS=-Wall -Wextra -Werror

SOURCES=$(wildcard srcs/*.c)
OBJECTS=$(patsubst %c,%o,$(SOURCES))

TARGET=libft.a

# the target build
all: $(TARGET)

$(TARGET): $(OBJECTS) 
	ar rcs $@ $(OBJECTS)
	ranlib $@

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all


==================
If the target is an archive member, then ' $@ ' is the name of the archive file. In a pattern rule that has multiple targets (see Introduction to Pattern Rules), ' $@ ' is the name of whichever target caused the rule's recipe to be run.

$<

    The name of the first prerequisite. If the target got its recipe from an implicit rule, this will be the first prerequisite added by the implicit rule (see Using Implicit Rules). 


The first is that error messages are best directed to the stderr device. It’s the ugly stepsister of the C language device constants, running a distant third to stdin (standard input) and stdout (standard output).

The reason for the stderr (standard error output) device is to ensure that a program’s output isn’t redirected to another device. The output to stderr is always sent to the console (the screen) regardless of what other I/O manipulation is taking place outside the program. Bottom line:

Always send error messages to the stderr device.

https://c-for-dummies.com/blog/?p=1740


ex00: KO | ex01: OK | ex02: KO | ex03: KO | ex04: OK | ex05: OK | ex06: Cheating | ex07: Cheating | ex08: Cheating | ex09: OK | ex10: OK | ex11: OK | ex12: OK | ex13: OK | ex14: OK | ex15: Cheating | ex16: OK | ex17: OK | ex18: Cheating | ex19: Cheating | ex20: OK | ex21: OK | ex22: OK | ex23: Does not compile | ex24: OK | ex25: OK | ex26: OK | ex27: Cheating

https://stackoverflow.com/questions/14189944/unix-system-file-tables

https://en.wikipedia.org/wiki/Open_%28system_call%29

 Some GNU programs (at least df, du, and ls) display sizes in "blocks". You can adjust the block size and method of display to make sizes easier to read. The block size used for display is independent of any filesystem block size. Fractional block counts are rounded up to the nearest integer.

The default block size is chosen by examining the following environment variables in turn; the first one that is set determines the block size.

DF_BLOCK_SIZE
    This specifies the default block size for the df command. Similarly, DU_BLOCK_SIZE specifies the default for du and LS_BLOCK_SIZE for ls.

BLOCK_SIZE
    This specifies the default block size for all three commands, if the above command-specific environment variables are not set.

POSIXLY_CORRECT
    If neither the command_BLOCK_SIZE nor the BLOCK_SIZE variables are set, but this variable is set, the block size defaults to 512.

If none of the above environment variables are set, the block size currently defaults to 1024 bytes in most contexts, but this number may change in the future. For ls file sizes, the block size defaults to 1 byte. 


find . -path ".*~"

basename 
https://superuser.com/questions/559824/how-to-get-only-names-from-find-command-without-path
find . -name "*.sh" -exec basename \{} .sh \; 
https://en.wikipedia.org/wiki/Basename
basename is a standard computer program on Unix and Unix-like operating systems. When basename is given a pathname, it will delete any prefix up to the last slash ('/') character and return the result. basename is described in the Single UNIX Specification and is primarily used in shell scripts.  intoduced in 1987
basename will retrieve the last name from a pathname ignoring any trailing slashes

$ basename /home/jsmith/base.wiki 
base.wiki

$ basename /home/jsmith/
jsmith

basename can also be used to remove the end of the base name, but not the complete base name

$ basename /home/jsmith/base.wiki .wiki
base


======  MAkefile flags
-fPIC flag when compiling libs is only for dynamic ones
PIC stands for Position Independent Code.

To quote man gcc:

If supported for the target machine, emit position-independent code, suitable for dynamic linking and avoiding any limit on the size of the global offset table. This option makes a difference on AArch64, m68k, PowerPC and SPARC.
Use this when building shared objects (*.so) on those mentioned architectures.

The rule of thumb:

When you need to debug, use -O0 (and -g to generate debugging symbols.)

When you are preparing to ship it, use -O2.

When you use gentoo, use -O3...!

When you need to put it on an embedded system, use -Os (optimize for size, not for efficiency.)


According to the man page for ranlib, it is "completely equivalent to executing ar -s". I believe the above can be simplified to one line: ar rcs libfoo.a foo.o foo2.o ...

Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag.  Sbe
rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe
gur arkg pvepyr.  Guvf punyyratr vf vaqvivqhny, gurer vf bayl n
cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf.  Nal
nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur
cevmr jvyy erznva flzobyvp.  Gur uvag sbe guvf svefg cebwrpg vf:
Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl
hccre tenivgl ureb
Each project of the 97 Common Core contains an encoded hint.  For
each circle, only one project provides the correct hint needed for
the next circle.  This challenge is individual, there is only a
prize for one student winner providing all decoded messages.  Any
advantaged people can play, like current or former staff, but the
prize will remain symbolic.  

The hint for this first project is:
Large cows generosity comes with charts and four blonde hats to defy
upper gravity hero


x86-64 and aarch64 (arm64) Linux, OS X and iOS all have size_t ultimately defined as unsigned long. (This is the LP64 model. This kind of thing is part of the platform's ABI which also defines things like function calling convention, etc. Other architectures may vary.) Even 32-bit x86 and ARM architectures use unsigned long on these OSes, although long happens to be the same representation as an int in those cases.

I'm fairly sure it's an unsigned __int64/unsigned long long on Win64. (which uses the LLP64 model)
https://stackoverflow.com/a/33585153/9497800

#ifndef __SIZE_T
# define __SIZE_T
typedef unsigned long size_t;
#endif
https://stackoverflow.com/questions/63464078/define-size-t-and-typedef-unsigned-int-size-t


check if strings overlap in mem
https://stackoverflow.com/questions/4023320/how-to-implement-memmove-in-standard-c-without-an-intermediate-copy

#memmove
https://stackoverflow.com/questions/43507854/memmove-is-overlapping
memmove allows the source and destination to have an overlapping region, and it is defined so that the contents of the source before memmove will compare equal to contents of the destination after the memmove.

If the source and destination overlap, you will expect the source to have changed in some way after the memmove call. What is prevented is the possible corruption of destination.

The behavior of memmove(dst, src, len) will be similar to:

char buf[len];
memcpy(buf, src, len);
memcpy(dst, buf, len);


#strlcpy
You're returning the length of the resulting string, not the length it would have been without the len limit.

Save strlen(src) in a variable and return that at the end.

size_t ft_strlcpy(char *dst, const char *src, size_t len)
{
  size_t l = strlen(src);
  size_t i = 0;

  while (i < len - 1 && *src != '\0')
  {
      *dst++ = *src++;
      i++;
  }
  *dst = '\0';
  return l;
}
Also, the len parameter and the return type should be size_t.

 Like snprintf(3), the strlcpy() and strlcat() functions return the total
     length of the string they tried to create.  For strlcpy() that means the
     length of src.  For strlcat() that means the initial length of dst plus
     the length of src.

     If the return value is >= dstsize, the output string has been truncated.
     It is the caller's responsibility to handle this.


snprintf? return the number of characters that would have
     been printed if the size were unlimited
     These functions return a
     negative value if an error occurs.?
     
     https://opensource.apple.com/source/Libc/Libc-825.26/string/strlcat.c.auto.html
size_t
strlcat(char * restrict dst, const char * restrict src, size_t maxlen) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, maxlen);
    if (dstlen == maxlen) return maxlen+srclen;
    if (srclen < maxlen-dstlen) {
        memcpy(dst+dstlen, src, srclen+1);
    } else {
        memcpy(dst+dstlen, src, maxlen-1);
        dst[dstlen+maxlen-1] = '\0';
    }
    return dstlen + srclen;
}     
