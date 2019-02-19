struct A {
    A(int a = 0) : a_(a)
    {
    }

    int a_;
};

void test()
{
    A a(1);
    A b = a;
    A c;
    c = a;
#if 0
    A as[10], bs[10];
    bs = as;
#endif
}