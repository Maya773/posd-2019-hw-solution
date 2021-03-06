#ifndef LINK
#define LINK

#include <string>
#include <memory>
#include <unistd.h>
#include <regex>
#include <sys/stat.h>
#include "node.h"
#include "null_iterator.h"

class Link : public Node
{
public:
    Link(std::string path, Node *node = nullptr) : Node(path), _node(node)
    {
        struct stat _st;
        lstat(path.c_str(), &_st);
        if (!S_ISLNK(_st.st_mode))
            throw(std::string("It is not Link!"));
        // Change the target of the symlink to Node
        _symlinkPath = new char[getPath().length()];
        strcpy(_symlinkPath, getPath().c_str());
        this->addLink(node);
    }

    void accept(FindVisitor *fv) override
    {
        fv->visitLink(this);
    }

    void addLink(Node *node) // add symbolic link
    {
        // First unlink then link to the new path
        unlink(_symlinkPath);
        char targetPath[node->getPath().length()];
        strcpy(targetPath, node->getPath().c_str());
        symlink(targetPath, _symlinkPath);
    }

    Node *getSource() // return node that the link point to!
    {
        return _node;
    }

    Iterator *createIterator() override
    {
        return new NullIterator();
    }

    void accept(UpdatePathVisitor *upv) override
    {
        upv->visitLink(this);
    }

    std::string targetName()
    {
        return _node->name();
    }

    std::string getTargetPath()
    {
        return _node->getPath();
    }

private:
    Node *_node;
    char *_symlinkPath;
};

#endif