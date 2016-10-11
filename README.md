__FT_LS__ [![Build Status](https://travis-ci.com/MajorTom327/ft_ls.svg?token=C3h4xYsmzkw5o5KZ5yAM&branch=master)](https://travis-ci.com/MajorTom327/ft_ls)
=========
--------------------------------------------------------------------------------
Educational Project
-------------------
ft_ls is a educational project about reproduction of ls and somes of his arguments.

--------------------------------------------------------------------------------
Implemented Argument (subject):
-------------------------------

- a: Include directory entries whose names begin with a dot (.).

- l: (The lowercase letter ''ell''.)  List in long format.  (See below.)  If the output is to a terminal, a total sum for all the file sizes is output on a line before the long listing.

- r: Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size

- R: Recursively list subdirectories encountered.

- t: Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.


Implemented Bonus:
------------------
- f: Output is not sorted.  This option turns on the -a option

- F: Display a slash ('/') immediately after each pathname that is a directory, an asterisk ('\*') after each that is executable, an at sign ('@') after each symbolic link, an equals sign ('=') after each socket, a percent sign ('%') after each whiteout, and a vertical bar ('|') after each that is a FIFO.

- g: This option is only available for compatibility with POSIX; it is used to display the group name in the long (-l) format output (the owner name is suppressed).

- G: show output with color

- i: For each file, print the file's file serial number (inode number).

- m: Stream output format; list files across the page, separated by commas.

- n: Display user and group IDs numerically, rather than converting to a user or group name in a long (-l) output.  This option turns on the -l option.

- O: Include the file flags in a long (-l) output.

- s: Display the number of file system blocks actually used by each file, in units of 512 bytes, where partial units are rounded up to the next integer value.  If the output is to a terminal, a total sum for all the file sizes is output on a line before the listing.  The environment variable BLOCKSIZE overrides the unit size of 512 bytes.

- u: Use time of last access, instead of last modification of the file for sorting (-t) or long printing (-l).

How it's working:
-----------------
> $> ./ft_ls [-afFgGilmnOrRstu] [directory ...]
