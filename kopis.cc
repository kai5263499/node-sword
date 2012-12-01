#define BUILDING_NODE_EXTENSION
#include <node.h>

#include <swmgr.h> // SWORD Project
#include <swmodule.h> // SWORD Project
#include <markupfiltmgr.h> // SWORD Project
#include <versekey.h> // SWORD Project

#include <string>
#include <vector>

using namespace v8;
using namespace sword;
using namespace std;

Handle<Value> RunCallback(const Arguments& args) {
  HandleScope scope;

  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  
  
  vector <string> modules;
  SWMgr library;
  ModMap::iterator it;
  for (it = library.Modules.begin(); it != library.Modules.end(); ++it) {
    SWModule *module = (*it).second;
    if (!strcmp(module->getType(), SWMgr::MODTYPE_COMMENTARIES)) {
        modules.push_back(module->getName());
    }
  }
  
  
  Local<Value> argv[argc] = { Local<Value>::New(String::New("hello world")) };
  cb->Call(Context::GetCurrent()->Global(), argc, argv);

  return scope.Close(Undefined());
}

void Init(Handle<Object> target) {
  target->Set(String::NewSymbol("runCallback"),
      FunctionTemplate::New(RunCallback)->GetFunction());
}

NODE_MODULE(kopis, Init)
