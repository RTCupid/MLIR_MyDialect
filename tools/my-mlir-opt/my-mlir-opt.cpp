#include "my-mlir/Dialect/MyDialect/IR/MyDialectDialect.h"
#include "my-mlir/Dialect/MyDialect/Transforms/Passes.h"

#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

using namespace mlir;

int main(int argc, char **argv) {
  DialectRegistry registry;

  registry.insert<arith::ArithDialect>();
  registry.insert<func::FuncDialect>();
  registry.insert<my_project::MyDialectDialect>();

  registerMyDialectPasses();

  return asMainReturnCode(
      MlirOptMain(argc, argv, "my MLIR Project optimizer\n", registry));
}
