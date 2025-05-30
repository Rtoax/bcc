/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */
#ifndef __OPENSNOOP_H
#define __OPENSNOOP_H

#define TASK_COMM_LEN 16
#define NAME_MAX 255
#define INVALID_UID ((uid_t)-1)

#define MAX_PATH_DEPTH 32

struct event {
	pid_t pid;
	enum {
		DATA_ALLOC,
		DATA_SUBMIT,
	} type;
};

struct data {
	/* user terminology for pid: */
	__u64 ts;
	pid_t pid;
	uid_t uid;
	int ret;
	int flags;
	__u32 mode;
	__u64 callers[2];
	char comm[TASK_COMM_LEN];
	char fname[NAME_MAX * MAX_PATH_DEPTH];
};

#endif /* __OPENSNOOP_H */
