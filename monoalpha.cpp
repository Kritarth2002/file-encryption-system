//============================================================================
// Name        : Monoalphabetic Cipher.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*

plain:  a b c d e f g h i j k l m n o p q r s t u v w x y z
cipher: D E F G H I J K L M N O P Q R S T U V W X Y Z A B C

If, instead, the "cipher" line can be any permutation of the 26 alphabetic characters,
then there are 26! or greater than 4 * 10^26 possible keys. This is 10 orders of magnitude
greater than the key space for DES and would seem to eliminate brute-force
techniques for cryptanalysis. 

Such an approach is referred to as a monoalphabetic
substitution cipher, because a single cipher alphabet (mapping from plain alphabet
to cipher alphabet) is used per message.
*/
//============================================================================

#include<bits/stdc++.h>
using namespace std;
string readPlainText()
{
	ifstream fin;
	string ptext;

	fin.open("plaintext.txt");
	fin >> ptext;
	fin.close();

	return ptext;
}

/* write cipher text to ciphertext.txt file */
void writecipherText(string ctext)
{
	ofstream fout;
	fout.open("ciphertext.txt");
	fout << ctext;
	fout.close();
}
void writedecryptText(string ctext)
{
	ofstream fout;
	fout.open("decryptedtext.txt");
	fout << ctext;
	fout.close();
}

string Monoalphabetic_Cipher_encryption(string message){
	int n = message.length(),temp;
	string key="FDSAVCXZGHJKLREWQTYUIOPMNB";
	string ency="";
	for(int i=0;i<n;++i){
		temp = message[i]-'a';
		ency+=key[temp];
	}
	return ency;
}

string Monoalphabetic_Cipher_decryption(string message){
	int n = message.length(),temp;
	string key = "dzfboaijuklmxyvwqncrtepgsh";
	string ency="";
	for(int i=0;i<n;++i){
		temp = message[i]-'A';
		ency+=key[temp];
	}
	return ency;
}
int main(){
	string s= readPlainText() ;
  cout<<s;
	string p = Monoalphabetic_Cipher_encryption(s);
	cout<<"Monoalphabetic_Cipher_encryption :"<<p<<"\n";
  writecipherText(p);
	cout<<"Monoalphabetic_Cipher_decryption: "<<Monoalphabetic_Cipher_decryption(p)<<"\n";
  writedecryptText(Monoalphabetic_Cipher_decryption(p));
	system("pause");
	return 0;
}