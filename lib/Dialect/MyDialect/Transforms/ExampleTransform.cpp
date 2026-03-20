#include "my-mlir/Dialect/MyDialect/Transforms/ExampleTransform.h"
#include "my-mlir/Dialect/MyDialect/IR/MyDialectDialect.h"
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.h"

#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/DialectRegistry.h"

namespace mlir {
namespace my_project {

StringRef ExampleTransformPass::getArgument() const {
  return "mydialect-example-transform";
}

StringRef ExampleTransformPass::getDescription() const {
  return "Example transform pass for the generated template";
}

void ExampleTransformPass::getDependentDialects(DialectRegistry &registry) const {
  registry.insert<MyDialectDialect>();
}

void ExampleTransformPass::runOnOperation() {
  func::FuncOp func = getOperation();

  func.walk([&](arith::ConstantOp op) {
    if (!op.getType().isIntOrIndex())
      return;

    OpBuilder builder(op);
    builder.setInsertionPointAfter(op);
    auto wrapped = builder.create<WrapOp>(op.getLoc(), op.getType(), op.getResult());
    builder.create<UnwrapOp>(op.getLoc(), op.getType(), wrapped.getResult());
  });
}

std::unique_ptr<Pass> createExampleTransformPass() {
  return std::make_unique<ExampleTransformPass>();
}

}  // namespace my_project
}  // namespace mlir
