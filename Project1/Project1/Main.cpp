/*This program basically is a basically a caesars cipher but instead of
shifting all letters by x it shifts all vowels by a certain value and all
consonants by another. I also have it so there will be a statement that mirrors the
original but only looking at its vowels. An 'a' represents a vowel while
a 'b' is a consonant. This makes it so if you have both pieces along with the shift you 
can properly decode it. Also every third letter is declared a vowel for no other reason
than my happiness and so it can't be cracked as easily by a normal caesars cipher decoder.
I made it from the base of this https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
and altered it from there. I know it is a dumpster fire so I will
add classes and stuff fro my second step.
*/
#include <iostream>
using namespace std;        

string encrypt(string text, int s1, int s2) {
   string result = "";
   string locations = "";

   for (int i = 0; i < text.length(); i++) { /* Gathers the text length*/
       if (char(int(text[i] == 32))) {
           result += " ";
           locations += " ";
       }
       else {
           if (isupper(text[i])) {
               if (i % 3 == 0) {
                   result += char(int(text[i] + s2 - 65) % 26 + 65);
                   locations += "a";
               }
               else {
                   switch (text[i]) {              /* This switch case looks for upper case vowels*/
                   case 65:                                        // If it finds a vowel (all of the case #s) It will add a secondary shift
                       result += char(int(text[i] + s2 - 65) % 26 + 65);
                       locations += "a";                                    //if there is a vowel it will add an a to a locations string 
                       break;
                   case 69:
                       result += char(int(text[i] + s2 - 65) % 26 + 65);
                       locations += "a";
                       break;
                   case 73:
                       result += char(int(text[i] + s2 - 65) % 26 + 65);
                       locations += "a";
                       break;
                   case 79:
                       result += char(int(text[i] + s2 - 65) % 26 + 65);
                       locations += "a";
                       break;
                   case 85:
                       result += char(int(text[i] + s2 - 65) % 26 + 65);
                       locations += "a";
                       break;
                   default:
                       result += char(int(text[i] + s1 - 65) % 26 + 65);
                       locations += "b";                                       // If there is a consonant it will add a b
                       break;
                   }
               }
           }

           else {

               if (i % 3 == 0) {
                   result += char(int(text[i] + s2 - 97) % 26 + 97);
                   locations += "a";
               }
               else {
                   switch (text[i]) {
                   case 97:
                       result += char(int(text[i] + s2 - 97) % 26 + 97);
                       locations += "a";
                       break;
                   case 101:
                       result += char(int(text[i] + s2 - 97) % 26 + 97);
                       locations += "a";
                       break;
                   case 105:
                       result += char(int(text[i] + s2 - 97) % 26 + 97);
                       locations += "a";
                       break;
                   case 111:
                       result += char(int(text[i] + s2 - 97) % 26 + 97);
                       locations += "a";
                       break;
                   case 117:
                       result += char(int(text[i] + s2 - 97) % 26 + 97);
                       locations += "a";
                       break;
                   default:
                       result += char(int(text[i] + s1 - 97) % 26 + 97);
                       locations += "b";
                       break;
                   }
               }
           }
       }
   }
    result += "\n" + locations;
    return result;
}


int main() {
    string text = "Hello World";
    int s1 = 5;
    int s2 = 13;
    cout << "Text : " << text;
    cout << "\nNormal Shift: " << s1;
    cout << "\nVowel Shift: " << s2;
    cout << "\nCipher: " << encrypt(text, s1, s2);
    return 0;

}
