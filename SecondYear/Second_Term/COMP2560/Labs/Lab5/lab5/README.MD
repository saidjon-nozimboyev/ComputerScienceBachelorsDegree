## 1. Files Included

The submission contains the following files:

- `writer.c` – Writer program for Parts 1 and 2.
- `reader.c` – Reader program for Parts 1 and 2.
- `client.c` – Client program for bidirectional communication.
- `server.c` – Server program for bidirectional communication.
- `README.md` – Compilation instructions, execution steps, testing details, and discussion answers.

---

# 2. Compilation Instructions

All programs were compiled in a Linux environment using GCC.

The following commands were used:

```bash
gcc -Wall -Wextra -std=c11 -pedantic writer.c -o writer

gcc -Wall -Wextra -std=c11 -pedantic reader.c -o reader

gcc -Wall -Wextra -std=c11 -pedantic client.c -o client

gcc -Wall -Wextra -std=c11 -pedantic server.c -o server
```

All four programs compiled successfully without errors or warnings.

After compilation, the following executable files were generated:

- `writer`
- `reader`
- `client`
- `server`

## Important Note About FIFO Paths

During testing on the shared Linux environment, an existing FIFO at `/tmp/lab_fifo` was found to belong to another user. Its permissions prevented access and caused a permission error.

To avoid interfering with another user's files, a custom FIFO path was used for Parts 1 and 2.

The custom FIFO path is:

```c
/tmp/comp2560_lab5_nozimbo_fifo
```

Both `writer.c` and `reader.c` use exactly the same FIFO path.

The FIFO definition in both programs is:

```c
#define FIFO_PATH "/tmp/comp2560_lab5_nozimbo_fifo"
```

This path must remain identical in both files.

For Parts 3 and 4, the following two FIFO paths are used:

- `/tmp/fifo_client_to_server`
- `/tmp/fifo_server_to_client`

These paths must also match between the client and server programs.

---

# 3. Part 1 – Basic Named Pipe Communication

## Exercise 1.1 – Writer

The writer creates a named pipe using `mkfifo()` and sends a message through it.

The writer was compiled using:

```bash
gcc -Wall -Wextra -std=c11 -pedantic writer.c -o writer
```

To execute the writer in one-time communication mode:

```bash
./writer --once
```

The writer creates the FIFO if it does not already exist, opens it for writing, sends the message, and closes the file descriptor.

The message sent is:

```text
Hello from writer!
```

## Exercise 1.2 – Reader

The reader was compiled using:

```bash
gcc -Wall -Wextra -std=c11 -pedantic reader.c -o reader
```

To execute the reader in one-time communication mode:

```bash
./reader --once
```

The reader opens the FIFO, reads the message, null-terminates the buffer, displays the received message, and closes the file descriptor.

Expected output:

```text
Received: Hello from writer!
```

## Testing Writer First

Two terminals were used for this test.

Terminal 1:

```bash
./writer --once
```

Terminal 2:

```bash
./reader --once
```

The writer was started first and waited until the reader connected.

The reader successfully received:

```text
Received: Hello from writer!
```

## Testing Reader First

The lab also requires testing what happens when the reader starts before the writer.

Since the writer removes the FIFO after completing its one-time communication when it created it, the FIFO was manually created before starting the reader.

First, the FIFO was created:

```bash
mkfifo /tmp/comp2560_lab5_nozimbo_fifo
```

Terminal 1:

```bash
./reader --once
```

Terminal 2:

```bash
./writer --once
```

The reader waited until the writer connected and successfully received:

```text
Received: Hello from writer!
```

The FIFO was cleaned up after the test:

```bash
rm -f /tmp/comp2560_lab5_nozimbo_fifo
```

Both startup orders were tested successfully.

---

# 4. Part 2 – Multiple Messages

Part 2 modifies the writer and reader programs to support continuous communication using keyboard input.

The writer repeatedly accepts messages from the user and sends them through the FIFO.

The reader continuously receives messages and displays them.

## Execution Steps

First, the reader was started in Terminal 1:

```bash
./reader
```

Then, the writer was started in Terminal 2:

```bash
./writer
```

The writer accepted messages from the keyboard.

The following messages were used during testing:

```text
Hello
How are you?
I am testing Part 2
This is COMP 2560
exit
```

Expected reader output:

```text
Received: Hello
Received: How are you?
Received: I am testing Part 2
Received: This is COMP 2560
Received: exit
```

When the writer sends `exit`, both programs terminate.

Newline-terminated strings are used to separate messages because a FIFO is a byte stream rather than a message queue.

The reader handles incoming data and separates complete lines instead of assuming that every `read()` call corresponds to one complete message.

Multiple-message communication was tested successfully.

---

# 5. Part 3 – Bidirectional Communication

## Exercise 3.1 – Request-Response Chat

Part 3 implements communication between two independent processes using two named pipes.

The two FIFO paths are:

```text
/tmp/fifo_client_to_server
/tmp/fifo_server_to_client
```

