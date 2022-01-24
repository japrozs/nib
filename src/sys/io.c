#include <io.h>
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

char*  getFilePath(){
	char* fileName = "nib.yaml";
	char* dir = "/.nib/";
	char* var = "HOME";

	// get the root user path, for eg. /Users/<username>/
	if(!getenv(var)){
		fprintf(stderr, "The environment variable %s was not found.\n", var);
        exit(0);
	}

	// create root .nib directory if it doesnt exist
	char* home = getenv(var);
	char* path = malloc(BUFSIZE * sizeof(char));
	strcat(path,home);
	strcat(path,dir);

	DIR* directory = opendir(path);
	if(ENOENT == errno || !directory){
		mkdir(path, 0777);
		DIR* checkDir = opendir(path);
		if(!checkDir){
			printf("Couldn't create directory '%s'\n", path);
			exit(0);
		}
	}
	strcat(path,fileName);

	// create a .nib/nib.yaml file if it doesnt exist, if it does, return the file path
	if( access( path, F_OK ) != 0 ) {
		printf("File '%s' doesn't exist. Creating file... ", path);
		FILE* fp;
		fp = fopen(path, "w");
		if(fp == NULL){
			printf("\nCouldn't create file '%s'\n", path);
			exit(0);
		}
		printf("Done\n");
	}
	
	return path;
}

char* getCode(char* path){
	FILE    *infile;
	char* buf;
	long  numbytes;
	
	/* open an existing file for reading */
	infile = fopen(path, "r");
	
	if(infile == NULL){}
	
	fseek(infile, 0L, SEEK_END);
	numbytes = ftell(infile);
	
	fseek(infile, 0L, SEEK_SET);	
	
	buf = (char*)calloc(numbytes, sizeof(char));	
	
	if(buf == NULL){}
	
	fread(buf, sizeof(char), numbytes, infile);
	fclose(infile);
	
	return buf;
}