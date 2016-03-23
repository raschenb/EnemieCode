
#include <iostream>
#include <string>

using namespace std;

 int main(int argc, char * argv[])
 {
 string decryptedString(const string& secret, int key);

 string secretMsg = ":mmZ\\dxZmx]Zpgy"; // Coded message

 for (int key = 1; key < 101; ++key) // Loop key 1-100
 {
 cout << "Key " << key << " - " << decryptedString(secretMsg, key) << endl; // show key numer used and if that key decoded message to make since
 }
 
 cout << endl;
 cin.get();
 return 0;
 }

 //---------------------------------------------------------
 bool filter(const char &chr)
 {
 return (toupper(chr) >= 'A' && toupper(chr) <= 'Z') || //a-z A-Z
 (chr >= '0' && chr <= '9') || //0-9
 (chr == ' ' || chr == '\t' || chr == '\n') || //white spaces
 (chr == ',' || chr == '.' || //punctuations
 chr == ':' || chr == ';' ||
 chr == '\'' || chr == '\"' ||
 chr == '?' || chr == '!');
 } 
 //---------------------------------------------------------
 string decryptedString(const string& secret, int key)
 {
 string decoder = "";
 for (int i = 0; i <= secret.length(); i++) // Loop using key
 {
 if (filter(secret[i] - key))
 decoder += secret[i] - key;
 else if (filter(secret[i] - key + 127 - 32))
 decoder += secret[i] - key + 127 - 32;
 }
 if (decoder.length() == secret.length()) //All encrypted chars must be decrypted
 return decoder;
 return decoder = "";
 }