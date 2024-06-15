#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

// Function to generate a single test case and its expected output
void generateTestCase(ofstream& testcaseFile, ofstream& outputfile, int n, int maxValue) {
    testcaseFile << n << endl;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = rand() % maxValue + 1;
        testcaseFile << a[i] << " ";
    }
    testcaseFile << endl;

    // Calculate the expected output
    long long expected_output = 0;
    map<int, long long> mp;
    for (int i = 1; i <= n; i++) {
        expected_output += mp[a[i]] * (n - i + 1);
        mp[a[i]] += i;
    }

    outputfile << expected_output << endl;
}

int main() {
    srand(time(0)); 

    int t = 100; 
    int maxN = 10000; 
    int maxValue = 10000000; 

    ofstream testcaseFile("testcases.txt");
    ofstream outputfile("expected_output.txt");

    testcaseFile << t << endl;
    for (int i = 0; i < t; i++) {
        int n = rand() % maxN + 1; 
        generateTestCase(testcaseFile, outputfile, n, maxValue);
    }

    testcaseFile.close();
    outputfile.close();

    cout << "Test cases generated and saved in testcases.txt" << endl;
    cout << "Expected outputs saved in expected_output.txt" << endl;

    return 0;
}
