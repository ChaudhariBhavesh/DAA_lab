
#include <bits/stdc++.h>
#include <fstream>
#include <unordered_map>
using namespace std;

struct MinHeapNode
{

    char data;

    unsigned freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)

    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{

    bool operator()(MinHeapNode *l, MinHeapNode *r)

    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << endl
             << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
    ofstream ofs("My.txt");
    string st;
    cout << "Enter the data to put on the  file" << endl;
    getline(cin, st);
    ofs << st;
    ofs.close();
    ifstream ifs("My.txt");
    getline(ifs, st);

    unordered_map<char, int> m;

    for (long i = 0; i < st.length(); i++)
    {
        m[st[i]]++;
    }
    int size = m.size();
    char arr[size];
    int freq[size];
    int i = 0;

    unordered_map<char, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        arr[i] = itr->first;
        freq[i] = itr->second;
        i++;
    }

    int len = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, len);

    return 0;
}
