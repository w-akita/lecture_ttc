#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */

int main(void)
{
   pid_t  pid;

   /* 子プロセスと親プロセスの両方の出力が
    * 標準出力に書かれる。
    * 両者は同時に動作する。
    */
   pid = fork();
   if (pid == -1)
   {   
      /* エラー:
       * fork()が-1を返す場合、エラーが起きたことを示す。
       * 例えばプロセス数が制限に達した場合など。
       */
      fprintf(stderr, "can't fork, error %d\n", errno);
      exit(EXIT_FAILURE);
   }

   if (pid == 0)
   {
      /* 子プロセス:
       * fork()が0を返す場合、子プロセスである。
       * 1秒に1ずつ、10まで数える。
       */
      int j;
      for (j = 0; j < 10; j++)
      {
         printf("child: %d\n", j);
         sleep(1);
      }
      _exit(0);  /* exit() を使わない点に注意 */
   }
   else
   { 
       
      /* fork() が正の数を返す場合、親プロセスである。
       * その値は生成した子プロセスのPIDである。
       * ここでも10まで数える。
       */
      int i;
      for (i = 0; i < 10; i++)
      {
         printf("parent: %d\n", i);
         sleep(1);
      }
      exit(0);
   }
   return 0;
}
