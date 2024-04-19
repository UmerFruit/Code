/*
    Name: Umer Farooq
    Student-ID: 22I-0518
    Assignment #1
*/
#include<iostream>
#include<cmath>
using namespace std;
int**** init(int dim);
void print_reward_locations(int**** grid, int dim);         
void print_distance(int**** grid,int dim,int x,int y,int z);
void dealocate(int**** grid, int dim);
void play_game(int**** grid, int dim);
int main()
{
    int choice;         //choice for menu
    int dim;            //dimension of grid
    int**** grid;       //grid array
    do
    {
        cout<<"Choose one of the following\n1: Initialize\n2: Print Rewards\n3: Play Game\n4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1: 
            cout<<"Enter Dimension for the grid"<<endl;         //dimension initialize
            cin>>dim;
            while(dim<0)
            {
                cout<<"Enter again. Invalid dimension"<<endl;
                cin>>dim;                                       //input validation
            }
            grid = init(dim);                                   //set rewards and initialize grid
            break;
        case 2:
            print_reward_locations(grid,dim);               //print reward locations
            break;
        case 3:
            play_game(grid,dim);                        //start game
            break;
        case 4:
            break;                                      //exit
        default:
            cout<<"Invalid input!\nEnter number from 1 to 4"<<endl;
            break; 
        }
    }while(choice != 4);
    dealocate(grid,dim);                //after ending game deallocate all memory
}
int**** init(int dim)
{
    srand(time(0));
    int**** grid= new int*** [dim];
    
    for(int i=0;i<dim;i++)
    {
        *(grid+i) = new int**[dim];
        for(int j=0;j<dim;j++)                      //initialize 4D array
        {
            *(*(grid+i)+j) = new int*[dim];
            
            for(int k=0;k<dim;k++)
                *(*(*(grid+i)+j)+k) = new int [3];
            
        }
    }
    for(int i=0; i<dim; i++)
        for(int j=0; j<dim; j++)
            for(int k=0; k<dim; k++)                //initialize all values in array to 0
                for(int l=0; l<3; l++)
                    *(*(*(*(grid+i)+j)+k)+l)=0;
    int check=0;
    int percent= (dim*dim*dim*3)*(0.4);           //calc 40% of array
    while(check!=percent)
    {
        int n1 = rand()%dim;
        int n2 = rand()%dim;
        int n3 = rand()%dim;
        int n4 = rand()%3;
        if( *(*(*(*(grid+n1)+n2)+n3)+n4) == 0 )    //run loop 40% times to put rewards in random locations
        {
            *(*(*(*(grid+n1)+n2)+n3)+n4)=1;
            check++;
        }   
    }
    return grid;
}
void print_reward_locations(int**** grid,int dim)
{
    int numrewards=0;
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            for(int k=0;k<dim;k++)
                for(int l=0;l<3;l++)                            //printing reward locations
                    if( *(*(*(*(grid+i)+j)+k)+l) == 1)
                    {
                        cout<<"Reward_"<<++numrewards<<":"<<i<<","<<j<<","<<k<<",";
                        switch(l)
                        {
                            case 0: cout<<"PAST"<<endl;    break;
                            case 1: cout<<"PRESENT"<<endl; break;
                            case 2: cout<<"FUTURE"<<endl;  break;
                        }
                    }
}
void print_distance(int**** grid,int dim,int x,int y,int z)
{
    int c=0;
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                for(int k=0;k<dim;k++)              //print distance from each reward
                    for(int l=0;l<3;l++)
                        if( *(*(*(*(grid+i)+j)+k)+l) == 1)
                        {
                            int distance = sqrt(pow(x-i,2) + pow(y-j,2) + pow(z-k,2));
                            cout<<"Reward_"<<++c<<":"<<"Distance is "<<distance<<endl;
                        }
}
void dealocate(int**** grid, int dim)
{
    for(int i=0;i<dim;i++)
    { 
        for(int j=0;j<dim;j++)
        {
            for(int k=0;k<dim;k++)
            {
                delete[] *(*(*(grid+i)+j)+k);
                *(*(*(grid+i)+j)+k)= NULL;
            }
            delete[] *(*(grid+i)+j);            //deallocate all memory
            *(*(grid+i)+j)= NULL;
        }
        delete[] *(grid+i);
        *(grid+i) = NULL;
    }
    delete[] grid;
    grid = NULL;
}
void play_game(int**** grid, int dim)
{
    int x,y,z,t;
    int moves;          //moves for game
    float tscore=0;     //total score

    cout<<"How many moves do you want to play?"<<endl;          //initialize moves
    cin>>moves;
    while(moves<0)                      
    {
        cout<<"Invalid! Enter atleast 0 moves"<<endl;
        cin>>moves;
    }
    cout<<"Enter your coordinates in X Y Z TIME format where:"<<endl;
    cout<<"0 for time is PAST\n"
    <<"1 for time is PRESENT\n"             //instructions
    <<"2 for time is FUTURE\n";
    for(int i=0;i<moves;i++)
    {
        float score;
        cout<<"Enter your point (cordinates seperated by spaces)"<<endl;        //input coordinates
        cin>>x>>y>>z>>t;

        while ((x<0 || x>=dim) || (y<0 || y>=dim) || (z<0 || z>=dim) || (t<0 || t>2))
        {
            cout<<"Enter again. Invalid Coordinates"<<endl;
            cin>>x>>y>>z>>t;
        }
        if( *(*(*(*(grid+x)+y)+z)+t) == 1)
        {
            cout<<"Congratulations! You guessed correctly."<<endl;         
            score = 1;                                      
            *(*(*(*(grid+x)+y)+z)+t) = 0;           //remove reward after correct guess
        }
        
        else if( *(*(*(*(grid+x)+y)+z)+0) == 1 || *(*(*(*(grid+x)+y)+z)+1) == 1 || *(*(*(*(grid+x)+y)+z)+2) == 1)
            {
                cout<<"YAY! You guessed the half correctly. Time was different."<<endl;
                score = 0.5;
                *(*(*(*(grid+x)+y)+z)+0) = 0;
                *(*(*(*(grid+x)+y)+z)+1) = 0; //remove rewards from all times after half correct guess      
                *(*(*(*(grid+x)+y)+z)+2) = 0;
            }
        print_distance(grid,dim,x,y,z);
        tscore += score;            //total score 
        
        cout<<"Score(This move) : "<<score<<endl;
        cout<<"Total Score : "<<tscore<<endl;
        score = 0;                  //reinitalize to 0 for score of only next move
    }   
    cout<<"GAME OVER!\nYour total score is "<<tscore<<endl;
}