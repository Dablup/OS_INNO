#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    //opening the directory
    DIR *dirp = opendir("./tmp/");
    if (dirp == NULL) {
        printf("Can't find such directory '/tmp/'!\n");
        return 1;
    }
 
    //opening the file
    FILE *outputFile = fopen("ex4.txt", "w");
    if (outputFile == NULL){
        printf("Can't find output file 'ex4.txt'!\n");
    }

    //struct for the directory entry
    struct dirent *directoryEntry;

    //struct for the information of entry
    struct stat infoAboutTheFile;

    char fulNameOfFile[512];
    while ((directoryEntry= readdir(dirp)) != NULL) {

        //Making a string concatenation ./tmp/ with directoryEntry name
        snprintf(fulNameOfFile, sizeof(fulNameOfFile), "%s%s", "./tmp/", directoryEntry->d_name);

        //Check whether the file has 2 or more hardlinks
        //If yes then print it
        stat(fulNameOfFile, &infoAboutTheFile);
        if (infoAboutTheFile.st_nlink >= 2) {
            fprintf(outputFile, "%s\n", fulNameOfFile);
        }
    }
    fclose(outputFile);
    return 0;
}
