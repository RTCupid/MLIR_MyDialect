#include "my-mlir/Dialect/MyDialect/Transforms/GroupedPasses.h"
#include "my-mlir/Dialect/MyDialect/Transforms/Passes.h"

#include "mlir/Pass/PassManager.h"
#include "mlir/Pass/PassRegistry.h"

namespace mlir {
namespace my_project {

struct DefaultPipelineOptions : public PassPipelineOptions<DefaultPipelineOptions> {};

void registerDefaultPipeline() {
  PassPipelineRegistration<DefaultPipelineOptions>(
      "mydialect-default-pipeline",
      "Run the default mydialect pipeline",
      [](OpPassManager &pm, const DefaultPipelineOptions &) {
        pm.addPass(createExampleTransformPass());
      });
}

}  // namespace my_project
}  // namespace mlir
