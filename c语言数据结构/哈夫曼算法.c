#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

// 定义哈夫曼树节点结构
typedef struct {
    unsigned int weight; // 权重
    int parent, lchild, rchild; // 父节点、左子节点、右子节点
    unsigned char value; // 节点对应的字符
} HTNode, *HuffmanTree;

typedef char **HuffmanCode; // 定义哈夫曼编码表类型

// 比较两个文件内容是否相同
int compareFiles(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    if (!f1) {
        fprintf(stderr, "Error opening file: %s\n", file1);
        exit(EXIT_FAILURE);
    }
    FILE *f2 = fopen(file2, "rb");
    if (!f2) {
        fprintf(stderr, "Error opening file: %s\n", file2);
        fclose(f1);
        exit(EXIT_FAILURE);
    }
    int c1, c2;
    do {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 != c2) {
            fclose(f1);
            fclose(f2);
            return 0; // 文件内容不同
        }
    } while (c1 != EOF && c2 != EOF);
    fclose(f1);
    fclose(f2);
    return 1; // 文件内容相同
}

// 统计文件中每个字符的频率
void countFrequency(const char *filename, unsigned int *freq) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    int c;
    while ((c = fgetc(file)) != EOF) {
        freq[c]++; // 增加字符的频率计数
    }
    fclose(file);
}

// 在哈夫曼树中选择权重最小的两个节点
void selectMin(HuffmanTree HT, int n, int *s1, int *s2) {
    unsigned int min1 = UINT_MAX, min2 = UINT_MAX;
    *s1 = *s2 = -1;
    for (int i = 0; i < n; i++) {
        if (HT[i].parent == -1 && HT[i].weight < min1) {
            min2 = min1;
            *s2 = *s1;
            min1 = HT[i].weight;
            *s1 = i;
        } else if (HT[i].parent == -1 && HT[i].weight < min2) {
            min2 = HT[i].weight;
            *s2 = i;
        }
    }
}

// 构建哈夫曼树
HuffmanTree buildHuffmanTree(unsigned int *freq, int *n) {
    *n = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) (*n)++; // 统计非零频率的字符数
    }
    int m = 2 * (*n) - 1; // 哈夫曼树的总节点数
    HuffmanTree HT = (HuffmanTree)malloc(m * sizeof(HTNode));
    for (int i = 0, j = 0; i < 256; i++) {
        if (freq[i] > 0) {
            HT[j].weight = freq[i];
            HT[j].parent = HT[j].lchild = HT[j].rchild = -1;
            HT[j].value = (unsigned char)i;
            j++;
        }
    }
    for (int i = *n; i < m; i++) {
        int s1, s2;
        selectMin(HT, i, &s1, &s2); // 选择权重最小的两个节点
        HT[s1].parent = HT[s2].parent = i;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].parent = -1;
    }
    return HT;
}

// 生成哈夫曼编码表
void generateHuffmanCodes(HuffmanTree HT, int n, HuffmanCode *HC) {
    *HC = (HuffmanCode)malloc(256 * sizeof(char *));
    for (int i = 0; i < 256; i++) {
        (*HC)[i] = NULL; // 初始化编码表
    }

    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';

    for (int i = 0; i < n; i++) {
        if (HT[i].lchild == -1 && HT[i].rchild == -1) { // 仅对叶子节点生成编码
            int start = n - 1;
            int c = i, f = HT[i].parent;
            while (f != -1) {
                start--;
                if (HT[f].lchild == c)
                    cd[start] = '0';
                else
                    cd[start] = '1';
                c = f;
                f = HT[f].parent;
            }
            (*HC)[HT[i].value] = (char *)malloc((n - start + 1) * sizeof(char));
            strcpy((*HC)[HT[i].value], &cd[start]);
            printf("Character '%c' -> Huffman Code: %s\n", HT[i].value, (*HC)[HT[i].value]);
        }
    }
    free(cd);
}

// 编码文件
void encodeFile(const char *inputFile, const char *outputFile, HuffmanCode HC, unsigned int *freq, unsigned long long totalBits) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        fprintf(stderr, "Error opening input file: %s\n", inputFile);
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        fprintf(stderr, "Error opening output file: %s\n", outputFile);
        fclose(in);
        exit(EXIT_FAILURE);
    }
    int n = 0;
    for (int i = 0; i < 256; i++) if (freq[i]) n++;
    fwrite(&n, sizeof(int), 1, out); // 写入字符种类数
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            unsigned char c = i;
            fwrite(&c, 1, 1, out); // 写入字符
            fwrite(&freq[i], sizeof(unsigned int), 1, out); // 写入频率
        }
    }
    fwrite(&totalBits, sizeof(unsigned long long), 1, out); // 写入总位数
    unsigned char buffer = 0;
    int count = 0;
    int c;
    printf("Encoding file '%s'...\n", inputFile);
    while ((c = fgetc(in)) != EOF) {
        char *code = HC[c];
        printf("Character '%c' -> Code: %s\n", c, code);
        for (int i = 0; code[i]; i++) {
            buffer <<= 1;
            if (code[i] == '1') buffer |= 1;
            count++;
            if (count == 8) {
                fwrite(&buffer, 1, 1, out);
                buffer = 0;
                count = 0;
            }
        }
    }
    if (count > 0) {
        buffer <<= (8 - count);
        fwrite(&buffer, 1, 1, out);
    }
    fclose(in);
    fclose(out);
    printf("Encoding completed. Encoded file saved to '%s'.\n", outputFile);
}

