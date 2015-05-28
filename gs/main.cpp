#include <iostream>
#include <fstream>

#include <string>
#include <map>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("input.txt");
    if (!infile)
        cerr << "Error: unable to open input file!" << endl;

    map<string, int> word_cnt;
    string line, word;
    while(getline(infile, line)) {
        istringstream stream(line);
        while (stream >> word)
            ++word_cnt[word];
    }
    infile.close();

    ofstream file("output.txt");
    map<string, int>::const_iterator
                            map_it = word_cnt.begin();
    while (map_it != word_cnt.end()) {
        if (map_it->second == 1)
            file << map_it->first << " occur " << map_it->second
                 << " time" << endl;
        else
            file << map_it->first << " occurs " << map_it->second
                 << " times" << endl;
        ++map_it;
    }
    file.close();

    return 0;
}
