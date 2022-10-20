#include "Factory.h"
#include "DummyTool.h"
#include "WCSimTool.h"

Tool* Factory(std::string tool) {
Tool* ret=0;

// if (tool=="Type") tool=new Type;
  if (tool=="DummyTool") ret=new DummyTool;
  if (tool=="WCSimTool") ret=new WCSimTool;
return ret;
}
