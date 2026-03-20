#ifndef MYDIALECT_TRANSFORMS_PASSES_H
#define MYDIALECT_TRANSFORMS_PASSES_H

#include <memory>
#include "mlir/Pass/Pass.h"

namespace mlir {
namespace my_project {

void registerMyDialectPasses();
std::unique_ptr<Pass> createExampleTransformPass();

}  // namespace my_project
}  // namespace mlir

#endif
