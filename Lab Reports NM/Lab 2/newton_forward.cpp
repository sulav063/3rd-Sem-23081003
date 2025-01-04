//Forward
#include<iostream>
#include<cmath>
using namespace std;

void calculate(float Ynew[], int i, int counter){
    for(int k = 0; k < counter - i - 1; k++){
        Ynew[k] = Ynew[k + 1] - Ynew[k];
    }
}

float Hero(float s, int i){
    if(i == 0){
        return 1;
    } else if(i == 1){
        return s;
    } else {
        return Hero(s, i - 1) * (s - i + 1) / tgamma(i + 1);
    }
}

float formula(float data[], int counter, float s, float X[], float h){
    float y = 0;
    for(int i = 0; i < counter; i++){
        y += Hero((s - X[0]) / h, i) * data[i];
    }
    return y;
}

int main(){
    int counter;
    cout << "How many points do you want to enter? ";
    cin >> counter;
    float x, s, h;
    cout << "Enter the value for calculation: ";
    cin >> x;
    float X[counter], Y[counter], Ynew[counter], data[counter];
    for(int i = 0; i < counter; i++){
        cout << "value of x" << i << ": ";
        cin >> X[i];
        cout << "value of y" << i << ": ";
        cin >> Y[i];
        Ynew[i] = Y[i];
    }
    h = X[1] - X[0];
    s = (x - X[0]) / h;
    data[0] = Y[0];
    for(int i = 0; i < counter - 1; i++){
        calculate(Ynew, i, counter);
        data[i + 1] = Ynew[0];
    }
    float y = formula(data, counter, s, X, h);
    cout << "Hence, f(" << x << ") = " << y;

    return 0;
}
