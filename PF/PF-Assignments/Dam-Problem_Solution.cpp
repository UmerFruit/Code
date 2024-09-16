/*
Made by: Riyan Aslam

*/
#include<iostream>

using namespace std;

int main()
{
    const int MAX = 1550;
    const int MIN = 0;
    int curr=0, m=0, y=0, inc=0, dec=0;
    bool increasing,reached=false;
    float req_months=0, req_years=0;
    

    
    cout << "Enter Current Level of the Dam: ";
    cin >> curr;
    
    cout << "Enter Current Month: ";
    cin >> m;
    
    cout << "Enter Current Year: ";
    cin >> y;
    
    cout << "Enter Increase Rate: ";
    cin >> inc;
    
    cout << "Enter Decrease Rate: ";
    cin >> dec;
    
    //checking for curent season.
    
    //increase during summer 3,4,5,6,7,8
    //decrease during winter 9,10,11,12,01,02
    
    if ( m >= 3 && m <= 8) {
        
        req_months = (MAX - curr)/static_cast<float>(inc);
        increasing = false;
        
        if ( req_months <= 9-m){
            reached = true;
            curr += ((9-m)*inc);
            m += req_months;
            y += m/13;
            m %= 13;
            
        } else {
            curr += ((9-m)*inc);
            m = 9;
        }
        
    } else {
        
        req_months = (curr - MIN)/static_cast<float>(dec);
        increasing = true;
        
        if ( req_months <= (14-m)%12){
            reached = true;
            curr -= (((14-m)%12)*dec);
            m += req_months;
            y += m/13;
            m %= 13;
            
        } else {
            curr -= (((14-m)%12)*dec);
            if (m != 1 || m!= 2)
                y++;
            m = 3;
        }
    }
        
    // checking how many years till it reaches its max or min.
    //cout << "M: " << m << endl << "Y:" <<  y << endl <<  "Curr: " << curr << endl;
        
    int annualRate = (inc*6) - (dec*6);
    
    if (!reached) {
        
        if (annualRate > 0){
            
            req_years = (MAX - curr)/static_cast<float>(annualRate);
            y += req_years;
            curr += annualRate * int(req_years);
            
        } else {
            
            annualRate *= -1;
            
            req_years = (curr - MIN)/static_cast<float>(annualRate);
            y += req_years;
            curr -= annualRate * int(req_years);
            
            
            
        }
        
        
    }
    
    
    //cout << "M: " << m << endl << "Y:" <<  y << endl <<  "Curr: " << curr << endl;
    
    //determining which season it reaches full.
    if (!reached) {
        if ( m >= 3 && m <= 8) {
            
            req_months = (MAX - curr)/static_cast<float>(inc);
            increasing = false;
            
            if ( req_months <= 9-m){
                reached = true;
                
                curr += ((9-m)*inc);
                m += req_months;
                y += m/13;
                m %= 13;
                
            } else {
                curr += ((9-m)*inc);
                m = 9;
            }
            
        } else {
            
            req_months = (curr - MIN)/static_cast<float>(dec);
            increasing = true;
            
            if ( req_months <= (14-m)%12){
                reached = true;
                
                curr -= (((14-m)%12)*dec);
                m += req_months;
                y += m/13;
                m %= 13;
                
            } else {
                curr -= (((14-m)%12)*dec);
                if (m != 1 || m!= 2)
                    y++;
                m = 3;
            }
        }
    }
    
    
    // incase it didnt reached its max or min within 6 months.
    if (!reached) {
        if ( m >= 3 && m <= 8) {
            
            req_months = (MAX - curr)/static_cast<float>(inc);
            increasing = false;
            
            if ( req_months <= 9-m){
                reached = true;
                
                curr += ((9-m)*inc);
                m += req_months;
                y += m/13;
                m %= 13;
                
            } else {
                curr += ((9-m)*inc);
                m = 9;
            }
            
        } else {
            
            req_months = (curr - MIN)/static_cast<float>(dec);
            increasing = true;
            
            if ( req_months <= (14-m)%12){
                reached = true;
                
                curr -= (((14-m)%12)*dec);
                m += req_months;
                y += m/13;
                m %= 13;
                
            } else {
                curr -= (((14-m)%12)*dec);
                if (m != 1 || m!= 2)
                    y++;
                m = 2;
            }
        }
    }
    
    if (curr>MAX)
    {
        cout<<"The dam will reach its maximum capacity in ";
        cout<<m<<"-"<<y;
    }
    else if (curr <= MIN)
    {
        cout<<"The dam will reach zero level in ";
        cout<<m<<"-"<<y+req_years;
    }
    cout << endl;
    return 0;
}

