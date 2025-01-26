/**
* @file List.cpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/


#include "../include/List.hpp"
#include "../include/Helper.hpp"
#include "../include/Tree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

NodeList::NodeList(Node* tree) : tree(tree), next(nullptr) {}

void ListeyeEkle(NodeList*& head, Node* tree) {
    NodeList* newNode = new NodeList(tree);
    if (head == nullptr) {
        head = newNode;
    } else {
        NodeList* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

NodeList* dosyaAc(const string& filename) {
    ifstream file(filename.c_str());
    if (!file) {
        cerr << "Dosya acilamadi: " << filename << endl;
        return nullptr;
    }

    NodeList* head = nullptr;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string tokn;
        string fullLine;

        while (iss >> tokn) {
            fullLine += tokn;
        }

        Node* root = nullptr;
        if (!fullLine.empty()) {
            root = new Node(string(1, fullLine[0]));
            for (int i = 1; i < (int)fullLine.size(); i++) {
                root = BSTekle(root, fullLine[i]);
            }
        }

        ListeyeEkle(head, root);
    }

    return head;
}

static int agacDegerHesaplaWrapper(Node* root);

void listeSayfaYazdir(NodeList* head, NodeList* aktif, int baslangicIndex, int maxSayfaS) {
    NodeList* current = head;
    int suankiIndex = 0;

    while (current != nullptr && suankiIndex < baslangicIndex) {
        current = current->next;
        suankiIndex++;
    }

    {
        NodeList* temp = current;
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            cout << "-------" << "   ";
            temp = temp->next;
        }
        cout << "\n";
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            string nodeAddr = sonUcDigit(temp);
            sabitAlanYazdir(nodeAddr);
            temp = temp->next;
        }
        cout << endl;
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            cout << "-------" << "   ";
            temp = temp->next;
        }
        cout << "\n";
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            int treeValue = agacDegerHesapla(temp->tree);
            string treeValueStr = to_string(treeValue);

            int len = (int)treeValueStr.size();
            int width = 5;

            cout << "-";
            cout << treeValueStr;
            if (len < width) {
                for (int s = 0; s < width - len; s++) {
                    cout << " ";
                }
            }
            cout << "-" << "   ";
            temp = temp->next;
        }
        cout << endl;
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            cout << "-------" << "   ";
            temp = temp->next;
        }
        cout << "\n";
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            string nextAddr = sonUcDigit(temp->next);
            sabitAlanYazdir(nextAddr);
            temp = temp->next;
        }
        cout << "\n";
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            cout << "-------" << "   ";
            temp = temp->next;
        }
        cout << "\n";
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            if (temp == aktif) {
                cout << "^^^^^^^" << "   ";
            } else {
                cout << "       " << "   ";
            }
            temp = temp->next;
        }
        cout << "\n";
    }

    {
        NodeList* temp = head;
        int idx = 0;
        while (temp != nullptr && idx < baslangicIndex) {
            temp = temp->next;
            idx++;
        }
        for (int i = 0; i < maxSayfaS && temp != nullptr; i++) {
            if (temp == aktif) {
                cout << "\n\n";
                AsciiAgacYazdir(temp->tree);
            } else {
                cout << "     " << "   ";
            }
            temp = temp->next;
        }
        cout << "\n";
    }
}

void listedeGezin(NodeList*& head) {
    if (head == nullptr) {
        cout << "Liste bos!" << endl;
        return;
    }

    NodeList* current = head;
    int totalNodes = 0;
    int maxSayfaS = 10;

    {
        NodeList* temp = head;
        while (temp != nullptr) {
            totalNodes++;
            temp = temp->next;
        }
    }

    int totalPages = (totalNodes + maxSayfaS - 1) / maxSayfaS;
    int suankiSayfa = 1;
    int suankiIndex = 0;

    while (true) {
        int baslangicIndex = (suankiSayfa - 1) * maxSayfaS;
        ekraniTemizle();
        listeSayfaYazdir(head, current, baslangicIndex, maxSayfaS);
        cout << "\nSayfa " << suankiSayfa << " / " << totalPages << endl;
        cout << "\nSecenekler:\n";
        cout << "a: Onceki dugum\n";
        cout << "d: Sonraki dugum\n";
        cout << "w: Agaci aynala\n";
        cout << "s: Dugumu sil\n";
        cout << "x: Cikis\n";
        cout << "Secim: ";

        char secim;
        cin >> secim;

        if (secim == 'a') {
            if (suankiIndex > 0) {
                suankiIndex--;
                NodeList* temp = head;
                for (int i = 0; i < suankiIndex; i++) {
                    temp = temp->next;
                }
                current = temp;
                if (suankiIndex < baslangicIndex) suankiSayfa--;
            }
        } else if (secim == 'd') {
            if (suankiIndex < totalNodes - 1) {
                suankiIndex++;
                NodeList* temp = head;
                for (int i = 0; i < suankiIndex; i++) {
                    temp = temp->next;
                }
                current = temp;
                if (suankiIndex >= baslangicIndex + maxSayfaS) suankiSayfa++;
            }
        } else if (secim == 's') {
            if (current == head) {
                NodeList* toDelete = head;
                head = head->next;
                current = head;
                delete toDelete;
            } else {
                NodeList* temp = head;
                while (temp->next != current) {
                    temp = temp->next;
                }
                temp->next = current->next;
                NodeList* toDelete = current;
                current = temp->next ? temp->next : temp;
                delete toDelete;
            }
            totalNodes--;
            totalPages = (totalNodes + maxSayfaS - 1) / maxSayfaS;
            if (baslangicIndex >= totalNodes && totalNodes > 0) {
                suankiSayfa = (totalNodes + maxSayfaS - 1) / maxSayfaS;
                suankiIndex = totalNodes - 1;
                NodeList* temp = head;
                for (int i = 0; i < suankiIndex; i++) {
                    temp = temp->next;
                }
                current = temp;
            }
            if (head == nullptr) {
              	ekraniTemizle();
                cout << "Tum dugumler silindi, Liste bos!" << endl;
                return;
            }
        } else if (secim == 'w') {
            if (current->tree != nullptr) {
                AgacAynala(current->tree);
                cout << "Agac aynalandi!" << endl;
            } else {
                cout << "Aynalanacak agac yok!" << endl;
            }
        } else if (secim == 'x') {
            return;
        } else {
            cout << "Gecersiz secim!" << endl;
        }
    }
}
