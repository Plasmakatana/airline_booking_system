#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
struct User {
    char name[50];
    char email[50];
    char password[50];
    int is_logged_in;
};
struct information{
    char code[3];
    char name[20];
    int xpos;
    int ypos;
};
char usernameforpost[50];
void sign_up(void) {
    FILE* fp;
    char user[20],userch[20],pass[20],passch[20];
	char temp;
	printf("enter username: ");
	scanf("%c",&temp);
	scanf("%[^\n]", user);    
    printf("enter password: ");
	scanf("%c",&temp);
	scanf("%[^\n]", pass);
	fp = fopen("users.txt", "a+");
 	rewind(fp);
    if (NULL == fp) {
    	printf("file can't be opened \n");
    	exit(1);
    }
    else
    {
    fprintf(fp,"%s %s\n",user,pass);
	}
	fclose(fp);
}
void log_in(void/*struct User *users, int num_users, char *username, char *password*/) {
    FILE* fp;
    char user[20],userch[20],pass[20],passch[20];
    char temp;
    int isloggedin;
    printf("enter username: ");
    scanf("%c",&temp);
    scanf("%[^\n]", user);    
    printf("enter password: ");
    scanf("%c",&temp);
    scanf("%[^\n]", pass);
    fp = fopen("users.txt", "r");
    rewind(fp);
    if (NULL == fp) {
    printf("file can't be opened \n");
    }
    else
    {
            while(!feof(fp)){
									
            fscanf(fp,"%s %s\n",userch,passch);
            if(strcmp(user,userch)==0&&strcmp(pass,passch)==0)
            {
                printf("logged in!");
                isloggedin=1;
                strcpy(usernameforpost,userch);
	        }
        }
        if(isloggedin!=1){
        printf("wrong login username or password\nor does not exist\nwrong login username or password\nor does not exist\n");
									
        }
    }
    fclose(fp);
}
int main(){
    struct information info[18];
    
    FILE *airports;
    airports=fopen("airports.txt","r+");
    rewind(airports);
    int index=0;
    if (NULL == airports) {
        printf("file can't be opened \n");
    }
    else{
        while(!feof(airports)){
            fscanf(airports,"%s,%s,%d,%d\n",info[index].code,info[index].name,info[index].xpos,info[index].ypos);
            index++;
        }
    }
    for(int i=0;i<18;i++){
        printf("%s,%s",info[i].name,info[i].code);
    }
    
    fclose(airports);
    return 0;
}