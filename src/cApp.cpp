#include "cApp.hpp"

CApp::CApp() {
  
}

int CApp::OnExecute() {
  return 0;
}

int main() {
  CApp theApp;
  
  return theApp.OnExecute();
}
