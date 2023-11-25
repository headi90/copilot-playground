#pragma once

class Hello {
public:
    explicit Hello(int i);
    void print();
    int get_i() const { return i_; };

private:
    int i_{};
};
