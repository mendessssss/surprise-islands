#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// int countfiles(char *path) {
//     DIR *dir_ptr = NULL;
//     struct dirent *direntp;
//     char *npath;
//     if (!path) return 0;
//     if( (dir_ptr = opendir(path)) == NULL ) return 0;

//     int count=0;
//     while( (direntp = readdir(dir_ptr)))
//     {
//         if (strcmp(direntp->d_name,".")==0 ||
//             strcmp(direntp->d_name,"..")==0) continue;
//         switch (direntp->d_type) {
//             case DT_REG:
//                 ++count;
//                 break;
//             case DT_DIR:            
//                 npath=malloc(strlen(path)+strlen(direntp->d_name)+2);
//                 sprintf(npath,"%s/%s",path, direntp->d_name);
//                 count += countfiles(npath);
//                 free(npath);
//                 break;
//         }
//     }
//     closedir(dir_ptr);
//     return count;
// }

int main (void){
    size_t count = 0;
    struct dirent *res;
    struct stat sb;
    const char *path = "/home/namoux/Documents/Exo C/Projet C/RPG Textuels/surprise-islands/iles";

    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)){
        DIR *folder = opendir ( path );

        if (access ( path, F_OK ) != -1 ){
            if ( folder ){
                while ( ( res = readdir ( folder ) ) ){
                    if ( strcmp( res->d_name, "." ) && strcmp( res->d_name, ".." ) ){
                        printf("%zu) - %s\n", count + 1, res->d_name);
                        count++;
                    }
                }

                closedir ( folder );
            }else{
                perror ( "Could not open the directory" );
                exit( EXIT_FAILURE);
            }
        }

    }else{
        printf("The %s it cannot be opened or is not a directory\n", path);
        exit( EXIT_FAILURE);
    }

    // printf( "\n\tFound %zu Files\n", count );
}