#ifndef MYDIALECT_CONVERSION_PASSES_H
#define MYDIALECT_CONVERSION_PASSES_H

#include <memory>
#include "mlir/Pass/Pass.h"

namespace mlir {
namespace my_project {

void registerMyDialectConversionPasses();
std::unique_ptr<Pass> createLowerToTargetPass();

}  // namespace my_project
}  // namespace mlir

#endif
