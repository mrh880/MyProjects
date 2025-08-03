#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Enums.h"

#include "FilesOperations.h"

using namespace std;

namespace FilesOperations
{
    string GetFullPathOfFile(const string &FileName)
    {
        return "Files\\" + FileName + ".txt";
    }

    bool isFileEmpty(fstream &File)
    {
        File.seekg(0, ios::beg);
        return File.peek() == ifstream::traits_type::eof();
    }

    bool Check_If_File_Was_Opend(fstream &File)
    {
        return File.is_open();
    }

    void OpenFile(fstream &File, enFileMode FileMode, const string &FilePath)
    {
        switch (FileMode)
        {
        case enFileMode::Read:
            File.open(FilePath, ios::in);
            break;
        case enFileMode::Write:
            File.open(FilePath, ios::out);
            break;
        case enFileMode::Append:
            File.open(FilePath, ios::out | ios::app);
            break;
        default:
            cerr << "Failed to open file because invalid type of file";
        }
        if (!Check_If_File_Was_Opend(File))
        {
            cerr << "Failed to open file '" << FilePath << "' in mode "
                 << (FileMode == enFileMode::Read ? "Read" : (FileMode == enFileMode::Write ? "Write" : "Append"))
                 << " mode." << endl;
            return;
        }
    }

    void CloseFile(fstream &File)
    {
        if (Check_If_File_Was_Opend(File))
            File.close();
    }

    void what_to_do_if_the_file_was_opened_for_printing_file_content(fstream &File)
    {
        if (isFileEmpty(File))
            cout << "FILE IS EMPTY\n";
        else
        {
            string Line = "";
            while (getline(File, Line))
                cout << Line << endl;
        }
        CloseFile(File);
    }

    void what_to_do_if_the_file_was_opened_for_loading_the_file_content_into_vector(fstream &File, vector<string> &vVectorContent)
    {
        string Line = "";
        while (getline(File, Line))
            vVectorContent.push_back(Line);
        CloseFile(File);
    }

    void what_to_do_if_the_file_was_opend_for_saving_vector_to_file(fstream &File, const vector<string> &vVectorcontent)
    {
        for (const string &Line : vVectorcontent)
        {
            if (!Line.empty())
                File << Line << endl;
        }
        CloseFile(File);
    }

    void what_to_do_if_file_was_opened_for_saving_lien_to_vector(fstream &File, const string &Line)
    {
        File << Line << endl;
    }

    void SaveLineToVector(const std::string &FileName, const std::string &Line)
    {
        fstream UserFile;
        
        string FilePath = GetFullPathOfFile(FileName);

        OpenFile(UserFile, enFileMode::Append, FilePath);

        if(!Check_If_File_Was_Opend(UserFile))
        {
            cerr << "Fle could not be opened " << FilePath << endl;
            return;
        }
        what_to_do_if_file_was_opened_for_saving_lien_to_vector(UserFile, Line);
        CloseFile(UserFile);
    }
    void PrintFileContent(const string &FileName)
    {
        string FilePath = GetFullPathOfFile(FileName);
        fstream UserFile;
        OpenFile(UserFile, enFileMode::Read, FilePath);
        if (!Check_If_File_Was_Opend(UserFile))
        {
            cout << "FILE WAS NOT OPENED\n";
            return;
        }
        what_to_do_if_the_file_was_opened_for_printing_file_content(UserFile);
    }

    void LoadDataFromFileToVector(const string &FileName, vector<string> &vVectorContent)
    {
        fstream UserFile;
        string FilePath = GetFullPathOfFile(FileName);
        OpenFile(UserFile, enFileMode::Read, FilePath);
        if (!Check_If_File_Was_Opend(UserFile))
        {
            cout << "FILE WAS NOT OPENED\n";
            return;
        }
        if (isFileEmpty(UserFile))
        {
            cout << "File is empty";
            return;
        }
        what_to_do_if_the_file_was_opened_for_loading_the_file_content_into_vector(UserFile, vVectorContent);
    }

    void SaveVectorToFile(const vector<string> &vVectorContent, const string &FileName)
    {
        string FilePath = GetFullPathOfFile(FileName);
        fstream Userfile;
        OpenFile(Userfile, enFileMode::Append, FilePath);
        if (!Check_If_File_Was_Opend(Userfile))
        {
            cout << "File was not opened\n";
            return;
        }
        what_to_do_if_the_file_was_opend_for_saving_vector_to_file(Userfile, vVectorContent);
    }

    void DeleteElementFromVector(vector<string> &vVectorContent, const string &RecordToDelete)
    {
        for (string &Line : vVectorContent)
            if (Line == RecordToDelete)
                Line = "";
    }

    void DeleteRecordFromFile(const string &FileName, string &RecordToDelete)
    {
        vector<string> TempVector;
        LoadDataFromFileToVector(FileName, TempVector);
        DeleteElementFromVector(TempVector, RecordToDelete);
        SaveVectorToFile(TempVector, FileName);
    }

    void UpdateRecordInVector(vector<string> &vVectorContent, const string &RecordToUpdate, const string &UpdateTo)
    {
        for (string &Line : vVectorContent)
            if (Line == RecordToUpdate)
                Line = UpdateTo;
    }

    void UpdateRecordInFile(const string &FileName, const string &RecordToUpdate, const string &UpdateTo)
    {
        vector<string> TempVector;
        LoadDataFromFileToVector(FileName, TempVector);
        UpdateRecordInVector(TempVector, RecordToUpdate, UpdateTo);
        SaveVectorToFile(TempVector, FileName);
    }
}