#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// document me kis kis type ka element ho skta hai 
// toh jaise textElement,imageElement,tabSpaceElement,
// newLineElement
class documentElement{
    public:
        virtual string render()=0;
};
class textElement:public documentElement{
    private:
        string text;
    public:
        textElement(string text){
            this->text=text;
        }
        string render() override{
            return text;
        }
};
class imageElement:public documentElement{
    private:
        string filePath;
    public:
        imageElement(string filePath){
            this->filePath=filePath;
        }
        string render() override{
            return "[Image" + filePath +"]";
        }
};

class tabSpaceElement:public documentElement{
    public:
        string render() override{
            return "\t";
        }
};

class newLineElement:public documentElement{
    public:
        string render() override{
            return "\n";
        }
};
// ye basically saara document element ko store krne ka kaam krega.
// or dusra us particular documentElement ka render function call krega.
class Document{
    private:
        vector<documentElement*> documentElements;
    public:
        void addElement(documentElement* element){
            documentElements.push_back(element);
        }
        // jitna bhi documentElement hai un sbko hm
        // ek jagah accumulate krke or phir return krege.
        string render(){
            string result;
            for(auto element:documentElements){
                result+= element->render();
            }
            return result;
        }
};

class Persistence{
    public:
        virtual void save(string data)=0;
};  

class fileStorage:public Persistence{
    public:
        void save(string data) override{
            ofstream outFile("documents.txt");
            if(outFile){
                outFile << data;
                outFile.close();
                cout<<"Document saved to documents.txt"<<endl;
            }
            else cout<<"Error while open file for writing"<<endl;
        };
};  
class dbStorage:public Persistence{
    public:
        void save(string data) override{
            // jo bhi business logic hoga
            // db me save krne ka.
        }
};

// ye documentEditor class client manage interaction ke liye hai.
class documentEditor{
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;
    public:
        documentEditor(Document* document,Persistence* storage){
            this->document=document;
            this->storage=storage;
        }

        void addText(string text){
            document->addElement(new textElement(text));
        }
        void addImage(string imagePath){
            document->addElement(new imageElement(imagePath));
        }
        void addTabSpace(){
            document->addElement(new tabSpaceElement());
        }
        void addNewLine(){
            document->addElement(new newLineElement());
        }
        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument=document->render();
            }
            return renderedDocument;
        }
        void saveDocument(){
            storage->save(renderDocument());
        }
};
int main(){

    Document* document= new Document();

    Persistence* persistence= new fileStorage();

    documentEditor* editor= new documentEditor(document,persistence);

    editor->addText("Hello world!!");
    editor->addNewLine();
    editor->addText("Hello world!!");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Wo text add kr rhe hai tab space ke baad");
    editor->addImage("rahul.jpg");


    cout<<editor->renderDocument()<<endl;

    editor->saveDocument();

    return 0;
}