The first FIFO transfers messages from the client to the server.

The second FIFO transfers replies from the server to the client.

The communication uses a turn-based request-response protocol.

The client sends a message first and waits for the server's reply. The server waits for a request before responding.

## Compilation

The server was compiled using:

```bash
gcc -Wall -Wextra -std=c11 -pedantic server.c -o server
```

The client was compiled using:

```bash
gcc -Wall -Wextra -std=c11 -pedantic client.c -o client
```

## Execution Steps

The server must be started first.

Terminal 1:

```bash
./server
```

The server displays:

```text
Server ready. Waiting for client...
```

Then, the client was started in Terminal 2:

```bash
./client
```

The client connects to the server and allows the user to enter messages.

## Communication Test

The following messages were used to test communication:

Client:

```text
Hello server
```

Server:

```text
Client: Hello server
Reply:
```

The server replied:

```text
Hello client!
```

The client displayed:

```text
Server: Hello client!
```

A second exchange was also tested:

Client:

```text
How are you?
```

Server:

```text
I am doing well!
```

The client successfully received the server's reply.

## Termination Test

The client sent:

```text
exit
```

The server received the exit request, sent its goodbye response, and both programs terminated.

Bidirectional communication and normal termination were tested successfully.

---

# 6. Part 4 – Error Handling and Cleanup

Part 4 improves the client and server programs by checking system call errors and handling unexpected process termination.

The implementation includes error checking for relevant operations, including:

- `mkfifo()`
- `open()`
- `read()`
- `write()`
- `close()`
- `unlink()`

The programs also handle unexpected peer termination, including `read()` returning zero when the other process closes its writing end.

Open file descriptors are closed when they are no longer needed.

The process responsible for FIFO creation removes the FIFO files using `unlink()` when appropriate.

The programs also account for the possibility of `SIGPIPE` when attempting to write to a FIFO without an active reader.

## Testing Unexpected Server Termination

The following test was performed to verify that the client detects an unexpected server disconnection.

First, the server was started in Terminal 1:

```bash
./server
```

Then, the client was started in Terminal 2:

```bash
./client
```

A message was sent from the client:

```text
Hello server
```

The server received the message and displayed:

```text
Client: Hello server
Reply:
```

While the client was waiting for the server's reply, the server was unexpectedly terminated by pressing:

```text
Ctrl + C
```

The client correctly detected the disconnection and displayed:

```text
Server disconnected before replying.
```

This confirmed that unexpected server termination was handled correctly.

## FIFO Cleanup

Because the server was terminated using `Ctrl + C`, its normal cleanup code could not execute.

The remaining FIFO files were manually removed using:

```bash
rm -f /tmp/fifo_client_to_server
rm -f /tmp/fifo_server_to_client
```

The FIFO files used in Parts 1 and 2 can also be removed using:

```bash
rm -f /tmp/comp2560_lab5_nozimbo_fifo
```

Error handling, unexpected termination detection, and manual cleanup were tested.

---

# 7. Part 5 – Discussion Questions

## Question 1: What is the main difference between a named pipe and a regular file?

A named pipe is used for communication between processes. Data written into a named pipe can be read by another process, and the data is removed as it is consumed.

A regular file stores data on disk and allows it to be accessed later. Unlike a named pipe, a regular file is designed for persistent data storage.

## Question 2: Can two unrelated processes communicate through a named pipe?

Yes. Two unrelated processes can communicate through a named pipe because it exists in the filesystem and can be accessed using its path.

Both processes need the necessary permissions to access the FIFO. They do not need to be related through a parent-child relationship.

## Question 3: Does a named pipe permanently store messages?

No. A named pipe does not permanently store messages.

It temporarily holds data in a limited kernel buffer while processes communicate. Once the reader consumes the data, it is removed from the pipe.

## Question 4: What happens if the writer produces data faster than the reader consumes it?

A named pipe has a limited buffer capacity.

If the writer produces data faster than the reader consumes it, the buffer eventually becomes full. When this happens, the writer blocks until the reader consumes some data and space becomes available.

This provides synchronization between the writer and reader.

## Question 5: When would you prefer a named pipe over an anonymous pipe?

A named pipe is preferred when two unrelated processes need to communicate because it can be accessed through a filesystem path.

An anonymous pipe is generally used for communication between related processes, such as a parent process and its child process.

---

# 8. Conclusion

This lab demonstrated inter-process communication using named pipes (FIFOs) in C.

Part 1 covered creating and using a named pipe to transfer a message between two independent processes. Both writer-first and reader-first startup orders were tested.

Part 2 extended the programs to support multiple messages using keyboard input and newline-terminated strings.

Part 3 implemented bidirectional communication using two named pipes and a turn-based request-response protocol.

Part 4 focused on error handling, unexpected process termination, closing file descriptors, and cleaning up FIFO resources.

Part 5 covered the differences between named pipes, regular files, and anonymous pipes, along with FIFO buffering and synchronization.

All four C programs were compiled successfully using GCC and tested in a Linux environment.