#ifndef WORKSPACES_TFE23_2_EXERCISE_003_MYVECTOR_HPP
#define WORKSPACES_TFE23_2_EXERCISE_003_MYVECTOR_HPP

class MyVector 
{
public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    unsigned int size();
    unsigned int get_current_size();
    void resize(int new_elements);
    void push_back(int element);
    //void push_back(int &element);
    //void push_back(int* element);
    int at(unsigned int index);

private:
    int* data;
    unsigned int m_size;
    unsigned int current_size = 0;
};
#endif