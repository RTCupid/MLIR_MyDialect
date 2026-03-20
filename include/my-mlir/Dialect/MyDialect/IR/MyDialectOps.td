#ifndef MYDIALECT_OPS_TD
#define MYDIALECT_OPS_TD

include "mlir/IR/OpBase.td"
include "my-mlir/Dialect/MyDialect/IR/MyDialectBase.td"

def MyDialect_WrapOp
    : MyDialect_Op<"wrap"> {
  let summary = "Wrap a value in the dialect";
  let arguments = (ins AnyType:$input);
  let results = (outs AnyType:$result);
}

def MyDialect_UnwrapOp
    : MyDialect_Op<"unwrap"> {
  let summary = "Unwrap a dialect value";
  let arguments = (ins AnyType:$input);
  let results = (outs AnyType:$result);
}

def MyDialect_Add
    : MyDialect_Op<"add"> {
  let summary = "Add two values";

  let description = [{
    Scheme of operation's job:
    result value = first + second
  }]

  let arguments = (ins

  )

  let results = (outs
    
  )

}

#endif
