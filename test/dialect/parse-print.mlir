// RUN: my-mlir-opt %s | FileCheck %s

func.func @parse_example(%arg0: i32) -> i32 {
  %0 = "mydialect.wrap"(%arg0) : (i32) -> i32
  %1 = "mydialect.unwrap"(%0) : (i32) -> i32
  return %1 : i32
}

// CHECK: mydialect.wrap
// CHECK: mydialect.unwrap
