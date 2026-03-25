#include "my-mlir/Dialect/MyDialect/Transforms/Passes.h"
#include "my-mlir/Dialect/MyDialect/Transforms/Patterns.h"
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.h"

#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

#define GEN_PASS_DEF_MYTRANSFORM
#include "MyDialectPasses.h.inc"

using namespace mlir;
using namespace mlir::my_project;

namespace {
class MyTransformPass : public ::impl::MyTransformBase<MyTransformPass> {
public:
  using Base::Base;

  void runOnOperation() override {
    MLIRContext *ctx = &getContext();

    RewritePatternSet patterns(ctx);
    patterns.add<SimplifyRedundantTranspose>(ctx);

    if (failed(applyPatternsAndFoldGreedily(getOperation(), std::move(patterns))))
      signalPassFailure();
  }
};
} // namespace

std::unique_ptr<Pass> mlir::my_project::createMyTransformPass() {
  return std::make_unique<MyTransformPass>();
}
