#include "my-mlir/Dialect/MyDialect/Transforms/Patterns.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/Passes.h"

namespace mlir {
namespace my_project {

LogicalResult SimplifyRedundantTranspose::matchAndRewrite(TransposeOp op,
                                            PatternRewriter &rewriter) const {
    Value input = op.getOperand();

    if (auto prev = input.getDefiningOp<TransposeOp>()) {
        rewriter.replaceOp(op, prev.getOperand());
        return success();
    }
    return failure();
}

void populateMyTransformPatterns(RewritePatternSet &patterns) {
    patterns.add<SimplifyRedundantTranspose>(patterns.getContext());
}

} // namespace my_project
} // namespace mlir
