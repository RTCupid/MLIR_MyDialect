#include "my-mlir/Dialect/MyDialect/Conversion/Passes.h"
#include "my-mlir/Dialect/MyDialect/Conversion/LowerToTarget.h"

#include "mlir/Pass/PassRegistry.h"

namespace mlir {
namespace my_project {

void registerMyDialectConversionPasses() {
  PassRegistration<LowerToTargetPass>();
}

}  // namespace my_project
}  // namespace mlir
