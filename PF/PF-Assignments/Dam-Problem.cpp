 /* Name = Umer farooq
   student ID= 22I-0518
   	Assignment #2	
*/

#include <iostream>
using namespace std;
int main(){
    
    float cl,changedcl,inc,dec,monthly;
    int cm,cy;
    float yearly;
    cout<<"Enter inc,dec,cl,cm,cy"<<endl;
    cin>>inc>>dec>>cl>>cm>>cy;
    yearly = (inc*(6)) - (dec*(6));
    if(yearly > 0){
    
    	 switch (cm)
        {
        case 3:
        		monthly = inc;
               changedcl = cl + monthly*5;
               break;
        case 4:
        		monthly = inc;
               changedcl = cl + monthly*4;
               break;
        case 5: 
        		monthly = inc;
               changedcl = cl + monthly*3;
               break;
        case 6:
        		monthly = inc;
               changedcl = cl + monthly*2;
               break;
        case 7:
        		monthly = inc;
               changedcl = cl + monthly*1;
               break;
        case 8: 
               monthly = inc;
               changedcl = cl + monthly*0;
               break;
        
        case 9:
        		 monthly = dec;
                changedcl = cl - monthly*5; 
                break;
        case 10:
        		 monthly = dec;
                 changedcl = cl - monthly*4; 
                 break;
        case 11:
         		monthly = dec;
                changedcl = cl - monthly*3; 
                break;
        case 12:
        		 monthly = dec;
                changedcl = cl - monthly*2; 
                break;
        case 1:
   		 		monthly = dec;
                changedcl = cl - monthly*1; 
                break;
        case 2:
        		monthly = dec;
                changedcl = cl - monthly*0; 
                break;
       }
       if(changedcl<=0){
       	if(cm == 1 || cm == 2){
       cout<<"It will reach min capacity in : 2 - "<<cy;
       		}
       	else
       		cout<<"It will reach min capacity in : 2 - "<<cy+1;
       }
       else if(changedcl>=1550){
        cout<<"It will reach max capacity in : 8 - "<<cy;
        }
        else{
        if(cm>=3 && cm<=8){
          cl = cl + monthly*(cm+(3-(2*(cm-3))));
         
        }
        yearly = (1550-cl)/yearly;
        cy = cy + yearly;
        yearly = yearly - static_cast<int> (yearly) ;
        yearly = yearly * 12;
        cout<<"It will reach max capacity in : "<<yearly<<" - "<<cy<<endl; 
        }
   }
   if(yearly < 0){
   
   
   
    switch (cm)
        {
        case 3:
        		monthly = inc;
               changedcl = cl + monthly*5;
               break;
        case 4:
        		monthly = inc;
               changedcl = cl + monthly*4;
               break;
        case 5: 
        		monthly = inc;
               changedcl = cl + monthly*3;
               break;
        case 6:
        		monthly = inc;
               changedcl = cl + monthly*2;
               break;
        case 7:
        		monthly = inc;
               changedcl = cl + monthly*1;
               break;
        case 8: 
               monthly = inc;
               changedcl = cl + monthly*0;
               break;
        
        case 9:
        		 monthly = dec;
                changedcl = cl - monthly*5; 
                break;
        case 10:
        		 monthly = dec;
                 changedcl = cl - monthly*4; 
                 break;
        case 11:
         		monthly = dec;
                changedcl = cl - monthly*3; 
                break;
        case 12:
        		 monthly = dec;
                changedcl = cl - monthly*2; 
                break;
        case 1:
   		 		monthly = dec;
                changedcl = cl - monthly*1; 
                break;
        case 2:
        		monthly = dec;
                changedcl = cl - monthly*0; 
                break;
       }
       if(changedcl<=0){
       	
       	if(cm == 1 || cm == 2){
       cout<<"It will reach min capacity in : 2 - "<<cy;
       		}
       	else
       		cout<<"It will reach min capacity in : 2 - "<<cy+1;
       }
       else if(changedcl>=1550){
        cout<<"It will reach max capacity in : 8 - "<<cy;
        }
        else{
        if(cm>=3 && cm<=8){
          cl = cl + monthly*(cm+(3-(2*(cm-3))));
         
        }
        yearly = -1*yearly; 						//since yearly change would be -ive convert that into +ive for calculations
        yearly = (cl)/yearly;						//division can give us the integer number of years that need to be added in current year
        cy = cy - yearly;
        yearly = yearly - static_cast<int> (yearly) ;
        yearly = yearly * 12;
        cout<<"It will reach max capacity in : "<<yearly<<" - "<<cy<<endl; 
        }
  /* 
       
       	else{	   
       
        yearly= -1*yearly;
  
        yearly = (cl)/yearly;
       
        cy = cy + static_cast<int> (yearly);
        yearly= yearly - static_cast<int> (yearly) ;
        yearly= yearly*10;
        yearly =(cm + (static_cast<int>(yearly) * 12)) %12;
        cout<<"It will reach min capacity in : "<<yearly<<" - "<<cy<<endl;
        } */
   }
    
  
}

