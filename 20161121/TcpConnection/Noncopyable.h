#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H


class Noncopyable //禁用值语义
{
public:
    Noncopyable() { }
    ~Noncopyable() { }
private:
    Noncopyable(const Noncopyable &);
    void operator=(const Noncopyable &);
};


#endif //NONCOPYABLE_H
