// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned int len = s.length();
    for (int i = 0; i < len/2; i++) {
        if (s[i] == s[len-i-1]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    string carbon = s;
    string revolver;
    unsigned int len = carbon.length()-1;
    for (int i = 0; i <= len; i++) {
        if (carbon[i] > 64 && carbon[i] < 91) {
            revolver.push_back(tolower(carbon[i]));
        }
        else if (carbon[i] > 96 && carbon[i] < 123) {
            revolver.push_back(carbon[i]);
        }
        else {
            continue;
        }
    }

    return palindrome(revolver);
}

// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    int nextnum = n + 1;
    while (digitSum(nextnum) != sum) {
        nextnum ++;
    }
    return nextnum;
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        int num = n % 10;
        sum += num;
        n /= 10;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    unsigned int len = v.size();
    unsigned int seq = 0;
    unsigned int max_seq = 0;
    for (unsigned int i = 1; i < len; i++) {
        if (v[i] < v[i-1]) {
            seq++;
        }
        else if (v[i] >= v[i-1]) {
            if (max_seq < seq) {
                max_seq = seq;
            }
            seq = 0;
        }
    }
    if (seq > max_seq) {
        max_seq = seq;
    }
    return max_seq;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    unsigned int len = v.size();
    int counter = 0;
    for (unsigned int i = 0; i < len; i++) {
        if (v[i] == n) {
            counter++;
        }
    }
    return counter;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    unsigned int len = v.size();
    for (unsigned int i = 0; i < len; i++) {
        for (unsigned int j = i + 1; j < len; j++) {
            if (v[i] == v[j]) {
                return true;
            }
        }
    }
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        for (auto s_itr = itr + 1; s_itr != v.end(); s_itr++) {
            if (*itr == *s_itr) {
                v.erase(s_itr);
                s_itr--;
            }
        }
    }
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans(v1);
    ans.insert(ans.end(), v2.begin(), v2.end());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = i+1; j < ans.size(); j++) {
            if (ans[i] > ans[j]) {
                swap(ans[i], ans[j]);
        }
    }
}
    return ans;
}


// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    int cont = 0;
    for (int x = 1; x <= n; x++) {
        if (n % x == 0) {
            cont += 1;
        }
    }
    if (cont == 2) {
        return true;
    }
    else {
        return false;
    }
}


// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            while (n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }
        else {
            continue;
        }
    }
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    vector<bool> prime_check(n+1, 1);
    for (int i = 2; i * i < n; i++) {
        if (prime_check[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                prime_check[j] = 0;
            }
        }
    }
    for (int x = 2; x <= n; x++) {
        if (prime_check[x] == 1) {
            ans.push_back(x);
        }
    }
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
int CAssist(long long n) {
    int sum = 0;
    while (n != 0) {
        int num = n % 10;
        sum += num;
        n /= 10;
    }
    return sum;
}



long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    n += 1;

    long long n_pow = 1;

    while (CAssist(n) > sum) {
        if ((n / n_pow) % 10 == 0) {
            n_pow *= 10;
        }
        else {
            n += n_pow;
        }
    }

    n_pow = 1;
    while (CAssist(n) < sum) {
        if ((n / n_pow) % 10 == 9) {
            n_pow *= 10;
        }
        else {
            n += n_pow;
        }
    }
    return n;
}