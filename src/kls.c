#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

void usage()
{
printf("kls Usage :\n");
printf("kls <dir>\n");
}

void printentry(struct dirent *entry)
{
struct stat *dstat;
stat(entry->d_name,dstat);
printf("%s\n",entry->d_name);

}



int main(int argc,char** argv)
{
DIR *entry;
struct dirent *dir;
char *wd;

if(argc < 2){
	wd = ".";
}else{
	wd = argv[1];
}


entry = opendir(wd);

if(!entry){
	perror("Failed to open folder");
	exit(-1);
}

while((dir = readdir(entry)) != NULL){
	if(strcmp(".",dir->d_name)!=0 && strcmp("..",dir->d_name)!=0){
		printentry(dir);	
	}
}


    
}
    
