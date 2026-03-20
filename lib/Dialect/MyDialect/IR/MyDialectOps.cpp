#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.h"

using namespace mlir;
using namespace mlir::my_project;

#define GET_OP_CLASSES
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.cpp.inc"
