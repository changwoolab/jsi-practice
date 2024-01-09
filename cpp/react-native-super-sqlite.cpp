#include "react-native-super-sqlite.h"
#include <iostream>

using namespace facebook;
using namespace std;

void installSequel(jsi::Runtime &rt) {
    cout << "Installing JSI bindings" << endl;
    
    // Make JSI Function (See ReactCommon/jsi/jsi.h & jsi.cpp)
    // function multiply() { }
    // const multiply = () => { }
    jsi::Function multiply = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "multiply"), 0,
       [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        return jsi::Value(42);
    });
    
    // Sets propery in global scope of javascript
    // { jsiMultiplication: multiply }
    rt.global().setProperty(rt, "jsiMultiplication", multiply);
};

void cleanUpSequel() {
    
};

/*
 function multiply() { }
 
 global.jsiMultiplication = multiply;
 
 jsiMultiplication();
 */
