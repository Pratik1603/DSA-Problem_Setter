#include <bits/stdc++.h>
using namespace std;

// Function to generate a test case
void generateTestCase(ofstream& testcaseFile, int maxLen) {
    int lenS = rand() % maxLen + 1; // Length of string s (1 ≤ lenS ≤ maxLen)
    int lenT = rand() % maxLen + 1; // Length of string t (1 ≤ lenT ≤ maxLen)
    
    string s = "";
    string t = "";
    
    for (int i = 0; i < lenS; ++i) {
        s += (rand() % 2) + '0';
    }
    
    for (int i = 0; i < lenT; ++i) {
        t += (rand() % 2) + '0';
    }
    
    testcaseFile << s << " " << t << endl;
}

// Function to solve the problem
string solve(string S, string T) {
    int cnt[2] = {0, 0};
    int A[514514] = {0};

    for (char c : S) {
        cnt[c - '0']++;
    }

    A[0] = -1;
    int j = -1;
    for (int i = 0; i < T.size(); i++) {
        while (j >= 0 && T[i] != T[j]) j = A[j];
        j++;
        A[i + 1] = j;
    }

    int M = T.size();
    int k = M - A[M];
    string ans;
    while (1) {
        bool fail = false;
        for (int i = 0; i < k; i++) {
            char c = T[i];
            if (cnt[c - '0'] == 0) {
                fail = true;
                break;
            }

            cnt[c - '0']--;
            ans += c;
        }

        if (fail) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    ans += char('0' + i);
                }
            }
            break;
        }
    }
    return ans;
}

int main() {
    srand(time(0)); // Seed for random number generation

    ofstream testcaseFile("testcases.txt");
    ofstream outputfile("expected_output.txt");

    int t = 100; // Number of test cases
    int maxLen = 1000; // Maximum length for s and t

    testcaseFile << t << endl;
    for (int i = 0; i < t; ++i) {
        generateTestCase(testcaseFile, maxLen);
        
    }

    testcaseFile.close();

    ifstream testcaseInput("testcases.txt");

    testcaseInput >> t;
    while (t--) {
        string S, T;
        testcaseInput >> S >> T;
        string result = solve(S, T);
        outputfile << result << endl;
    }

    testcaseInput.close();
    outputfile.close();

    cout << "Test cases generated in testcases.txt and expected outputs saved in expected_output.txt" << endl;

    return 0;
}
