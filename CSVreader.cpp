#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Country {
    string name;
    string region;
    long long population;
    double area;
    double gdp;
    double education;
};

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<Country> readCountries(const string &filename) {
    vector<Country> countries;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return countries;
    }

    string line;
    getline(file, line);
    
    while (getline(file, line)) {
        vector<string> tokens = split(line, ';');
        if (tokens.size() >= 6) {
            Country country;
            country.name = tokens[0];
            country.region = tokens[1];
            country.population = stoll(tokens[2]);
            country.area = stod(tokens[3]);
            country.gdp = stod(tokens[4]);
            country.education = stod(tokens[5]);
            countries.push_back(country);
        }
    }
    
    return countries;
}

void writeResults(const string &filename, const vector<string> &countryNames) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not create file " << filename << endl;
        return;
    }
    
    for (const auto &name : countryNames) {
        file << name << endl;
    }
}

int main() {
    // Read data from input file
    vector<Country> countries = readCountries("input.txt");
    
    // Filter countries
    vector<string> bigCountries;
    for (const auto &country : countries) {
        if (country.population > 25000000 || country.area > 3000000) {
            bigCountries.push_back(country.name);
        }
    }
    
    // Sort country names alphabetically
    sort(bigCountries.begin(), bigCountries.end());
    
    // Write results to output file
    writeResults("output.txt", bigCountries);
    
    cout << "Processing complete. Results written to output.txt" << endl;
    return 0;
}