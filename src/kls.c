#include <stdio.h>
#include <errno.h>

void usage()
{
printf("kls Usage :\n");
printf("kls <dir>\n");
}



int main(int argc,char** argv)
{
   if(argc < 2){
      usage();
      exit(-1);
    }
}
    
