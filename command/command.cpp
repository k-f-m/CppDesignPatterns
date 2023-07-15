/*
 * This example code shows how the Command pattern can be implemented in C++.
 *
 * The example provides a file system utility with methods for opening, writing, and closing files that supports multiple operating systems. 
 * To implement our file system utility, we first create an interface called Command, which have three methods: execute, undo, and redo. 
 * We have three classes that will implement this interface: OpenFileCommand, WriteFileCommand, and CloseFileCommand.
 * These classes have their own implementations of the execute, undo, and redo methods.
 */

#include <iostream>
#include <vector>

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

class OpenFileCommand : public Command {
public:
    OpenFileCommand(std::string filename) : filename_str(filename) {}
    void execute() override {
        // Open the file
        std::cout << "Opening file " << filename_str << std::endl;
    }
    void undo() override {
        // Close the file
        std::cout << "Closing file " << filename_str << std::endl;
    }
    void redo() override {
        execute();
    }
private:
    std::string filename_str;
};

class WriteFileCommand : public Command {
public:
    WriteFileCommand(std::string filename, std::string data) : filename_str(filename), data_str(data) {}
    void execute() override {
        // Write data to the file
        std::cout << "Writing data \"" << data_str << "\" to file " << filename_str << std::endl;
    }
    void undo() override {
        // Remove the data from the file
        std::cout << "Removing data \"" << data_str << "\" from file " << filename_str << std::endl;
    }
    void redo() override {
        execute();
    }
private:
    std::string filename_str;
    std::string data_str;
};

class CloseFileCommand : public Command {
public:
    CloseFileCommand(std::string filename) : filename_str(filename) {}
    void execute() override {
        // Close the file
        std::cout << "Closing file " << filename_str << std::endl;
    }
    void undo() override {
        // Re-open the file
        std::cout << "Re-opening file " << filename_str << std::endl;
    }
    void redo() override {
        execute();
    }
private:
    std::string filename_str;
};

class FileSystemInvoker {
public:
    FileSystemInvoker(Command* command) : command_obj(command) {}
    ~FileSystemInvoker() { delete command_obj; }
    void execute() { command_obj->execute(); }
    void undo() { command_obj->undo(); }
    void redo() { command_obj->redo(); }
private:
    Command* command_obj;
};

int main() {
    std::vector<FileSystemInvoker*> invokers;

    // Open a file
    invokers.push_back(new FileSystemInvoker(new OpenFileCommand("file.txt")));
    
    // Write some data to the file
    invokers.push_back(new FileSystemInvoker(new WriteFileCommand("file.txt", "HELLO WORLD!")));
    
    // Close the file
    invokers.push_back(new FileSystemInvoker(new CloseFileCommand("file.txt")));

    // Undo the last command (close the file)
    invokers.back()->undo();

    // Redo the last command (close the file)
    invokers.back()->redo();

}