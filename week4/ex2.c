/*
   A tree for 3 iterations.


   ├─sshd─┬─sshd───bash─┬─ex2─┬─ex2─┬─ex2───ex2
        │      │             │     │     └─ex2
        │      │             │     ├─ex2───ex2
        │      │             │     └─ex2
        │      │             └─pstree
        │      └─sshd───sftp-server


   A tree for the 5 iterations.


     ├─sshd─┬─sshd───bash─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
        │      │             │     │     │     │     └─ex2
        │      │             │     │     │     ├─ex2───ex2
        │      │             │     │     │     └─ex2
        │      │             │     │     ├─ex2─┬─ex2───ex2
        │      │             │     │     │     └─ex2
        │      │             │     │     ├─ex2───ex2
        │      │             │     │     └─ex2
        │      │             │     ├─ex2─┬─ex2─┬─ex2───ex2
        │      │             │     │     │     └─ex2
        │      │             │     │     ├─ex2───ex2
        │      │             │     │     └─ex2
        │      │             │     ├─ex2─┬─ex2───ex2
        │      │             │     │     └─ex2
        │      │             │     ├─ex2───ex2
        │      │             │     └─ex2
        │      │             └─pstree
        │      └─sshd───sftp-server



    As we can see for the 3 iterations we have exactly 2^3 = 8 ex2 processes. For 5 iterations we have 2^5 = 32 ex processes. We have such values
    because on every iteration every procces is doubled into parent and child process.

*/






#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main(){

for (int i = 0; i < 5; i++){
    fork();
    sleep(5);
 }

return 0;
}
