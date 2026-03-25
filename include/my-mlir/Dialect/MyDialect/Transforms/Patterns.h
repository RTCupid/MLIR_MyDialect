#ifndef MYDIALECT_TRANSFORMS_PATTERNS_H
#define MYDIALECT_TRANSFORMS_PATTERNS_H

#include "mlir/IR/PatternMatch.h" 
#include "mlir/Transforms/DialectConversion.h"
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.h"

namespace mlir {
namespace my_project {

struct SimplifyRedundantTranspose : public OpRewritePattern<TransposeOp> {
    using OpRewritePattern<TransposeOp>::OpRewritePattern;
    LogicalResult matchAndRewrite(TransposeOp op, PatternRewriter &rewriter) const override;
};

void populateMyTransformPatterns(RewritePatternSet &patterns);

} // namespace my_project
} // namespace mlir

#endif
