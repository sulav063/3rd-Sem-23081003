#include<iostream>
//#include<cmath>
using namespace std;

void calculate(float Ynew[],float X[],int i,int counter){
    for(int k=0;k<counter-i-1;k++){
        Ynew[k]=(Ynew[k+1]-Ynew[k])/(X[k+1+i]-X[k]);
        cout << "Intermediate value at i=" << i << ", k=" << k << ": " << Ynew[k] << ", ";
    }
    cout << endl;
}

float Hero(float x,float X[],int i){
    if(i==-1){
        return 1;
    }else{
        return (x-X[i])*Hero(x,X,i-1);
    }
}

float formula(float data[],int counter, float X[],float Y[],float x){
    float y=Y[0];
    for(int i=0;i<counter;i++){
        cout << "Intermediate value of data[" << i << "]: " << data[i] << endl;
        cout << "Intermediate value of Hero(" << x << ", X, " << i << "): " << Hero(x,X,i) << endl;
        y=y+data[i]*Hero(x,X,i);
        cout << "Intermediate value of y after " << i+1 << " term: " << y << endl;
    }
    return y;
}


int main(){
    int counter;
    cout << "How many points do you want to enter?";
    cin >> counter;
    float x,y,s,h;

    cout << "Enter the value for calculation: ";
    cin >> x;

    float X[counter],Y[counter],Ynew[counter],data[counter];
    for(int i=0;i<counter;i++){
        cout << "value of x" << i << ": ";
        cin >> X[i];
        cout << "value of y" << i << ": ";
        cin >> Y[i];
        Ynew[i]=Y[i];
    }
    data[0]=Y[0];
    for(int i=0;i<counter-1;i++){
        calculate(Ynew,X,i,counter);
        data[i]=Ynew[0];
    }
    
    y=formula(data,counter,X,Y,x);
    cout << "Hence, f(" << x << ")= " << y;
    
    return 0;
}
