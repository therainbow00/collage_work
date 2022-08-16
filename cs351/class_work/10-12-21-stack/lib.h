%define SYS_read	0
%define SYS_write	1
%define SYS_open	2
%define SYS_close	3
%define SYS_stat	4
%define SYS_exit	60
%define SYS_getrandom	318

%define STDIN_FILENO	0
%define STDOUT_FILENO	1
%define STDERR_FILENO	2

; Flags for use with getrandom:
%define GRND_NONBLOCK	0x01
%define GRND_RANDOM	0x02
%define GRND_INSECURE	0x04
