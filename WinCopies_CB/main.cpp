// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

//Project dllCBox;  File dllMain.cpp
#include <stdio.h>

extern "C" class __declspec(dllexport) CBox
{
 public:
 CBox(double dblLen, double dblWidth, double dblHeight)
 {
  printf("Called CBox() Constructor\n");
  m_Length=dblLen;
  m_Width=dblWidth;
  m_Height=dblHeight;
 }

 ~CBox()
 {
  printf("Called CBox() Destructor\n");
 }

 double Volume()
 {
  return m_Length*m_Width*m_Height;
 }

 private:
 double m_Length;
 double m_Width;
 double m_Height;
};


BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved)
{
 switch(reason)
 {
  case DLL_PROCESS_ATTACH:
    break;
  case DLL_PROCESS_DETACH:
    break;
 }

 return TRUE;
}

//Project CBoxHost;  File Main.cpp
#include <stdio.h>

extern "C" class __declspec(dllimport) CBox
{
 public:
 CBox(double,double,double);
 ~CBox();
 double Volume();

 private:
 double m_Length;
 double m_Width;
 double m_Height;
};


int main(void)
{
 CBox box1(3.0,4.0,5.0);

 printf("box1.Volume()=%f\n",box1.Volume());
 getchar();

 return 0;
}

extern "C"
{
    // A function adding two integers and returning the result
    int SampleAddInt(int i1, int i2)
    {
        return i1 + i2;
    }

    // A function doing nothing ;)
    void SampleFunction1()
    {
        // insert code here
    }

    // A function always returning zero
    int SampleFunction2()
    {
        // insert code here

        return 0;
    }
}
