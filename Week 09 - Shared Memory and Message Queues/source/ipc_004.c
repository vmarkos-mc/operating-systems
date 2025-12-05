// source/ipc_004.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd_in, fd_out;
    char buffer[1024];
    int bytes_read;
    fd_in = open("input.txt", O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        exit(1);
    }
    fd_out = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd_out == -1) {
        perror("open");
        exit(1);
    }
    while ((bytes_read = read(fd_in, buffer, sizeof(buffer))) > 0) {
        write(fd_out, buffer, bytes_read);
    }
    close(fd_in);
    close(fd_out);
    return 0;
}

/*
Explaining lines 21-23:
* read(int file_descriptor, char* buf, size_t size):
    * this reads some bytes, if any, from a file descriptor (i.e., a thing that handles files).
      and "pastes" then into a character array (buf). The total size of the sequence read is `size`.
    * read() typically returns the number of bytes read.
* So, so long as we read more than 0 bytes, it means we have actually read something new, so, we write 
  it into another file.
* write(int file_descriptor, char* buf, size_t size):
    * writes `size_t` from the contents of `buf` into the file descriptor.
*/