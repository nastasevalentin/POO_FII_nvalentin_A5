#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


string lower_string(const string& str) {
  string ret;

  for (int i = 0; i < str.size(); i++) {
    ret.push_back(tolower(str[i]));
  }

  return ret;
}


vector<string> cut_into_words(const string& str) {
  vector<string> v;
  string separators = " ?!.,";

  string current;
  for (int i = 0; i < str.size(); i++) {
    if (separators.find_first_of(str[i]) != string::npos) {

        if (!current.empty())
        {
            
            v.push_back(lower_string(current));
        }
        current = "";
        continue;
    }
    current.push_back(str[i]);
  }

  return v;
}



int main (){


   ifstream file("fisier.txt");

  string input;
  getline(file, input);

  vector<string> words = cut_into_words(input);
  map<string, int> word_map;

  for (string word : words) {
    word_map[word]++;
    //cout << "Word: " << word << endl;
  }

  for (auto const &pair: word_map) {
        cout << "\"" << pair.first << "\"" << " => " << pair.second << "\n";
    }
}