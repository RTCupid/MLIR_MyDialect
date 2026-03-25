#ifndef MYDIALECT_OPS_H
#define MYDIALECT_OPS_H

#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OpDefinition.h"

#include "my-mlir/Dialect/MyDialect/IR/MyDialectDialect.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#define GET_OP_CLASSES
#include "my-mlir/Dialect/MyDialect/IR/MyDialectOps.h.inc"

#endif
