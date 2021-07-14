#include <emscripten.h>
#include <stdio.h>



//Declar resualt js functio

// return type, name of function, variables being passed, function itself
EM_JS( void, jsFunction, (int n), {
  console.log("Call from em_js :" + n)
})
int main() {
  printf("WASM READY\n");

  // Call JS function
  // Would be using function eval

  emscripten_run_script("console.log('Hello from C!')");


// Async run script
  emscripten_async_run_script("console.log('Hello from C! async')", 2000);


// Calling js function -int
  int jsVal = emscripten_run_script_int("getNum()");


// Calling js function -String
  char * jsValStr = emscripten_run_script_string("getStr()");

  printf("Val from get num %d\n", jsVal);
  printf("Val from get str %s\n", jsValStr);
  jsFunction(144);
  return 1;
}
