#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    string filePath = "testcase.txt";
    ofstream writeFile(filePath.data());
    if(writeFile.is_open()){
        writeFile << "1000 1000\n";
        for(int i=0;i<999;i++)
        {
            for(int j=0;j<1000;j++)
            {
                writeFile << 0;
            }writeFile << "\n";
        }
        for(int i=0;i<1;i++)
        {
            for(int j=0;j<1000;j++)
            {
                writeFile << 1;
            }writeFile << "\n";
        }
        writeFile.close();
    }
    
    return 0;
}