// 解码文件
void decodeFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        fprintf(stderr, "Error opening input file: %s\n", inputFile);
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        fprintf(stderr, "Error opening output file: %s\n", outputFile);
        fclose(in);
        exit(EXIT_FAILURE);
    }
    int n;
    fread(&n, sizeof(int), 1, in); // 读取字符种类数
    unsigned int freq[256] = {0};
    printf("\nReading frequency table from encoded file...\n");
    printf("Number of unique characters: %d\n", n);
    for (int i = 0; i < n; i++) {
        unsigned char c;
        unsigned int f;
        fread(&c, 1, 1, in);
        fread(&f, sizeof(unsigned int), 1, in);
        freq[c] = f;
        printf("Character '%c' -> Frequency: %u\n", c, f);
    }
    unsigned long long totalBits;
    fread(&totalBits, sizeof(unsigned long long), 1, in); // 读取总位数
    printf("Total bits to read: %llu\n", totalBits);
    HuffmanTree HT = buildHuffmanTree(freq, &n);
    int m = 2 * n - 1;
    int root = m - 1;
    int current = root;
    unsigned char byte;
    int bitPos = 0;
    unsigned long long bitsProcessed = 0;
    printf("Decoding file '%s'...\n", inputFile);
    while (bitsProcessed < totalBits && fread(&byte, 1, 1, in)) {
        bitPos = 8;
        while (bitPos-- && bitsProcessed < totalBits) {
            int bit = (byte >> bitPos) & 1;
            current = bit ? HT[current].rchild : HT[current].lchild;
            if (HT[current].lchild == -1 && HT[current].rchild == -1) {
                fputc(HT[current].value, out);
                printf("Decoded character: '%c'\n", HT[current].value);
                current = root;
            }
            bitsProcessed++;
        }
    }
    fclose(in);
    fclose(out);
    free(HT);
    printf("Decoding completed. Decoded file saved to '%s'.\n", outputFile);
}

// 显示文件内容
void displayFileContent(const char *path, const char *description, int isBinary) {
    FILE *file = fopen(path, isBinary ? "rb" : "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file '%s' for reading.\n", path);
        return;
    }
    printf("%s ('%s'):\n", description, path);
    int isEmpty = 1;
    if (isBinary) {
        unsigned char buffer[16];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            isEmpty = 0;
            for (size_t i = 0; i < bytesRead; i++) {
                printf("%02X ", buffer[i]);
            }
            printf("\n");
        }
    } else {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            isEmpty = 0;
            putchar(ch);
        }
    }
    fclose(file);
    if (isEmpty) {
        printf("The file is empty.\n");
    }
    printf("\n");
}

// 打印哈夫曼树结构
void printHuffmanTree(HuffmanTree HT, int n) {
    printf("\nHuffman Tree Structure:\n");
    printf("Index\tWeight\tParent\tLChild\tRChild\tValue\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d\t%-6d\t%-6d\t%-6s\t%-6s\t%-6c\n", 
            i, HT[i].weight, HT[i].parent, 
            HT[i].lchild == -1 ? "-" : (char[10]){0}, // 如果没有左子节点，显示 "-"
            HT[i].rchild == -1 ? "-" : (char[10]){0}, // 如果没有右子节点，显示 "-"
            (HT[i].lchild == -1 && HT[i].rchild == -1) ? HT[i].value : ' ');
    }
    printf("\n");
}

int main() {
    char originalFile[256] = "/mnt/d/original.txt";
    char encodedFile[256] = "/mnt/d/encoded.bin";
    char decodedFile[256] = "/mnt/d/decoded.txt";

    unsigned int freq[256] = {0};
    countFrequency(originalFile, freq);

    int n;
    HuffmanTree HT = buildHuffmanTree(freq, &n);

    // 打印哈夫曼树结构
    printHuffmanTree(HT, 2 * n - 1);

    HuffmanCode HC;
    generateHuffmanCodes(HT, n, &HC);

    unsigned long long totalBits = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] && HC[i]) {
            totalBits += freq[i] * strlen(HC[i]);
        }
    }
    printf("\nTotal bits to write: %llu\n", totalBits);

    displayFileContent(originalFile, "Content of the original file", 0);

    encodeFile(originalFile, encodedFile, HC, freq, totalBits);
    decodeFile(encodedFile, decodedFile);

    printf("Files comparison result: %s\n", compareFiles(originalFile, decodedFile) ? "Identical" : "Different");

    printf("Checking encoded file content:\n");
    displayFileContent(encodedFile, "Content of the encoded file (binary data in hex)", 1);

    printf("Checking decoded file content:\n");
    displayFileContent(decodedFile, "Content of the decoded file", 0);

    FILE *decoded = fopen(decodedFile, "r");
    if (decoded) {
        fseek(decoded, 0, SEEK_END);
        if (ftell(decoded) == 0) {
            printf("Warning: The decoded file is empty. Please verify the encoding and decoding process.\n");
        }
        fclose(decoded);
    } else {
        printf("Error: Unable to open the decoded file for verification.\n");
    }

    for (int i = 0; i < 256; i++) {
        if (HC[i]) free(HC[i]);
    }
    free(HC);
    free(HT);

    return 0;
}