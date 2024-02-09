<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
int isloggedin=0;
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
struct User {
    char name[50];
    char email[50];
    char password[50];
    int is_logged_in;
};
char name[20];
struct information{
    char code[20],name[20];
    int xc,yc;
};
struct ticketing
{
    char start[20];
    char end[20];
    char startname[20];
    char endname[20];
    char name[20];
    int flightday;
    int flightmonth;
    int flightprice;
};
char username[20];
char ticketname[20];
char usrnm[20];
void sign_up(void) {
    FILE* fp;
    char user[20],pass[20];
	char temp;
	printf("enter username: ");
	scanf("%c",&temp);
	scanf("%[^\n]s",&user);    
    printf("enter password: ");
	scanf("%c",&temp);
	scanf("%[^\n]s",&pass);
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
    strcpy(usrnm,user);
}

void log_in() {
    FILE* fp;
    char user[20],userch[20],pass[20],passch[20];
    char temp;
    printf("Enter username: ");
    scanf("%c",&temp);
    scanf("%[^\n]", &user);    
    printf("Enter password: ");
    scanf("%c",&temp);
    scanf("%[^\n]", &pass);
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
                strcpy(username,userch);
	        }
        }
        if(isloggedin!=1){
        printf("wrong login username or password\nor does not exist\nwrong login username or password\nor does not exist\n");
		}
    }
    fclose(fp);
    strcpy(usrnm,user);
}
int calculate(int mdiff,int ddiff,int xd,int yd){
    int price=0;
    price=6000+30*((xd*xd)+(yd*yd))-1*((mdiff*30)+ddiff);
    return price;
}
void printticket(struct ticketing *t){
    printf("\n|_______________|\n     TICKET   \n|_______________|\n");
    printf("\n|____SKIBIDI____|\n|____AIRWAYS____|\n");
    printf("|%s\n",name);
    printf("|%s ------> %s|\n",t->start,t->end);
    printf("|%d/%d      %d:%d|",t->flightday,t->flightmonth,rand()%24,rand()%60);
    printf("\n|_______________|\n|_______________|\n");
}
void printinvoice(struct ticketing *inv){
    printf("\n\n\n\n______________________\n       INVOICE      \n|_____________________\n");
    printf("|%s\n",inv->name);
    printf("\n|______________________\n");
    printf("|%s\n",name);
    printf("\n|______________________\n");
    printf("|%s TO %s\n",inv->startname,inv->endname);
    printf("\n|______________________\n");
    printf("|Amount to be Paid: %d\n",inv->flightprice);
    printf("\n|______________________\n");
    printf("|Date of Departure: %d/%d\n",inv->flightday,inv->flightmonth);
    printf("\n|______________________\n");
}
void ticket_to_file(struct ticketing *t){
    FILE* fp;
    fp=fopen("tickets.txt","a+");
    rewind(fp);
    if (NULL == fp) {
        printf("file can't be opened \n");
    }
    else
    {
        
        fprintf(fp,"%s %s %s %d %d %d\n",usrnm,t->startname,t->endname,t->flightday,t->flightmonth,t->flightprice);
        //printf("saved");
        
    }
    fclose(fp);
}

void show_previous(char f_usrnm[20]){
    char startname[20],endname[20];
    int flightday,flightmonth,flightprice;
    char userch[20];
    FILE* fp;
    fp = fopen("tickets.txt", "r");
    rewind(fp);
    if (NULL == fp) {
        printf("file can't be opened \n");
    }
    else
    {
        while(!feof(fp)){
			fscanf(fp,"%s %s %s %d %d %d\n",userch,startname,endname,&flightday,&flightmonth,&flightprice);
            if(strcmp(f_usrnm,userch)==0){
                printf("%s,%s to %s,on %d/%d,Rs. %d\n",userch,startname,endname,flightday,flightmonth,flightprice);
            }
        }

    }
    fclose(fp);
}
void display_loading(void){
    for(int j=0;j<2;j++){
    delay(300);
    system("cls");
    printf("|");
    delay(300);
    system("cls");
    printf("/");
    delay(300);
    system("cls");
    printf("--");
    delay(300);
    system("cls");
    printf("\\");
    }

}

