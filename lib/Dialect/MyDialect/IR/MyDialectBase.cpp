#include "my-mlir/Dialect/MyDialect/IR/MyDialectDialect.h"
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.h"

using namespace mlir;

using namespace mlir::my_project;

#include "my-mlir/Dialect/MyDialect/IR/MyDialectBase.cpp.inc"

void MyDialectDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.cpp.inc"
      >();
}
