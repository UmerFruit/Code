#include "Headers.h"
int main()
{
    string sym = " + ";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    if(i+j+k+l == 10)
                    {
                        cout<<i<<sym<<j<<sym<<k<<sym<<l<<endl;
                    }
                }
                
            }
            
        }
        
    }
    
}