int main(){
    char t_b;
    int purpose=0;
    char *array[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    //date of today
    time_t now;
    struct tm *local=localtime(&now);
    int day=local->tm_mday;
    int month=local->tm_mon;
    //airport names
    struct information info[18];
    char code[20];
    int xcoords[18]={0};
    int ycoords[18]={0};
    FILE* fptr;
    fptr=fopen("airports.txt","r+");
    rewind(fptr);
    int index=0;
    if (NULL == fptr) {
        printf("airports file can't be opened \n");
    }
    else{
        while(!feof(fptr)){
            fscanf(fptr,"%s %s %d %d\n",code,name,&info[index].xc,&info[index].yc);
            strcpy(info[index].code,code);
            strcpy(info[index].name,name);
            xcoords[index]=info[index].xc;
            ycoords[index]=info[index].yc;
            index++;
        }
        fclose(fptr);
    }
    int input=0;
    display_loading();
    system("cls");
    printf("\n1.Login\n2.Signup\n3.Exit\n");
    while(isloggedin==0){
        printf("Enter your choice: ");
        scanf("%d",&input);
    if(input==1){
        log_in();
        if (isloggedin!=1){
            printf("\nwrong username or password please signup or recheck\n");
        }
        else{
            goto out;
        }
    }
    else if(input==3){
        exit(1);
    }
    else if(input==2){
        sign_up();
        isloggedin=1;
        goto out;
    }
    else{
        printf("wrong input");
    }
    }
    out:
    display_loading();
    system("cls");
    printf("1.Retrieve previous details\n2.Book new ticket\n3.Exit\n");
    printf("Enter choice:");
    scanf("%d",&purpose);
    if(purpose==1){
        system("cls");
        show_previous(usrnm);
        printf("Returning after 20 seconds");
        delay(20000);
        goto out;
    }
    else if(purpose==3){
        exit(1);
    }
    else if(purpose==2){
    display_loading();
    system("cls");
    printf("\nToday's Date: %d %3s\n",day,array[month-1]);
    printf("\n________________________________________________________________\n");
    int choice;
    
    printf("DEPARTURE DATE:\n");
    for(int i=0;i<12;i++){
        printf("%d %s\n",i+1,array[i]);
    }
    struct ticketing ticket;
    struct ticketing invoice;
    printf("Select month: \n");
    scanf("%d",&choice);
    int monthdiff=0;
    if(choice-month>=0){
        monthdiff=choice-month;
    }
    else{
        monthdiff=11-month+choice;
    }
    ticket.flightmonth=choice;
    //for(int i=0;i<18;i++){
    //    printf("\n%s %s %d %d\n",info[i].code,info[i].name,info[i].xc,info[i].yc);
    //}
    int daydiff=0;
    display_loading();
    system("cls");
    printf("DEPARTURE DATE:");
    printf("Enter day(1-30) :");
    scanf("%d",&choice);
    checkdate:
    if(choice<=31){
    if(choice>=day){
        daydiff=choice-day;
    }
    else{
        daydiff=30-choice+day;
    }
    }
    else{
        printf("Enter valid date!");
        goto checkdate;
    }
    ticket.flightday=choice;
    int index_1,index_2;
    display_loading();
    system("cls");
    for(int i=0;i<18;i++){
        printf("\n%d %s\n",i+1,info[i].name);
    }   
    printf("Enter Starting City :");
    scanf("%d",&index_1);
    printf("\n________________________________________________________________\n");
    display_loading();
    system("cls");
    for(int i=0;i<18;i++){
        printf("\n%d %s\n",i+1,info[i].name);
    }
    printf("Enter Destination :");
    scanf("%d",&index_2);
    printf("\nEnter your Full Name: ");
    scanf("%c",&t_b);
    scanf("%[^\n]",&name);
    display_loading();
    system("cls");
    index_1--;
    index_2--;
    int xdiff=xcoords[index_2]-xcoords[index_1];
    int ydiff=ycoords[index_2]-ycoords[index_1];
    int t_price=calculate(monthdiff,daydiff,xdiff,ydiff);
    
    strcpy(ticket.start,info[index_1].code);
    strcpy(ticket.startname,info[index_1].name);
    strcpy(ticket.endname,info[index_2].name);
    strcpy(ticket.end,info[index_2].code);
    strcpy(ticket.name,usrnm);    
    ticket.flightprice=t_price;
    printticket(&ticket);
    printinvoice(&ticket);
    ticket_to_file(&ticket);
    printf("\nreturning in 20 seconds\n");
    scanf("%c",&t_b);
    delay(20000);
    display_loading();
    goto out;
    }
    else{
        display_loading();
        system("cls");
        printf("Invalid input");
        delay(5000);
        display_loading();
    }
    return 0;
}
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
int isloggedin=0;
struct User {
    char name[50];
    char email[50];
    char password[50];
    int is_logged_in;
};
char name[20];
struct information{
    char code[20],name[20];
    int xc,yc;
};
struct ticketing
{
    char start[20];
    char end[20];
    char startname[20];
    char endname[20];
    char name[20];
    int flightday;
    int flightmonth;
    int flightprice;
};
char username[20];
char ticketname[20];
char usrnm[20];
void sign_up(void) {
    FILE* fp;
    char user[20],pass[20];
	char temp;
	printf("enter username: ");
	scanf("%c",&temp);
	scanf("%[^\n]s",&user);    
    printf("enter password: ");
	scanf("%c",&temp);
	scanf("%[^\n]s",&pass);
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
    strcpy(usrnm,user);
}

void log_in() {
    FILE* fp;
    char user[20],userch[20],pass[20],passch[20];
    char temp;
    printf("Enter username: ");
    scanf("%c",&temp);
    scanf("%[^\n]", &user);    
    printf("Enter password: ");
    scanf("%c",&temp);
    scanf("%[^\n]", &pass);
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
                strcpy(username,userch);
	        }
        }
        if(isloggedin!=1){
        printf("wrong login username or password\nor does not exist\nwrong login username or password\nor does not exist\n");
		}
    }
    fclose(fp);
    strcpy(usrnm,user);
}
int calculate(int mdiff,int ddiff,int xd,int yd){
    int price=0;
    price=6000+3000*((xd*xd)+(yd*yd))-100*((mdiff*30)+ddiff);
    return price;
}
void printticket(struct ticketing *t){
    printf("\n|_______________|\n     TICKET   \n|_______________|\n");
    printf("\n|____SKIBIDI____|\n|____AIRWAYS____|\n");
    printf("|%s\n",name);
    printf("|%s ------> %s|\n",t->start,t->end);
    printf("|%d/%d      %d:%d|",t->flightday,t->flightmonth,rand()%24,rand()%59);
    printf("\n|_______________|\n|_______________|\n");
}
void printinvoice(struct ticketing *inv){
    printf("\n\n\n\n______________________\n       INVOICE      \n|_____________________\n");
    printf("|%s\n",inv->name);
    printf("\n|______________________\n");
    printf("|%s\n",name);
    printf("\n|______________________\n");
    printf("|%s TO %s\n",inv->startname,inv->endname);
    printf("\n|______________________\n");
    printf("|Amount to be Paid: %d\n",inv->flightprice);
    printf("\n|______________________\n");
    printf("|Date of Departure: %d/%d\n",inv->flightday,inv->flightmonth);
    printf("\n|______________________\n");
}

