/*dltest.c*/
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(){
	void *handle;
	int (*add)(int,int), (*substract)(int,int), (*multifly)(int,int), (*divide)(int,int);
	char *error;
	
	handle = dlopen("./lib/libcal.so", RTLD_LAZY);
	if(!handle){
		fputs (dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if((error = dlerror()) != NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
        substract = dlsym(handle, "substract");
        if((error = dlerror()) != NULL){
                fprintf(stderr,"%s",error);
                exit(1);
        }
        multifly = dlsym(handle, "multifly");
        if((error = dlerror()) != NULL){
                fprintf(stderr,"%s",error);
                exit(1);
        }
        divide = dlsym(handle, "divide");
        if((error = dlerror()) != NULL){
                fprintf(stderr,"%s",error);
                exit(1);
        }

        printf("add(5,2) = %d\n", (*add)(5,2));
        printf("substract(5,2) = %d\n", (*substract)(5,2));
        printf("multifly(5,2) = %d\n", (*multifly)(5,2));
        printf("divide(5,2) = %d\n", (*divide)(5,2));
	dlclose(handle);
}
