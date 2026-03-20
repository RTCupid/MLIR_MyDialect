// RUN: my-mlir-opt -pass-pipeline='builtin.module(func.func(mydialect-example-transform))' %s | FileCheck %s

func.func @transform_example() {
  %0 = arith.constant 7 : i32
  return
}

// CHECK: mydialect.wrap
// CHECK: mydialect.unwrap