int main(){
    char t_b;
    char *array[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    //date of today
    time_t now;
    struct tm *local=localtime(&now);
    int day=local->tm_mday;
    int month=local->tm_mon;
    //airport names
    struct information info[18];
    char code[20];
    int xcoords[18]={0};
    int ycoords[18]={0};
    FILE* fptr;
    fptr=fopen("airports.txt","r+");
    rewind(fptr);
    int index=0;
    if (NULL == fptr) {
        printf("airports file can't be opened \n");
    }
    else{
        while(!feof(fptr)){
            fscanf(fptr,"%s %s %d %d\n",code,name,&info[index].xc,&info[index].yc);
            strcpy(info[index].code,code);
            strcpy(info[index].name,name);
            xcoords[index]=info[index].xc;
            ycoords[index]=info[index].yc;
            index++;
        }
        fclose(fptr);
    }
    int input=0;
    system("cls");
    printf("\n1.Login\n2.Signup\n");
    while(isloggedin==0){
        printf("Enter your choice: ");
        scanf("%d",&input);
    if(input==1){
        log_in();
        if (isloggedin!=1){
            printf("\nwrong username or password please signup or recheck\n");
        }
        else{
            goto out;
        }
    }
    else if(input==2){
        sign_up();
        isloggedin=1;
        goto out;
    }
    else{
        printf("wrong input");
    }
    }
    out:
    system("cls");
    printf("\nToday's Date: %d %3s\n",day,array[month-1]);
    printf("\n________________________________________________________________\n");
    int choice;
    
    printf("DEPARTURE DATE:\n");
    for(int i=0;i<12;i++){
        printf("%d %s\n",i+1,array[i]);
    }
    struct ticketing ticket;
    struct ticketing invoice;
    printf("Select month: \n");
    scanf("%d",&choice);
    int monthdiff=0;
    if(choice-month>=0){
        monthdiff=choice-month;
    }
    else{
        monthdiff=11-month+choice;
    }
    ticket.flightmonth=choice;
    for(int i=0;i<18;i++){
        printf("\n%s %s %d %d\n",info[i].code,info[i].name,info[i].xc,info[i].yc);
    }
    int daydiff=0;
    system("cls");
    printf("DEPARTURE DATE:");
    printf("Enter day(1-30) :");
    scanf("%d",&choice);
    checkdate:
    if(choice<=31){
    if(choice>=day){
        daydiff=choice-day;
    }
    else{
        daydiff=30-choice+day;
    }
    }
    else{
        printf("Enter valid date!");
        goto checkdate;
    }
    ticket.flightday=choice;
    int index_1,index_2;
    system("cls");
    for(int i=0;i<18;i++){
        printf("\n%d %s\n",i+1,info[i].name);
    }   
    printf("Enter Starting City :");
    scanf("%d",&index_1);
    printf("\n________________________________________________________________\n");
    system("cls");
    for(int i=0;i<18;i++){
        printf("\n%d %s\n",i+1,info[i].name);
    }
    printf("Enter Destination :");
    scanf("%d",&index_2);
    printf("\nEnter your Full Name: ");
    scanf("%c",&t_b);
    scanf("%[^\n]",&name);
    system("cls");
    index_1--;
    index_2--;
    int xdiff=xcoords[index_2]-xcoords[index_1];
    int ydiff=ycoords[index_2]-ycoords[index_1];
    int t_price=calculate(monthdiff,daydiff,xdiff,ydiff);
    
    strcpy(ticket.start,info[index_1].code);
    strcpy(ticket.startname,info[index_1].name);
    strcpy(ticket.endname,info[index_2].name);
    strcpy(ticket.end,info[index_2].code);
    strcpy(ticket.name,usrnm);    
    ticket.flightprice=t_price;
    printticket(&ticket);
    printinvoice(&ticket);
    return 0;
}
