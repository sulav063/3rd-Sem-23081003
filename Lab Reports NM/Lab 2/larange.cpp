//Lagrange Interpolation
#include<iostream>
using namespace std;
float upper(int i,float X[],float Y[],float x,int counter){
    float result=1;
    for(int steps=0;steps<counter;steps++){
        if(i==steps){
        continue;
        } else{
            result=result*(x-X[steps]);
        }
    }
    cout<<"Upper: "<<result<<endl;
    return result;
}

float lower(int i,float X[],float Y[],float x,int counter){
    float result=1;                   
    x=X[i];
    for(int steps=0;steps<counter;steps++){
        if(i==steps){
            continue;
        } else{
            result=result*(x-X[steps]);
        }
    }
    cout<<"Lower: "<<result<<endl;
    return result;
}

int main(){
    int counter;
    cout<<"How many points do you want to enter?";
    cin>>counter;
    float x,y;
    cout<<"Enter the value for calculation: ";
    cin>>x;
    float X[counter],Y[counter];
    for(int i=0;i<counter;i++){
        cout<<"value of x"<<i<<": ";
        cin>>X[i];
        cout<<"value of y"<<i<<": ";
        cin>>Y[i];
    }
    
    for(int i=0;i<counter;i++){
        y=y+(upper(i,X,Y,x,counter)/lower(i,X,Y,x,counter))*Y[i];  
    }
    
    cout<<"Final Output: "<<y;
    return 0;
}