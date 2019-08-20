#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    string filePath = "testcase.txt";
    ofstream writeFile(filePath.data());
    if(writeFile.is_open()){
        writeFile << "50 50 2500\n";
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<50;j++)
            {
                writeFile << 1;
            }writeFile << "\n";
        }
        writeFile.close();
    }
    
    return 0;
}