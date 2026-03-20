#include "my-mlir/Dialect/MyDialect/Conversion/LowerToTarget.h"

namespace mlir {
namespace my_project {

StringRef LowerToTargetPass::getArgument() const {
  return "mydialect-lower-to-target";
}

StringRef LowerToTargetPass::getDescription() const {
  return "Example lowering pass stub";
}

void LowerToTargetPass::runOnOperation() {
  // Template stub: add conversion patterns here.
}

std::unique_ptr<Pass> createLowerToTargetPass() {
  return std::make_unique<LowerToTargetPass>();
}

}  // namespace my_project
}  // namespace mlir
