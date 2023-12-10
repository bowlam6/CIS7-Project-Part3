#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int main() {

  // Declare variables
  char message[100];
  string key = "AYUSH";
  string encrypted;
  string decrypted;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // Map such that key is an alphabetiocal character and value is a number
  map<char, int> dict1;
  for (int i = 0; i < alphabet.size(); i++) { 
   dict1[alphabet[i]] = i ;
  }

  // Map such that key is a number and value is an alphabetical character
  map<int, char> dict2;
  for (int i = 0; i < alphabet.size(); i++) { 
    dict2[i] = alphabet[i];
  }

  // Warn user of input criteria
  cout << "WARNING: Messages must contain alphabetical characters ONLY." << endl;
  
  // Prompt user input for encryption
  cout << "Enter a message to encrypt: ";
  cin.getline(message, 100);

  // Convert input message to uppercase
  for (int i = 0; i < strlen(message); i++) {
      message[i] = toupper(message[i]);
  }

  // Compute encryption
  for (int i =0; i < strlen(message); i++) {
    int plainText = dict1[message[i]];
    int keyText = dict1[key[i % key.size()]];
    int encryptedVal = (plainText + keyText) % 26;
    encrypted += dict2[encryptedVal];
  }

  // Print encrypted message
  cout << "The message after encryption is: " << encrypted << endl;

  // Prompt user input for decryption
  cout << "Enter a message to decrypt: ";
  cin.getline(message, 100);

  // Convert input message to uppercase
  for (int i = 0; i < strlen(message); i++) {
      message[i] = toupper(message[i]);
  }

  // Compute decryption
  for (int i =0; i < strlen(message); i++) {
    int plainText = dict1[message[i]];
    int keyText = dict1[key[i % key.size()]];
    int decryptedVal = (plainText - keyText + 26) % 26;
    decrypted += dict2[decryptedVal];
  }

  // Print decrypted message
  cout << "The message after decryptuon is: " << decrypted << endl;
}

