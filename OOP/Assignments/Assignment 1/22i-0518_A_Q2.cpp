/*
    Name: Umer Farooq
    Student-ID: 22I-0518
    Assignment #1
*/
#include <iostream> 
using namespace std;
int toupper (char* ch);
int tolower (char* ch);
int isspace (const char* ch);
char* strncpy (char* dest, const char* src, size_t n);
int strcmp (const char* cstr1, const char* cstr2);
char* strncat (char* dest, const char* src, size_t n);
char* strstr (char* cstr1, char* cstr2);     
char* strtok (char* cstr, const char* delim);   //works only first time but aftwerwards it doesn't work
int strlen(char* cstr);
int main()
{   
    char* ch1= new char[100];   //2 dynamic character arrays
    char* ch2= new char[100];
    cout<<"Enter str1"<<endl;       //input for 1st string
    cin.getline(ch1,100);
    
    int choice;
    cout<<"Choose from menu(Enter the number)"<<endl;
    cout<<"1. to upper\n2. tolower\n3. to isspace\n4. string copy\n5. string compare\n6. string concatenate\n7. strstr\n8. string tokenize"<<endl;          //print menu
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<toupper(ch1);
        cout<<ch1;
        break;
    
    case 2:
        cout<<tolower(ch1);
        break;

    case 3:
        cout<<isspace(ch1);
        break;
    
    case 4:
        cout<<"Enter str2"<<endl;
        cin.getline(ch2,100);
        cout<<strncpy(ch1,ch2,100);
        break;
    
    case 5:
        cout<<"Enter str2"<<endl;
        cin.getline(ch2,100);
        cout<<strcmp(ch1,ch2);
        break;

    case 6:
        cout<<"Enter str2"<<endl;
        cin.getline(ch2,100);
        cout<<strncat(ch1,ch2,100);
        break;

    case 7:
        cout<<"Enter str2"<<endl;
        cin.getline(ch2,100);
        cout<<strstr(ch1,ch2);
        break;

    case 8:
        
        cout<<strtok(ch1," ");
        break;


    default:
        cout<<"Enter valid input"<<endl;
        break;
    }
}
int toupper (char* ch)
{
   for(int i=0; *(ch+i) != '\0'; i++)
   {
        if(*(ch+i)>='a' && *(ch+i)<='z')        //checks for only lowercase letters then converts
        {
            *(ch+i) -= 32;
        }
   }
   return 0;
}
int tolower (char* ch)
{
    for(int i=0; *(ch+i) != '\0'; i++)
   {
        if(*(ch+i)>='A' && *(ch+i)<='Z')    //checks for only capital letters then converts
        {
            *(ch+i) += 32;
        }
   }
   return 0;
}
int isspace (const char* ch)
{
    for(int i=0; *(ch+i) != '\0'; i++)
    {
        if(*(ch+i)==' ' || *(ch+i)<='\r' || *(ch+i)<='\t'|| *(ch+i)<='\n' || *(ch+i)<='\f'|| *(ch+i)<='\v')
        {
            return 1;           //checks for only specified characters in array and if found return true
        }q
    }
   return 0;
}
char* strncpy (char* dest, const char* src, size_t n)
{
    for(int i=0; i<n ; i++)
    {   
        *(dest+i) = *(src+i);       //copy every element to the dest array from src
    }
   return dest;
}
int strcmp (const char* cstr1, const char* cstr2)
{
    int i=0;
    while( *(cstr1 + i) != '\0' || *(cstr2 + i) != '\0')
    {
        if(*(cstr1 + i) < *(cstr2 + i))
        {
            return -1;                              //checks str 1 and 2 for equality or inequality
        }   
        else if(*(cstr1 + i) > *(cstr2 + i))
        {
            return 1;
        }
        i++;
    }
    return 0;
}
char* strncat (char* dest, const char* src, size_t n)
{
   dest += n;
   strncpy(dest,src,n);
   dest += n;                   //append str2 at end of str 1
   *dest = '\0'; 
   return dest; 
}
char* strstr (char* cstr1, char* cstr2)
{
    char* occur;
    for(int i=0; *(cstr1+i)!='\0'; i++)     //run till end of str 1
    {
        if(*(cstr1+i) == *cstr2)        //if at any point it matches str 2
        {
            int k=0;
            for (int j =i; *(cstr1+j)!='\0'; j++,i++)   
            {                           //keep checking after that point if they match till end of str1
                                
                if(*(cstr2+k)!='\0')            //check till end of str 2
                {       
                    if(*(cstr2+k) == *(cstr1+j))          //keep moving in array till they match
                    {
                        k++;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    occur= cstr1+i-strlen(cstr2);
                    return occur;
                }  
            }
            occur= cstr1+i;
            return occur;             
            
        }
    }
    return nullptr;
}
char* strtok (char* cstr, const char* delim)
{   
    static int i=0;
    char* dest;
    if(cstr == nullptr)             //if nullptr meaning its called a 2nd time
    {
                    
        strncpy(dest,cstr+i,strlen(cstr+i));           
        strncpy(cstr,dest,strlen(dest));
        *(cstr+i) = '\0';
        i=0;
        while(*(cstr+i)!= '\0')
        {
            if(*(cstr+i) == *delim)
            {
                *(cstr+i)= '\0';
                return cstr;
            }
            i++;
        }
    }
    else
    {
        i=0;
    
        while(*(cstr+i)!= '\0')
        {
            if(*(cstr+i) == *delim)
            {
                *(cstr+i)= '\0';
                return cstr;
            }
            i++;
        }
    }
    return nullptr;
}
int strlen(char* cstr)
{
    int i=0;
    while(*(cstr+i)!= '\0')
    {
        i++;
    }
    return --i;
}