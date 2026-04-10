#include <bits/stdc++.h>
using namespace std;


int main(){
    int state[4][4];
    int key[4][4];

    //taking the input

    cout << "enter the state matix : " << endl;
    for(int i= 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin >> state[i][j];
        }
    }


    cout << "enter the key matrix : " << endl;
    for(int i= 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin >> key[i][j];
        }
    }

    //now first we do using sbox 
    int sbox[16] = {14,15,5,10,3,4,13,2,1,7,9,11,8,12,0,6};

    //first we do sbox swap ;

    for(int i= 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            state[i][j] = sbox[state[i][j] % 16];
        }
    }

    //now we shift rows
    for(int i = 1 ; i < 4 ; i++){
        int temp[4];
        for(int j = 0 ; j < 4 ; j++){
            temp[j] = state[i][(j+i)%4];
        }

        for(int j = 0 ; j < 4 ; j++){
            state[i][j] = temp[j];
        }
    }


    //mix coloums
    for(int j= 0 ; j < 4 ; j++){
        int a = state[0][j] ^ state[1][j] ^ state[2][j] ^ state[3][j];

        for(int i = 0 ; i < 4 ; i++){
            state[i][j] = a ^ state[i][j];
        }
    }


    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            state[i][j] = key[i][j] ^ state[i][j];
        }
    }



    //answer
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cout << state[i][j] << " ";
        }

        cout << endl;
    }
}
