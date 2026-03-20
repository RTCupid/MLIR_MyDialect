// RUN: my-mlir-opt -mydialect-lower-to-target %s | FileCheck %s

module {
  func.func @lowering_smoke() {
    return
  }
}

// CHECK: module
