#include "my-mlir/Dialect/MyDialect/Transforms/Passes.h"

namespace mlir {
namespace my_project {

#define GEN_PASS_DEF_MYTRANSFORM
#include "MyDialectPasses.h.inc"
#undef GEN_PASS_DEF_MYTRANSFORM

}  // namespace my_project
}  // namespace mlir

