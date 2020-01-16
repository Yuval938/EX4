//
// Created by yuval on 16/01/2020.
//

#ifndef EX4_NODE_H
#define EX4_NODE_H

#include <string>
#include <vector>
using namespace std;
class Node {
    double value;
    int numOfNeighbors = 0;
    char color = 'w';
    double pathValue = -1;
    Node* father = NULL;
    vector<Node*> Neighbors;
public:
    Node(double num) {
        this->value = num;
    }
    double getValue(){
        return this->value;
    }
    void addNeighbor(Node* Neighbor){
        this->Neighbors.push_back(Neighbor);
        this->numOfNeighbors+=1;
    }
    void setPathValue(double val){
        this->pathValue = val;
    }
    void setColor(char c){
        this->color = c;
    }
    void setFather(Node* father1){
        this->father = father1;
    }
    vector<Node*>::iterator getNeighbors(){
        this->Neighbors.begin();
    }
    int GetNumOfNeighbors(){
        return this->numOfNeighbors;
    }
    char getColor(){
        return this->color;
    }
    double getPathValue(){
        return this->pathValue;
    }

};


#endif //EX4_NODE_H



/*
void printMatrix(vector <vector<double>> matrixDouble) {

    int lines = matrixDouble.size();
    cout << "lines: " << lines << endl;
    int i, j;
    for (i = 0; i < lines; i++) {
void MyClientHandler::handleClient(int clientsocket) {

}
        int columns = matrixDouble[i].size();
        for (j = 0; j < columns; j++) {
            cout << matrixDouble[i][j] << " " << flush;
        }
        //   cout << "columns: " << columns << flush;
        cout << endl;
    }
}
 */





/*
int main() {

    string nameOfFile = "matrix_test.txt";
    ifstream infile(nameOfFile);

    vector <string> matrixString;
    vector <vector<Node*>> matrixDouble;

    string line;
    while (getline(infile, line)) {
        replaceAll(line, " ", "");
        matrixString.push_back(line);

    }

    int matrixSize = matrixString.size();
    int i;
    for (i = 0; i < matrixSize - 3; i++) {
        string numString = "";
        int j = 0, lineSize = matrixString[i].size();
        vector < Node * > lineVector;
        while (j < lineSize) {
            while (j < lineSize && matrixString[i].at(j) != ',') {
                numString += matrixString[i].at(j);
                j++;
            }
            if (numString.compare("end") != 0) {
                double num = atof(numString.c_str());
                lineVector.push_back(new Node(num);
            }
            j++;
            numString = "";
        }

        if (lineVector.size() > 0) {
            matrixDouble.push_back(lineVector);
        }
    }
    string numString = "";
    int count = 0;
    int j = 0, lineSize;
    int startX, startY, endX, endY;

    for (i; i < matrixSize - 1; i++) {
        lineSize = matrixString[i].size();
        j = 0;
        while (j < lineSize) {
            while (j < lineSize && matrixString[i].at(j) != ',') {
                numString += matrixString[i].at(j);
                j++;
            }
            if (count < 4) {
                double num = atof(numString.c_str());
                numString = "";
                j++;
                if (count == 0) {
                    startX = num;
                } else if (count == 1) {
                    startY = num;
                } else if (count == 2) {
                    endX = num;
                } else if (count == 3) {
                    endY = num;
                }
                count++;
            }
        }
    }

    // make and initialize wasHere matrix
    vector <vector<int>> wasHere;
    const int size = matrixDouble[0].size();
    for (i = 0; i < size; i++) {
        vector<int> boolLine;
        for (j = 0; j < size; j++) {
            boolLine.push_back(0);
        }
        wasHere.push_back(boolLine);
    }

    printMatrix(matrixDouble);
    cout << "start P: (" << startX << "," << startY << ")" << endl;
    cout << "end P: (" << endX << "," << endY << ")" << endl;

    // now we got the matrix in vectors and doubles

    return 0;
}

 */