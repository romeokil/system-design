#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


class documentEditor{
    private:
        vector<string> documentElements;
        string renderedDocuments;
    public:
        void addText(string word){
            documentElements.push_back(word);
        }
        void addImage(string filePath){
            documentElements.push_back(filePath);
        }
        string renderDocument(){
            if(renderedDocuments.empty()){
                string result;
                for(auto element:documentElements){
                    if(element.size() > 4 && (element.substr(element.size()-4) ==".jpg" || element.substr(element.size()-4) ==".png"))
                    result+="[Image:" + element + "]" + "\n";
                    else result+=element+"\n";
                }
                renderedDocuments=result;
            }
            return renderedDocuments;
        }
        void savetoFile(){
            ofstream file("document.txt");
            if(file.is_open()){
                file << renderDocument();
                file.close();
                cout<<"Document saved to document.txt"<<endl;
            }
            else{
                cout<<"Error: Unable to open the file"<<endl;
            }
        }
};
int main(){
    documentEditor de;
    de.addText("hi beta kaise ho");
    de.addImage("picture.jpg");
    de.renderDocument();
    de.savetoFile();
}