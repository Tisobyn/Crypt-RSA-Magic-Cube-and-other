//
//  main.cpp
//  shifrs
//
//  Created by Yermek Sabyrzhan on 05.09.17.
//  Copyright © 2017 Yermek Sabyrzhan. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<stdio.h>
#include<string.h>

using namespace std;

void Cesar(string text){
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string encode;
    int sdvig;
    cout << "please inter a sdvig" << endl;
    cin >> sdvig;
    
    for(int i = 0; i < alphabet.length(); i++){
        alphabet[i] = (char)toupper(alphabet[i]);
    }
    
    for(int i = 0; i < text.length(); i++){
        for(int j = 0; j < alphabet.length(); j++){
            if(text[i] == alphabet[j]){
                    int temp = 0;
                    temp = j + sdvig;
                    if(temp > 25) temp = temp - 26;
                    encode.push_back(alphabet[temp]);
                
            }
        }
    }
    
    cout << encode << endl;
}

void MagicCube(string text){
    // надо найти квадрат ахв
    int magicSquare[1000][1000];
    int n = 0;
    int lenght = text.length();
    while( n*n < lenght) n++;
    // надо найти чему должна быть равна столбик диогональ столбец
    int w = (n*(n*n +1))/2;
    // магический квадрат генеризация
    memset(magicSquare, 0, sizeof(magicSquare));
    
    int i = n/2;
    int j = n-1;
    
//     1. The position of next number is calculated by decrementing row number of previous number by 1, and incrementing
//      the column number of previous number by 1. At any time, if the calculated row position becomes -1, it will wrap around
//      to n-1. Similarly, if the calculated column position becomes n, it will wrap around to 0.
//
//     2. If the magic square already contains a number at the calculated position, calculated column
//       position will be decremented by 2, and calculated row position will be incremented by 1.
//
//     3. If the calculated row position is -1 & calculated column position is n, the new position would be: (0, n-2).
    
    for (int num=1; num <= n*n; )
    {
        if (i==-1 && j==n) //3rd condition
        {
            j = n-2;
            i = 0;
        }
        else
        {
            //1st condition
     
            if (j == n)
                j = 0;
          
            if (i < 0)
                i=n-1;
        }
        if (magicSquare[i][j]) //2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++; //set number
        
        j++; i--; //1st condition
        
    }
    
    // Print magic square
    string crypted = "";
    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",
           n, w);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++){
            
            printf("%3d ", magicSquare[i][j]);
            crypted.push_back(text[(magicSquare[i][j] -1)]);
        }
        printf("\n");
    }
    
    cout << crypted << endl;
}


void Visionar(string text){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < alphabet.length(); i++){
        alphabet[i] = (char)toupper(alphabet[i]);
    }
    string crypted;
    string key;
    int k;
    cout << "Insert a key" << endl;
    cin >> key;
    k = key.length();
    int alp = alphabet.length();
    int t = text.length();
    
    for (int i=k; i<t; i++){
        key=key+key[i%k];
    }
    cout << "Key is: " << key << endl;
    k = key.length();
    string  str[26][26];
    
    
    for(int i = 0; i < 26; i ++){
        for(int j = 0; j < 26; j++){
            if((j+i) >25)
                str[i][j] = alphabet[(j+i)-26];
            else
                str[i][j] = alphabet[j+i];
            cout << str[i][j] << " ";
        }
        cout << endl;
    }
    
    int ind1,ind2;

    
    for (int i=0; i<k; i++){
        ind1=alphabet.find(text[i]);
        ind2=alphabet.find(key[i]);
        crypted.push_back(alphabet[(ind1 + ind2)%26]);
    }

    cout << crypted << endl;
    

}



int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
void RSA(string text){
    
    char temp[1024];
    int  msg[1024];
    strcpy(temp, text.c_str());
    int len = text.length();

    for(int i = 0; i < len ; i++){
        msg[i] = temp[i];
        msg[i] = msg[i] - 65;
    }
    cout << endl;
    
    double p = 3;
    double q = 7;
    
    // First part of public key:
    double n = p*q;
    
    // Finding other part of public key.
    // e stands for encrypt
    double e = 2;
    double phi = (p-1)*(q-1);
    
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }
    
    // Private key (d stands for decrypt)
    int k = 2;  // A constant value
    double d = (1 + (k*phi))/e;
    
    // Message to be encrypted
    cout << "Message data is :" ;
    for(int i = 0; i < len ; i++) cout << msg[i] << " " ;
    cout << endl;
    // Encryption c = (msg ^ e) % n
    
    double c[1024];
    double m[1024];
    
    for(int i = 0; i < len ; i++){
        c[i] = pow(msg[i], e);
        m[i] = pow(c[i], d);
    }
    
    for(int i = 0; i < len ; i++){
        c[i] = fmod(c[i], n);
        m[i] = fmod(m[i], n);
    }
    
    cout << "Encrypted data : ";
    for(int i = 0; i < len ; i++) cout << c[i];
    cout << endl;
    
}

int main() {
    string text = "";
    int c = 0 ;
     cout << "Write the text: " << endl;
    cin >> text;
   
    for(int i = 0; i < text.length(); i++){
        text[i] = (char)toupper(text[i]);
    }
    
    
    cout << " choose method of encoding" << endl;
    cout << " 1. Cesar. " << endl;
    cout << " 2. Magic cube. IF text is longer than 25 simvol it doesn't work" << endl;
    cout << " 3. Visionar" << endl;
    cout << " 4. RSA"<< endl;

    
    
        cout << "Change a number: " << endl;
        cin  >> c;
        switch(c){
            case 1: Cesar(text);  break;
            case 2: MagicCube(text); break;
            case 3: Visionar(text); break;
            case 4: RSA(text); break;
            
            default: cout << " You choose incorrect number. YOu can choose only 1, 2 or 3" << endl;
    
        }
    
    
    return 0;
}
