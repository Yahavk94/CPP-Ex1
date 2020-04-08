#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace std;

int main() {
	string text = "Dond vorri be haffy";
	cout << phonetic::find(text, "dont") << endl; // Should print "Dond"
	cout << phonetic::find(text, "worry") << endl; // Should print "vorri"
	cout << phonetic::find(text, "Be") << endl; // Should print "be"
	cout << phonetic::find(text, "happy") << endl; // Should print "haffy"
	try {
		cout << phonetic::find(text, "happ") << endl; // Should throw an exception - "happ" is not a full word in the sentence
	} catch (exception &ex) {
	 	cout << "caught exception: " << ex.what() << endl; // Should print "Did not find the word 'happ' in the text"
	}
}