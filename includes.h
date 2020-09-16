/*
 * includes.h
 *
 *  Created on: Dec 21, 2016
 *      Author: zjm09
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <sys/types.h>       /* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>     /* for winsize */
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/sysinfo.h>
#include <stdio.h>     /* for convenience */
#include <stdlib.h>    /* for convenience */
#include <stdint.h>
#include <stddef.h>    /* for offsetof */
#include <string.h>    /* for convenience */
#include <unistd.h>    /* for convenience */
#include <signal.h>    /* for SIG_ERR */
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <getopt.h>
#include <libgen.h>
#include <inttypes.h>

#include <assert.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <net/route.h>
#include <netinet/in.h>

#include <semaphore.h>
#include <pthread.h>

#include <sqlite3.h>

#endif /* INCLUDES_H_ */
