struct B 
{
    virtual void a(int);
    virtual void f();
    virtual void g() const;
    virtual void h(char);
    void k(); // not virtual
};

struct D : B
{
    void a(float) override; // doesn't override B::a(int) (wrong signature)
    void f() override; // overrides B::f()
    void g() override; // doesn't override B::g() (wrong type)
    void k() override; // doesn't override B::k() (B::k() is not virtual)
    void h(char); // overrides B::h(char)
};
