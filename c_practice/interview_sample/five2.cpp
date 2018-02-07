#include <string> // for storing strings in a C++ way
#include <sstream> // to easily separate sentences into words
#include <vector> // to dynamically store arbitrary amounts of words
#include <algorithm> // for std::reverse
#include <iostream> // for printing the result
using namespace std;
 
int main()
{
string sentence = "Your sentence which contains ten words, two of them numbers";
stringstream stream(sentence);
string word;
vector<string> words;
while ( stream >> word )
{
	words.push_back(word);
}
//reverse(words.begin(), words.end());
for ( size_t i(0); i < words.size(); ++i )
{
	cout << words[i] << " ";
}
cout << "\n";
}
