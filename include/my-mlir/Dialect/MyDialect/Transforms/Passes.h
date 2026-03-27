#ifndef MYDIALECT_TRANSFORMS_PASSES_H
#define MYDIALECT_TRANSFORMS_PASSES_H

#include <memory>
#include "mlir/Pass/Pass.h"

namespace mlir {
namespace my_project {

std::unique_ptr<Pass> createMyTransformPass();
void registerMyDialectPasses();

}  // namespace my_project
}  // namespace mlir

#define GEN_PASS_REGISTRATION
#include "MyDialectPasses.h.inc"
#undef GEN_PASS_REGISTRATION

#endif
