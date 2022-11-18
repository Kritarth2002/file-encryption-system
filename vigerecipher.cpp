// C++ code to implement Vigenere Cipher
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




string generateKey(string str, string key)
{
    int x = str.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
 
// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        cipher_text.push_back(x);
    }
    return cipher_text;
}
 
// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}
 
// Driver program to test the above function
int main()
{
    string str = readPlainText();
    string keyword;
    cout<<"enter keyword to generate key";
    cin>>keyword;
 
    string key = generateKey(str, keyword);
    string cipher_text = cipherText(str, key);
    writecipherText(cipher_text);
    cout << "Ciphertext : "
         << cipher_text << "\n";
  
    cout << "Original/Decrypted Text : "
         << originalText(cipher_text, key);
    writedecryptText(originalText(cipher_text, key));
    return 0;
}