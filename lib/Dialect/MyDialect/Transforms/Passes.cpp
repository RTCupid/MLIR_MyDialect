#include "my-mlir/Dialect/MyDialect/Transforms/Passes.h"
#include "my-mlir/Dialect/MyDialect/Transforms/ExampleTransform.h"
#include "my-mlir/Dialect/MyDialect/Transforms/GroupedPasses.h"

#include "mlir/Pass/PassRegistry.h"

namespace mlir {
namespace my_project {

void registerMyDialectPasses() {
  PassRegistration<ExampleTransformPass>();
  registerDefaultPipeline();
}

}  // namespace my_project
}  // namespace mlir
