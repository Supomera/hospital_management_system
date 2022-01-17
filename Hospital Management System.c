#include<stdio.h>
#include<string.h>
// Author: Ömer Bera Dinç (github: Supomera)
struct ad
{
    char name[30];
    char department[30];
    char age[20];
    char surname[30];
    char mail[30];
}x[500];
int n,i,j=0,a=0,sum=0,g,flag,num;
void read();
void add();
void view();
void search();
void edit();
void del();
void show();
int main()
{
    read();
    int c,i,q,m;
    printf("--- Welcome to the Hospital Management System --- \n");
	printf("------------------------------------------------- \n \n");
// Here I'm making the pattern for program
    
    
    while(c!=4)
    {

        printf("1: Show All Records | 2: Search Patient | 3: New Patient | 4: Exit   \n");
        scanf("%d",&c);     //getting user's choice
        fflush(stdin);      //making it clear, it's messing up if I don't
        if(c==1)            //viewing records
        {
            system("cls");
            view();          //my viewing function
            printf("0: Return to Main Menu | 1: Delete Record | 2: Update Record \n"); //possible choices after viewing patient list
        	scanf("%d",&m); 
        	fflush(stdin); 
        	if(m==0)
        	{
        		continue;      //with this, code gets back to the previous block
			}
			else if(m==1)
			{
				system("cls");
				del();   //this is my record deleting function
			}
			else if(m==2)
			{
				system("cls");
				edit();    //this is a function for updating records
			}
        }
        else if(c==2)//search
        {
            system("cls");
            search();        //function to search
        }
        else if(c==3)//add
        {
            system("cls");
            add();            //function to add
        }
        
        else if(c==4)
        {
            write();         //function to write all information to a text file, after that this algorithm stops with returning zero.
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");  //to get valid input, I used this.
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num);   //Shows how many patients there are currently.
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);                                               //You can add more than one patient with this function, and this brings number of new patient(s).
    sum=n+num;

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");                                            //at this block, we are getting all information about the patient one by one to add them
        fflush(stdin);
        printf("Enter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter the surname = ");
        gets(x[i].surname);
        fflush(stdin);
        printf("Enter department = ");
        gets(x[i].department);
        fflush(stdin);
        printf("Enter the birthday = ");
        gets(x[i].age);
        fflush(stdin);
        printf("Enter mail = ");
        gets(x[i].mail);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view()
{
    for(i=0; i<num; i++)                        //This function views whole informations about all patients that are recorded. Works by printing all informations one by one.
    {
        printf("\n");
        printf("Serial Number=%d\n",i);
        printf("Name = ");
        puts(x[i].name);
        printf("Surname = ");
        puts(x[i].surname);
        printf("Department = ");
        puts(x[i].department);
        printf("Birthday = ");
        puts(x[i].age);
        printf("Mail = ");
        puts(x[i].mail);
        printf("\n\n");
    }
}
void edit()
{
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Surname\n3.Birthday\n4.Mail\n5.Department\n");        
    printf("Option=");
    scanf("%d",&q);                                                              //Here, getting the option               
    if(q<=5)
    {
        printf("Enter the serial no of that patient= (0 - %d)=",num-1);        //First we got what we want to edit and secondly we are getting patients ID to edit their info.
        scanf("%d",&p);                                                        //serial number(ID)
        if(p<num)
        {
            if(q==1)                                                           //If user selected "1" at the first phase, user arranges name of the patient that he/she choosed here. This is same for all else if blocks here.
            {
                fflush(stdin);
                printf("Enter the new name=");
                gets(x[p].name);

            }
            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Department=");
                gets(x[p].department);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Birthday=");
                gets(x[p].age);
            }

            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Surname=");
                gets(x[p].surname);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new mail =");
                gets(x[p].mail);
            }
        }
        else                                                               //If there is no patient for stated ID, algorithm wants the ID again here.
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else                                                                   //If there is no option for stated number, algorithm wants the number again here.
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s,h,f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Surname\n4.Birthday\n5.Mail\n6.Department\n\nOption = ");
    scanf("%d",&h);                                                                                 //Here I'm getting data that specifies searching by what
    if(h==1)
    {
        printf("Enter Serial number of the patient=");                         //With given ID, algorithm prints out all informations.
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number=%d\n",s);
            printf("Name = ");
            puts(x[s].name);
            printf("Surname = ");
            puts(x[s].surname);
            printf("Department = ");
            puts(x[s].department);
            printf("Birthday = ");
            puts(x[s].age);
            printf("Mail = ");
            puts(x[s].mail);
            printf("\n\n");
        }
        else                                                    //If there is no one with that ID, prints out "Not Found".
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)                                              //At first I got problem here but I guess I solved it, now algorithm can show all patients even if their names are same.
    {                                                          //But, for instance, if patient's name is Ömer; user need to search this patient as Ömer, so "Öme, Öm" etc. are not acceptable.
    															 //These comments are same for all blocks in this function, so I won't remark what I wrote again and again. 
        int f=1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Surname = ");
                puts(x[g].surname);
                printf("Department = ");
                puts(x[g].department);
                printf("Birthday = ");
                puts(x[g].age);
                printf("Mail = ");
                puts(x[g].mail);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==6)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Department = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].department)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Surname = ");
                puts(x[g].surname);
                printf("Department = ");
                puts(x[g].department);
                printf("Birthday = ");
                puts(x[g].age);
                printf("Mail = ");
                puts(x[g].mail);
                printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");


    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter your Surname=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].surname)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Surname = ");
                puts(x[g].surname);
                printf("Department = ");
                puts(x[g].department);
                printf("Birthday = ");
                puts(x[g].age);
                printf("Mail = ");
                puts(x[g].mail);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        fflush(stdin);
        printf("Enter the Mail=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].mail)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Surname = ");
                puts(x[g].surname);
                printf("Department = ");
                puts(x[g].department);
                printf("Birthday = ");
                puts(x[g].age);
                printf("Mail = ");
                puts(x[g].mail);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==4)
    {
         int f=1;
        fflush(stdin);
        printf("Enter the Birthday=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].age)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Surname = ");
                puts(x[g].surname);
                printf("Department = ");
                puts(x[g].department);
                printf("Birthday = ");
                puts(x[g].age);
                printf("Mail = ");
                puts(x[g].mail);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");

    }
    else
        printf("\n\nInvalid input\n\n");




}
void del()
{														
    int f,h;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);																		 //Here I'm getting ID of patient to delete them.
    if(f<num)
    {
        while(f<num)																	 //Here, code deletes all information about that patient, so deletes them as well.
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].surname,x[f+1].surname);
                strcpy(x[f].department,x[f+1].department);
                strcpy(x[f].age,x[f+1].age); 
                strcpy(x[f].mail,x[f+1].mail);
                f++;
            }
            num--;
    }
    else																				 //If that ID is invalid, algorithm feedbacks here.
        printf("\n\nInvalid Serial number\n");

}
void read()
{
    FILE *fp = fopen("patient.txt","r");                //Here we are opening a file to READ 
    if(fp == NULL)
    {
        //Creating an empty file (if does not exist) so that we can open it in the next execution of this program.
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");   //With this function, we are writing all informations about patient(s) we recorded, to save for next executions of this program.
    if(fp == NULL)
    {										 //If there is no file, it is feeding back and exiting.
        printf("Error");                 
        exit(1);
    }
    fwrite(x, sizeof(struct ad),num, fp);  //Writes information(s) here.

    fclose(fp);                            //Closes the file
}

