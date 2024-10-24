#include "Array.h"
#include <iostream>
#include <algorithm>

using namespace std;

struct Block {
    int width;
    int height;
};

bool compareBlocks(const Block& a, const Block& b) {
    if (a.width == b.width) {
        return a.height < b.height;
    }
    return a.width < b.width;
}

int main() {
    int N;
    cout << "Enter the number of blocks: ";
    cin >> N;

    Array blocks(N);
    for (int i = 0; i < N; ++i) {
        int width, height;
        cout << "Enter width and height of block " << i + 1 << ": ";
        cin >> width >> height;
        blocks.add(i, to_string(width) + "," + to_string(height));
    }

    Block* blockVector = new Block[N];
    for (int i = 0; i < N; ++i) {
        string blockStr = blocks.get(i);
        size_t pos = blockStr.find(",");
        int width = stoi(blockStr.substr(0, pos));
        int height = stoi(blockStr.substr(pos + 1));
        blockVector[i] = { width, height };
    }

    sort(blockVector, blockVector + N, compareBlocks);

    int* dp = new int[N];
    for (int i = 0; i < N; ++i) {
        dp[i] = blockVector[i].height;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (blockVector[j].width < blockVector[i].width) {
                dp[i] = max(dp[i], dp[j] + blockVector[i].height);
            }
        }
    }

    int maxHeight = 0;
    for (int i = 0; i < N; ++i) {
        maxHeight = max(maxHeight, dp[i]);
    }

    cout << "Maximum height of the pyramid: " << maxHeight << endl;

    delete[] blockVector;
    delete[] dp;

    return 0;
}