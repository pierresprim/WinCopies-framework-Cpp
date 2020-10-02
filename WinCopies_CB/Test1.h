#ifndef TEST1_H_INCLUDED
#define TEST1_H_INCLUDED

extern "C" __declspec(dllexport) class Test1
{
    public:
        Test1()
        {

        }

        virtual ~Test1()
        {

        }

        void SaySomething();
};

#endif // TEST1_H_INCLUDED
