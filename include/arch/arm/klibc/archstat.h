#ifndef _KLIBC_ARCHSTAT_H
#define _KLIBC_ARCHSTAT_H

#include <klibc/stathelp.h>

#define _STATBUF_ST_NSEC

/* This matches struct stat64 in glibc2.1, hence the absolutely
 * insane amounts of padding around dev_t's.
 * Note: The kernel zero's the padded region because glibc might read them
 * in the hope that the kernel has stretched to using larger sizes.
 */

struct stat {
	__stdev64	(st_dev);
	unsigned char   __pad0[4];

	unsigned long	__st_ino;
	unsigned int	st_mode;
	unsigned int	st_nlink;

	unsigned long	st_uid;
	unsigned long	st_gid;

	__stdev64	(st_rdev);
	unsigned char   __pad3[4];

	long long	st_size;
	unsigned long	st_blksize;

	unsigned long long  st_blocks;	/* Number 512-byte blocks allocated. */

	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;

	unsigned long long	st_ino;
};

#endif
