/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:50:28 by lteng             #+#    #+#             */
/*   Updated: 2023/12/30 16:50:29 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void child_process(int pipefd[]) {
    // Close the read end in the child process (not used)
    close(pipefd[0]);

    // Write data to the pipe
    write(pipefd[1], "Hello from child!\n", 19);

    // Close the write end after writing
    close(pipefd[1]);

    // Child process logic
    // ...
}

void parent_process(int pipefd[]) {
    // Close the write end in the parent process (not used)
    close(pipefd[1]);

    // Read data from the pipe
    char buffer[20];
    read(pipefd[0], buffer, sizeof(buffer));

    // Close the read end after reading
    close(pipefd[0]);

    // Print the received data
    printf("Parent received: %s", buffer);
    fflush(stdout);

    // Parent process logic
    // ...
}

int main() {
    int pipefd[2];
    pid_t process_id;

    if (pipe(pipefd) == -1) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }

    process_id = fork();
    if (process_id == -1) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }

    if (process_id == 0) {
        // Child process
        child_process(pipefd);
    } else {
        // Parent process
        parent_process(pipefd);
    }

    return 0;
}
