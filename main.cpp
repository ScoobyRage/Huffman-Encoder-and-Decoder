#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Node
{
    char character;
    int frequency;
    Node *left, *right;

    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

Node* createNode(char ch, int freq)
{
    return new Node(ch, freq);
}
void sortNodes(Node* nodes[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (nodes[j]->frequency > nodes[j + 1]->frequency)
            {
                Node* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}
void huffmancode(Node* root, string code, string codes[100])
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        codes[(unsigned char)root->character] = code;
        return;
    }
    huffmancode(root->left, code + "0", codes);
    huffmancode(root->right, code + "1", codes);
}

Node* buildHuffmanTree(int frequency[100])
{
    Node* nodes[100];
    int size = 0;

    for (int i = 0; i < 100; ++i)
    {
        if (frequency[i] > 0)
        {
            nodes[size++] = createNode(i, frequency[i]);
        }
    }

    while (size > 1)
    {
        sortNodes(nodes, size);

        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* merged = createNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        for (int i = 2; i < size; ++i)
        {
            nodes[i - 2] = nodes[i];
        }
        nodes[size - 2] = merged;
        size--;
    }

    return nodes[0];
}

void freeTree(Node* root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}
string compressString(const string& input, string codes[100])
{
    string output;
    for (char ch : input)
    {
        output += codes[(unsigned char)ch];
    }
    return output;
}
string decodeString(Node* root, const string& compressed)
{
    string decoded = "";
    Node* current = root;

    for (char bit : compressed)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (!current->left && !current->right)
        {
            decoded += current->character;
            current = root;
        }
    }

    return decoded;
}
void encoding()//-----------------------------------------------------------------------------------------------------------------------------------------------------For Encoding--------------------------------------
{
    string input;
    ifstream inputFile("input.txt");

    getline(inputFile, input);

    int frequency[100] = {0};
    for (char ch : input)
    {
        frequency[(unsigned char)ch]++;
    }

    ofstream frequencyFile("frequency.txt");

    for (int i = 0; i < 100; ++i)
    {
        if (frequency[i] > 0)
        {
            frequencyFile << (char)i << " " << frequency[i] << "\n";
        }
    }

    Node* nodes[100];
    int size = 0;
    for (int i = 0; i < 100; ++i)
    {
        if (frequency[i] > 0)
        {
            nodes[size++] = createNode(i, frequency[i]);
        }
    }

    while (size > 1)
    {
        sortNodes(nodes, size);

        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* merged = createNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        for (int i = 2; i < size; ++i)
        {
            nodes[i - 2] = nodes[i];
        }
        nodes[size - 2] = merged;
        size--;
    }

    string codes[100];
    huffmancode(nodes[0],"", codes);

    string compressed = compressString(input, codes);

    ofstream outputFile("output.txt");

    outputFile << compressed;

    inputFile.close();
    outputFile.close();
    frequencyFile.close();
    cout << "\n\nEncoded string saved in output.txt . Check the text file for compressed string\n\n";

}
void decoding()//-------------------------------------------------------------------------------------------------------------For Decoding-------------------------------------------------------------------------------------
{
    string compressed;
    ifstream compressedFile("output.txt");

    getline(compressedFile, compressed);
    compressedFile.close();

    ifstream frequencyFile("frequency.txt");

    char ch;
    int freq;
    int frequency[100] = {0};
    while (frequencyFile >> ch >> freq)
    {
        frequency[(unsigned char)ch] = freq;
    }
    frequencyFile.close();

    Node* root = buildHuffmanTree(frequency);

    string decoded = decodeString(root, compressed);

    ofstream decodedFile("decoded.txt");
    decodedFile << decoded;
    decodedFile.close();

    cout << "\n\nDecoded string saved in decoded.txt . Check the text file for decoded string\n\n";
}
void file()
{
            ofstream input("input.txt");
            input.close();
            cout<<"\ninput.txt file created please go to the directory and write a string that you want to encode\n\n";
        }
int option()
{
        cout<<"Press 1 creating input.txt\n"<<"Press 2 for Encoding\n"<<"Press 3 for Decoding\n";
        while(1)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            file();
            option();
        }
        else if(a==2)
        {
            encoding();
            option();
        }
        else if(a==3)
        {
            decoding();
            option();
        }
        else if(a!=1 || a!=2 ||a!=3)
        {
            cout<<"Only the given value\n";
        }
    }
}
int main()
{
    cout<<"If this program is running for first time after build \nPlease press 1 that will create a text file name input.txt \nwhich is located in the same directory where this program file is saved.\n\n\n";
    option();
}

