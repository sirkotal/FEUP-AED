// AED 2022/2023 - Aula Pratica 03
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 02/10/2022]

#include "funWithSearch.h"
#include <climits>
#include <algorithm>

// ----------------------------------------------------------
// Exercicio 1: Pesquisa Elementar
// ----------------------------------------------------------
// TODO
int FunWithSearch::search(const vector<int> & v, int key) {
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) {
            high = middle - 1;
        }
        else if (key > v[middle]) {
            low = middle + 1;
        }
        else return middle;
    }
    return -1;
}

// ----------------------------------------------------------
// Exercicio 2: Limite Inferior
// ----------------------------------------------------------
// TODO
int FunWithSearch::lowerBound(const vector<int> &v, int key) {
    int low = 0;
    int high = (int)v.size() - 1;
    int sz = (int)v.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (key <= v[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    if (low < sz && v[low] < key) {
        low++;
    }
    if (v[low] < key) {
        return -1;
    }
    return low;
}
// ----------------------------------------------------------
// Exercicio 3: Intervalos
// ----------------------------------------------------------
// TODO
int FunWithSearch::countRange(const vector<int> & v, int a, int b) {
    int sz = (int)v.size();
    int low = lowerBound(v,a);
    int high = lowerBound(v,b);
    int count = 0;
    int carbon = b;

    if (low == -1) {
        return 0;
    }

    if (high == -1) {
        return (sz - low);
    }

    count += high - low;

    while (v[high] == carbon && high != sz) {
        count++;
        high++;
    }
    return count;
}

// ----------------------------------------------------------
// Exercicio 4a: Viagem de mochila às costas (isPossible)
// ----------------------------------------------------------
// TODO
bool FunWithSearch::isPossible(const vector<int> & v, int x, int k) {
    int parts = 0;
    int sum = 0;

    for (unsigned int i = 0; i < v.size(); i++) {
        sum += v.at(i);
        if (v.at(i) > x) {
            return false;
        }
        else if (sum > x) {
            parts += 1;
            sum = v.at(i);
        }
    }

    if (k > parts && sum <= x) {
        return true;
    }
    return false;
}

// ----------------------------------------------------------
// Exercicio 4b: Viagem de mochila às costas (partitions)
// ----------------------------------------------------------
// TODO
int FunWithSearch::partitions(const vector<int> & v, int k) {
    vector<int> days = {};
    int max = 0;
    int sum = 0;

    for (unsigned int i = 0; i < v.size(); i++) {
        days.push_back(v.at(i));
        sum += v.at(i);
        if (v.at(i) > max) {
            max = v.at(i);
        }
    }


    int under = max; // low int
    int hangem = sum; // high int

    while (under < hangem) {
        int spear = (under + hangem) / 2;  // midway int
        int x = 1;  // use my ints Anakin
        int y = 0;  // I beg you


        for (int day : days) {
            y += day;
            if (y > spear) {
                y = day;
                x++;
            }
        }

        if (x <= k) {
            hangem = spear;
        }
        else {
            under = spear + 1;
        }
    }
    return under;
}

// ----------------------------------------------------------
// Exercicio 5: Somas mais próximas
// ----------------------------------------------------------
// TODO
vector<int> FunWithSearch::closestSums(const vector<int> & v, const vector<int> & p) {
    vector<int> ans;
    vector<int> final;
    int v_len = (int)v.size();
    int p_len = (int)p.size();

    for (auto i = v.begin(); i < v.end(); i++) {
        for (auto j = i + 1; j < v.end(); j++) {
            ans.push_back(*i + *j);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (unsigned int k = 0; k < p_len; k++) {
        unsigned int point = 0;
        unsigned int finish = ans.size() - 1;
        unsigned int midway;
        while (point + 1 < finish) {
            midway = (point + finish) / 2;

            if (ans.at(midway) > p.at(k))
                finish = midway;
            else
                point = midway;
        }

        unsigned int solid = abs(p.at(k) - ans.at(point));
        unsigned int revolver = abs(ans.at(finish) - p.at(k));

        if (solid < revolver)
            final.push_back(ans.at(point));
        else if (revolver < solid)
            final.push_back(ans.at(finish));
        else {
            if (ans.at(point) < ans.at(finish)) {
                final.push_back(ans.at(point));
            }
            else {
                final.push_back(ans.at(finish));
            }
        }
    }
    return final;
}

// ----------------------------------------------------------
// Exercicio 6: Jogo de strings
// ----------------------------------------------------------
// TODO
int FunWithSearch::stringGame(const string & a, const string & b, const vector<int> & p) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 7: Regras Quadriculadas
// ----------------------------------------------------------
// TODO
long long FunWithSearch::rules(int k, long long a, long long b) {
    return 0;
}