#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    pipe(pipefd);
    pid = fork();
    if (pid == 0) { // Child process
        close(pipefd[1]); // Close the write end
        char buffer[100];
        read(pipefd[0], buffer, 100);
        printf("Child: %s\n", buffer);
        close(pipefd[0]);
    } else { // Parent process
        close(pipefd[0]); // Close the read end
        write(pipefd[1], "Parent Message!", 16);
        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}

/*
                     Pipe
                 -------------
                 |           |
Parent  <---r--- |           | ---r--> Child
Process ----w--> |           | <--w--- Process
                 |           |
                 -------------

r: read  --> pipefd[0];
w: write --> pipefd[1];

So, in line 19, where the parent process first accesses and modifies `pipefd`
we have a COW incident, i.e., the child process creates a local copy of
`pipefd`. So, assume that pipefd == [ 123, 456 ].

When the parent tries to modify pipefd, a new copy is created for the child:

```
Parent copy: pipefd == [ 123, 456 ]
                          o    o      // o: open, c: closed

Child  copy: pipefd == [ 123, 456 ]
                          o    o     // o: open, c: closed
```

After line 19 has executed, the situation looks roughly like this:

```
Parent copy: pipefd == [ 123, 456 ]
                          c    o      // o: open, c: closed

Child  copy: pipefd == [ 123, 456 ]
                          o    o     // o: open, c: closed
```
So, in Figures, this is what happens:

0. Initial state:

Parent close their read end: line 19: close(pipefd[0]);

```
                     Pipe
                 -------------
                 |           |
Parent  <---r--- |           | ---r--> Child
Process ----w--> |           | <--w--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```

1. Parent closes their read end: line 19: close(pipefd[0]);

```
                     Pipe
                 -------------
                 |           |
Parent  <---nr-- |           | ---r--> Child
Process ----w--> |           | <--w--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```

2. Parent writes (they still can): line 20: write(pipefd[1], "Parent Message!", 16);

```
                     Pipe
                 -------------
                 | "Parent   |
Parent  <---nr-- | Message"  | ---r--> Child
Process ----w--> |           | <--w--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```

3. Parent closes their write end: line 21: close(pipefd[1]);

```
                     Pipe
                 -------------
                 | "Parent   |
Parent  <---nr-- | Message"  | ---r--> Child
Process ---nw--> |           | <--w--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```
4. The parent then waits for the child.

5. The child process closes its write end: line 13: close(pipefd[1]);

```
                     Pipe
                 -------------
                 | "Parent   |
Parent  <---nr-- | Message"  | ---r--> Child
Process ---nw--> |           | <-nw--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```

6. Child reads the pipe: line 15: read(pipefd[0], buffer, 100);

```
                     Pipe
                 -------------
                 | "Parent   |
Parent  <---nr-- | Message"  | ---r--> Child    --> Read "Parent Message"
Process ---nw--> |           | <-nw--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```

7. Child closes its own read end: line 17: close(pipefd[0]);

```
                     Pipe
                 -------------
                 | "Parent   |
Parent  <---nr-- | Message"  | --nr--> Child    --> Read "Parent Message"
Process ---nw--> |           | <-nw--- Process
                 |           |
                 -------------
// nr: no read, nw: no write, r: read, w: write
```

*/