//Kodowanie tekstu metodą Huffmana
//Tekst na wejsciu musi posiadać conajmniej dwa różne znaki
//Adam Zabrocki

#include <iostream>
#include <string>

using namespace std;

struct Node // Tworzenie węzła
{
    Node *next;
    Node *right;
    Node *left;
    char inputSign;
    int sameSignesNumber;
};

void CheckSignes(string input) // Sprawdzenie czy są różne znaki
{
    unsigned int i;
    string check = input.substr(0,1);
    for(i = 1; i < input.length(); ++i)
    {
        if (input.substr(i,1) != check)
            return;
    }
    cout << "Tekst na wejsciu musi posiadać conajmniej dwa różne znaki" << endl;
    exit (0);
}
        
       

void CreateList(Node *&root, string input)    // Tworzenie listy, sortowanie
{
    unsigned int i, count;
    char nextSign;
    Node *sign;
    bool sorted;
    root = NULL;
    for (i = 0; i < input.length(); i++)
    {
        sign = root;
        while (sign && (sign->inputSign != input[i])) sign = sign->next;
        if(!sign)
        {
            sign = new Node;
            sign->next = root;
            sign->left = NULL;
            sign->right = NULL;
            sign->inputSign = input[i];
            sign->sameSignesNumber = 0;
            root = sign;
        }
        sign->sameSignesNumber++;
    }
    while(!sorted)
    {
        sorted = true;
        sign = root;
        while(sign->next)
        {
            if(sign->sameSignesNumber > sign->next->sameSignesNumber)
            {
                nextSign = sign->inputSign;
                sign->inputSign = sign->next->inputSign;
                sign->next->inputSign = nextSign;
                count = sign->sameSignesNumber;
                sign->sameSignesNumber = sign->next->sameSignesNumber;
                sign->next->sameSignesNumber = count;
                sorted = false;
            }
            sign = sign->next;
        }
    }
}

void CreateTree(Node *&root)  // Tworzenie drzewa
{
    Node *sign, *tempRoot, *firstRoot, *secondRoot;
    while(1)
    {
        firstRoot = root;
        secondRoot = firstRoot->next;
        if(!secondRoot)
            break;
        root = secondRoot->next;
        sign = new Node;
        sign->left = firstRoot;
        sign->right = secondRoot;
        sign->sameSignesNumber = firstRoot->sameSignesNumber + secondRoot->sameSignesNumber;
        if(!root || (sign->sameSignesNumber <= root->sameSignesNumber))
        {
            sign->next = root;
            root = sign;
            continue;
        }
        tempRoot = root;
        
        while (tempRoot->next && (sign->sameSignesNumber > tempRoot->next->sameSignesNumber))
            tempRoot = tempRoot->next;
        sign->next = tempRoot->next;
        tempRoot->next = sign;
    }
}
 
void Print(Node *sign, string code) // Drukowanie kodów znaków
{
    if(!sign->left && !sign->right)
    {
        if(sign->inputSign == ' ')
            cout << "(space): " << code << endl;
        else
            cout << sign->inputSign << ": " << code << endl;
    }
    else
    {
        Print(sign->left, code + "0");
        Print(sign->right, code + "1");
    }
}

bool CodeSign(char tempInputSign, Node *sign, string code) // Kodowanie znaku
{
  if(!sign->left && !sign->right)
  {
    if(tempInputSign != sign->inputSign) 
        return false;
    else
    {
        cout << code;
        return true;
    }
  }
  else return CodeSign(tempInputSign, sign->left, code + "0") || CodeSign(tempInputSign, sign->right, code + "1");
}

void CodeInput(Node *root, string input) // Przesylanie kolejnych znakow do kodowania
{
  unsigned int i;

  for(i = 0; i < input.length(); i++)
    CodeSign(input[i],root,"");
}

void RemoveTree(Node *branch)   //Usuwanie drzewa
{
  if(branch)
  {
    RemoveTree(branch->left);
    RemoveTree(branch->right);
    delete branch;
  }
}

int main()
{
  Node *root;
  string input;
  cout << "Wpisz tekst"<< endl;
  getline(cin, input);
  CheckSignes(input);
  CreateList(root,input);
  CreateTree(root);
  cout << "Kody poszczególnych znaków:"<< endl;
  Print(root,"");
  cout << "Kod całego tekstu: ";
  CodeInput(root,input);
  cout << endl;
  RemoveTree(root);
  exit (0);
} 
                
