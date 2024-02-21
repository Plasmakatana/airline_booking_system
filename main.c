#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
int isloggedin=0;
char interact;
void printlogo(void){
    int c[11]={1,3,2,6,4,5,4,6,2,3,1};
    for(int i=0;i<11;i++){
        printf("\033[1;3%dm",c[i]);
        for(int j=10;j>i;j--){
            printf(" "); 
        }
        for(int k=0;k<2*i+1;k++){
            if(i!=5){
                if(k==(2*i)||k==(2*i+1)||k==(2*i-1)||k==i||k==i+1){
                    printf("#");
                }
                else{
                    printf(" ");
                }            
        }
        else{
            printf("#");
        }
        }
        printf("\n");
    }
    printf("\033[1;35m");
    
}
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
char usrnm[20];
void sign_up(void) {
    FILE* fp;
    char userch[20],passch[20];
    char user[20],pass[20];
	char temp;
    int counter=0;
	printf("enter username: ");
	scanf("%c",&temp);
	scanf("%[^\n]s",&user);       
    printf("enter password: ");
	scanf("%c",&temp);
	scanf("%[^\n]s",&pass);
	fp = fopen("users.txt", "a+");
    rewind(fp);
    while(!feof(fp)){
        fscanf(fp,"%s %s\n",userch,passch);
        if(strcmp(user,userch)==0){
            printf("user already exists,Please login");
            counter++;
        }
    }
 	rewind(fp);
    if (NULL == fp) {
    	printf("file can't be opened \n");
    	exit(1);
    }
    else
    {
        if(counter==0){
            fprintf(fp,"%s %s\n",user,pass);
	    }
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
    price=6000+300*((xd*xd)+(yd*yd))+10000/((mdiff*30)+ddiff);
    return price;
}
void printticket(struct ticketing *t){
    printf("\033[1;31m");
    printf("\n|_______________|\n     TICKET   \n|_______________|\n");
    printf("\033[1;32m");
    printf("\n|_____AXIOM_____|\n|____AIRWAYS____|\n");
    printf("\033[1;33m");
    printf("|%s\n",name);
    printf("\033[1;34m");
    printf("|%s ------> %s|\n",t->start,t->end);
    printf("\033[1;37m");
    printf("|%d/%d      %d:%d|",t->flightday,t->flightmonth,rand()%24,rand()%60);
    printf("\033[1;36m");
    printf("\n|_______________|\n|_______________|\n");
}
void printinvoice(struct ticketing *inv){
    printf("\033[1;31m");
    printf("\n\n\n\n______________________\n       INVOICE      \n|_____________________\n");
    printf("\033[1;32m");
    printf("|%s\n",inv->name);
    printf("\n|______________________\n");
    printf("\033[1;33m");
    printf("|%s\n",name);
    printf("\n|______________________\n");
    printf("\033[1;34m");
    printf("|%s TO %s\n",inv->startname,inv->endname);
    printf("\n|______________________\n");
    printf("\033[1;37m");
    printf("|Amount to be Paid: %d\n",inv->flightprice);
    printf("\n|______________________\n");
    printf("\033[1;36m");
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
    printlogo();
    printf("\n|\t\t|\t\t|\n\n");
    delay(300);
    system("cls");
    printlogo();
    printf("\n/\t\t/\t\t/\n\n");
    delay(300);
    system("cls");
    printlogo();
    printf("\n--\t\t--\t\t--\n\n");
    delay(300);
    system("cls");
    printlogo();
    printf("\n\\\t\t\\\t\t\\\n\n");
    }

}

int main(){
    int color=4;
    printf("\033[1;3%dm",color);
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
        printf("\033[1;31m");
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
        
    }
    fclose(fptr);
    int input=0;
    display_loading();
    system("cls");
    printlogo();
    printf("\n1.Login\n2.Signup\n3.Exit\n");
    while(isloggedin==0){
        color++;
        printf("\033[1;3%dm",color%8);
        printf("Enter your choice: ");
        scanf("%d",&input);
    if(input==1){
        log_in();
        if (isloggedin!=1){
            printf("\033[1;31m");
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
        printf("\033[1;31m");
        printf("wrong input");
    }
    }
    out:
    //delay(2000);
    display_loading();
    system("cls");
    printlogo();
    color++;
    printf("\033[1;3%dm",color%8);
    printf("1.Retrieve previous details\n2.Book new ticket\n3.Exit\n");
    printf("Enter choice:");
    scanf("%d",&purpose);
    color++;
    printf("\033[1;3%dm",color%8);
    if(purpose==1){
        system("cls");
        printlogo();
        show_previous(usrnm);
        printf("Returning after 20 seconds");
        getch();
        goto out;
    }
    else if(purpose==3){
        exit(1);
    }
    else if(purpose==2){
    display_loading();
    system("cls");
    printlogo();
    color++;
    printf("\033[1;3%dm",color%8);
    printf("\nToday's Date: %d %3s\n",day,array[month-1]);
    printf("\n________________________________________________________________\n");
    int choice;
    color++;
    printf("\033[1;3%dm",color%8);
    printf("DEPARTURE DATE:\n");
    for(int i=0;i<12;i++){
        printf("\033[1;3%dm",i%8);
        printf("%d %s\n",i+1,array[i]);
    }
    color++;
    printf("\033[1;3%dm",color%8);
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
    printlogo();
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
    printlogo();
    for(int i=0;i<18;i++){
        printf("\033[1;3%dm",i%8);
        printf("\n%d %s\n",i+1,info[i].name);
    }
    color++;
    printf("\033[1;3%dm",color%8);   
    printf("Enter Starting City :");
    scanf("%d",&index_1);
    printf("\n________________________________________________________________\n");
    display_loading();
    system("cls");
    printlogo();
    for(int i=0;i<18;i++){
        printf("\033[1;3%dm",i%8);
        printf("\n%d %s\n",i+1,info[i].name);
    }
    color++;
    printf("\033[1;3%dm",color%8);
    printf("Enter Destination :");
    scanf("%d",&index_2);
    printf("\nEnter your Full Name: ");
    scanf("%c",&t_b);
    scanf("%[^\n]",&name);
    display_loading();
    system("cls");
    printlogo();
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
    getch();
    display_loading();
    color++;
    printf("\033[1;3%dm",color%8);
    goto out;
    }
    else{
        display_loading();
        system("cls");
        printlogo();
        printf("\033[1;31m");
        printf("Invalid input");
        delay(5000);
        display_loading();
    }
    color++;
    printf("\033[1;3%dm",color%8);
    return 0;
}