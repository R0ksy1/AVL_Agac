/**
* @file Tree.cpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author
*/

#include "../include/Tree.hpp"
#include "../include/Helper.hpp"
#include <iostream>
#include <climits>   // <-- min_col ararken INT_MAX kullanmak için
using namespace std;

struct PosNode {
    Node* node;
    int row;
    int col;
};

static const int DikeyBosluk = 5;
static const int YatayBosluk = 3;
static const char BasChar = '.';

static int genislikHesapla(Node* root) {
    if (!root) return 0;
    int lw = genislikHesapla(root->left);
    int rw = genislikHesapla(root->right);
    return lw + YatayBosluk + rw;
}

static void pozisyonAta(Node* root, int row, int left_pad, PosNode*& dizi_pos, int &index) {
    if (!root) return;

    int lw = genislikHesapla(root->left);
    int col = left_pad + lw;

    dizi_pos[index].node = root;
    dizi_pos[index].row = row;
    dizi_pos[index].col = col;
    index++;

    pozisyonAta(root->left,  row + DikeyBosluk, left_pad,         dizi_pos, index);
    pozisyonAta(root->right, row + DikeyBosluk, col + YatayBosluk, dizi_pos, index);
}

static void agacYazdir(PosNode* dizi_pos, int node_count) {
    int root_col = dizi_pos[0].col;
    for (int i = 0; i < node_count; i++) {
        dizi_pos[i].col -= root_col;
    }

    int min_col = INT_MAX;
    for (int i = 0; i < node_count; i++) {
        if (dizi_pos[i].col < min_col) {
            min_col = dizi_pos[i].col;
        }
    }

    if (min_col < 0) {
        for (int i = 0; i < node_count; i++) {
            dizi_pos[i].col -= min_col;
        }
    }

    int margin = 2;
    for (int i = 0; i < node_count; i++) {
        dizi_pos[i].col += margin;
    }

    int max_row = 0;
    int max_column = 0;
    int maxDataLength = 0;
    for (int i = 0; i < node_count; i++) {
        if (dizi_pos[i].row > max_row)    max_row = dizi_pos[i].row;
        if (dizi_pos[i].col > max_column) max_column = dizi_pos[i].col;

        int dataLength = (int)dizi_pos[i].node->data.size();
        if (dataLength > maxDataLength) maxDataLength = dataLength;
    }

    max_column += maxDataLength + 2;
    max_row    += 2;
    max_column += 2;

    char** Tuval = new char*[max_row + 1];
    for (int r = 0; r <= max_row; r++) {
        Tuval[r] = new char[max_column + 1];
        for (int c = 0; c <= max_column; c++) {
            Tuval[r][c] = ' ';
        }
        Tuval[r][max_column] = '\0';
    }

    for (int i = 0; i < node_count; i++) {
        Node* n = dizi_pos[i].node;
        int r = dizi_pos[i].row;
        int c = dizi_pos[i].col;
        const string& dataStr = n->data;
        int len = (int)dataStr.size();

        for (int k = 0; k < len && (c + k) <= max_column; k++) {
            if (r <= max_row && (c + k) <= max_column && r >= 0 && (c + k) >= 0) {
                Tuval[r][c + k] = dataStr[k];
            }
        }
    }

    for (int i = 0; i < node_count; i++) {
        Node* n = dizi_pos[i].node;
        int r = dizi_pos[i].row;
        int c = dizi_pos[i].col;

        auto cizBaglanti = [&](Node* child) {
            for (int j = 0; j < node_count; j++) {
                if (dizi_pos[j].node == child) {
                    int vt = dizi_pos[j].row;
                    int vv = dizi_pos[j].col;

                    int baslaC = myMinimum(c, vv);
                    int bitisC = myMaximum(c, vv);
                    int satirSira = r + 1;

                    for (int x = baslaC; x <= bitisC && x <= max_column && satirSira <= max_row; x++) {
                        if (x >= 0 && satirSira >= 0) {
                            Tuval[satirSira][x] = BasChar;
                        }
                    }

                    for (int rr = satirSira + 1; rr < vt && rr <= max_row && vv <= max_column; rr++) {
                        if (rr >= 0 && vv >= 0) {
                            Tuval[rr][vv] = BasChar;
                        }
                    }
                    break;
                }
            }
        };

        if (n->left)  cizBaglanti(n->left);
        if (n->right) cizBaglanti(n->right);
    }

    for (int rr = 0; rr <= max_row; rr++) {
        int end = max_column;
        while (end > 0 && Tuval[rr][end - 1] == ' ') end--;
        if (end > 0) {
            for (int vv = 0; vv < end; vv++) {
                cout << Tuval[rr][vv];
            }
            cout << "\n";
        }
    }

    for (int r = 0; r <= max_row; r++) {
        delete[] Tuval[r];
    }
    delete[] Tuval;
}

void AsciiAgacYazdir(Node* root) {
    if (!root) {
        cout << "(Bos agac)\n";
        return;
    }

    struct Counter {
        static int sayNode(Node* r) {
            if (!r) return 0;
            return 1 + sayNode(r->left) + sayNode(r->right);
        }
    };

    int node_count = Counter::sayNode(root);
    PosNode* dizi_pos = new PosNode[node_count];

    int index = 0;
    int total_width = genislikHesapla(root);

    pozisyonAta(root, 0, 0, dizi_pos, index);

    agacYazdir(dizi_pos, node_count);

    delete[] dizi_pos;
}
