#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "Enums.h"

namespace FilesOperations
{
    std::string GetFullPathOfFile(const std::string &FileName);

    bool isFileEmpty(std::fstream &File);

    bool Check_If_File_Was_Opend(std::fstream &File);

    void OpenFile(std::fstream &File, enFileMode FileMode, const std::string &FilePath);

    void CloseFile(std::fstream &File);

    void what_to_do_if_the_file_was_opened_for_printing_file_content(std::fstream &File);

    void what_to_do_if_the_file_was_opened_for_loading_the_file_content_into_vector(std::fstream &File, std::vector<std::string> &vVectorContent);

    void what_to_do_if_the_file_was_opend_for_saving_vector_to_file(std::fstream &File, const std::vector<std::string> &vVectorcontent);

    void SaveLineToFile(const std::string &FileName, const std::string &Lien);

    void PrintFileContent(const std::string &FileName);

    void LoadDataFromFileToVector(const std::string &FileName, std::vector<std::string> &vVectorContent);

    void SaveVectorToFile(const std::vector<std::string> &vVectorContent, const std::string &FileName);

    void DeleteElementFromVector(std::vector<std::string> &vVectorContent, const std::string &RecordToDelete);

    void DeleteRecordFromFile(const std::string &FileName, std::string &RecordToDelete);

    void UpdateRecordInVector(std::vector<std::string> &vVectorContent, const std::string &RecordToUpdate, const std::string &UpdateTo);

    void UpdateRecordInFile(const std::string &FileName, const std::string &RecordToUpdate, const std::string &UpdateTo);
}