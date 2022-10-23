#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *name;
    int middle;
    int final;
};
int compare(const void *cp1, const void *cp2){
    return strcmp(((struct node *)cp1)->name,((struct node *)cp2)->name);
}
void print_node(const void *, VISIT, int);
int main(){
    int tableSize;
    printf("몇 명 입니까?:");
    scanf("%d", &tableSize);
    
    char * nametable = (char *) malloc(sizeof(char) * tableSize);
    struct node * nodetable = (struct node *) malloc(sizeof(struct node)*tableSize);
    struct node *root =NULL;
    char *nameptr = nametable;
    struct node *nodeptr = nodetable;
    struct node **ret;
    int i =0;
    while(scanf("%s %d %d", nameptr, &nodeptr ->middle, &nodeptr ->final)!=EOF && i ++<tableSize){
        nodeptr->name = nameptr;
        /*트리에 넣기*/
        ret = (struct node **) tsearch((void *) nodeptr, (void **)&root, compare);
        printf("\" %s \" 님이", (*ret)->name);
        if(*ret == nodeptr){
            printf("트리에 추가되었습니다.\n");
        }else{
            printf("트리에 이미 존재합니다. \n");
        }
        nameptr += strlen(nameptr) +1;
        nodeptr++;
    }
    twalk((void *) root, print_node);
}
void print_node(const void * nodeptr, VISIT order, int level){
    if(order == preorder || order == leaf){
        printf("이름 = %-20s, 중간점수=%d, 기말점수=%d \n",
        (*(struct node **)nodeptr)->name,
        (*(struct node **)nodeptr)->middle,
        (*(struct node **)nodeptr)->final
        );
    }
}
