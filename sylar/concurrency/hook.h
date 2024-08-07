#pragma once

#include <time.h>		// for nanosleep
#include <unistd.h>		// for usleep
#include <sys/types.h>
#include <sys/socket.h>

namespace sylar {
namespace concurrency {

using sleep_libc_func_t = unsigned int (*)(unsigned int seconds);
extern sleep_libc_func_t sleep_libc_func;

using usleep_libc_func_t = int (*)(useconds_t usec);
extern usleep_libc_func_t usleep_libc_func;

using nanosleep_libc_func_t = int (*)(const struct timespec *req, struct timespec *rem);
extern nanosleep_libc_func_t nanosleep_libc_func;

using socket_libc_func_t = int (*)(int domain, int type, int protocol);
extern socket_libc_func_t socket_libc_func;

using fcntl_libc_func_t = int (*)(int fd, int cmd, ... /* arg */ );
extern fcntl_libc_func_t fcntl_libc_func;

using getsockopt_libc_func_t = int (*)(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
extern getsockopt_libc_func_t getsockopt_libc_func;

using setsockopt_libc_func_t = int (*)(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
extern setsockopt_libc_func_t setsockopt_libc_func;

using connect_libc_func_t = int (*)(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
extern connect_libc_func_t connect_libc_func;

using accept_libc_func_t = int (*)(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
extern accept_libc_func_t accept_libc_func;

using read_libc_func_t = ssize_t (*)(int fd, void *buf, size_t count);
extern read_libc_func_t read_libc_func;

using write_libc_func_t = ssize_t (*)(int fd, const void *buf, size_t count);
extern write_libc_func_t write_libc_func;




namespace this_thread {

/// @brief Enable/Disable hook on this thread
void EnableHook(bool on);

/// @brief Get the flag that this thread whether hooked
bool IsHooded();

} // namespace this_thread
} // namespace concurrency
} // namespace sylar
