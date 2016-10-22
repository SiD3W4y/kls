#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>


const char *months[] = {
	"jan.","feb.","mar.","apr."
	,"may","jun.","jul.","aug.",
	"sep.","oct.","nov.","dec."
};



void usage()
{
printf("kls Usage :\n");
printf("kls <dir>\n");
}

void printmode(struct stat *st)
{
printf((S_ISDIR(st->st_mode)) ? "d" : "-");
printf((st->st_mode & S_IRUSR) ? "r" : "-");
printf((st->st_mode & S_IWUSR) ? "w" : "-");
printf((st->st_mode & S_IXUSR) ? "x" : "-");
printf((st->st_mode & S_IRGRP) ? "r" : "-");
printf((st->st_mode & S_IWGRP) ? "w" : "-");
printf((st->st_mode & S_IXGRP) ? "x" : "-");
printf((st->st_mode & S_IROTH) ? "r" : "-");
printf((st->st_mode & S_IWOTH) ? "w" : "-");
printf((st->st_mode & S_IXOTH) ? "x" : "-");
}

void printdate(struct tm *time)
{
printf("%i %s %i:%i ",time->tm_mday,months[time->tm_mon],time->tm_hour,
							time->tm_min);
}



void printentry(struct dirent *entry)
{
struct stat *dstat = malloc(sizeof(struct stat));
struct tm *time;

if(stat(entry->d_name,dstat) != 0){
	perror("Stat error");
}else{	
	time = localtime(&dstat->st_mtime);
	printmode(dstat);
	printf(" %i ",(long)dstat->st_size);
	printdate(time);
	printf("%s\n",entry->d_name);
}
free(dstat);
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
	if(strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name,"..") !=0){
		printentry(dir);
	}

}

return 0;
}
    
