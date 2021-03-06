#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class NodeVisitor;
class NodeIterator;

class Node{
  public:
    Node(const char * path): _path(path)
    {
      lstat(_path, &_st);
      string str(_path);
      _nodePath = str;
      _nodeName = _nodePath;
      _nodeName = str.substr(str.rfind("/")+1);
    }

    int size() const
    {
      return _st.st_size;
    }

    string name()
    {
      return _nodeName;
    }

    string getPath()
    {
      //return string(_path);
      return _nodePath;
    }

    virtual void add(Node *node)
    {
      throw string("unable to add");
    }

    virtual void remove(Node *node)
    {
        throw std::string("unable to remove");
    }

    virtual int numberOfChildren() const
    {
      return 0;
    }

    virtual void accept(NodeVisitor *NodeVisitor) = 0;

    virtual NodeIterator* createIterator() = 0;
    /*{
      return new NullIterator;
    }*/

  private:
    const char * _path;
    struct stat _st;
    string _nodeName;
    string _nodePath;
};

#endif
