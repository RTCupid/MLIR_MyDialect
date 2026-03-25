#ifndef MYDIALECT_OPS_TD
#define MYDIALECT_OPS_TD

include "mlir/IR/OpBase.td"
include "my-mlir/Dialect/MyDialect/IR/MyDialectBase.td"
include "my-mlir/Dialect/MyDialect/IR/MyDialectTypes.td"

include "mlir/Interfaces/SideEffectInterfaces.td"

class MyDialect_Op<string mnemonic, list<Trait> traits = []>
    : Op<MyDialect_Dialect, mnemonic, traits>;

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

def TransposeOp : MyDialect_Op<"transpose", [Pure, AllTypesMatch<["input", "output"]>]> {
  let summary = "Transpose operation";
  let arguments = (ins F64Tensor:$input);
  let results = (outs F64Tensor:$output);
  let assemblyFormat = "$input attr-dict `:` type($input)";
}

def MyDialect_PrintOp : MyDialect_Op<"print"> {
  let arguments = (ins F64Tensor:$input);

  let assemblyFormat = "$input attr-dict `:` type($input)";
}

def MyDialect_AddOp
    : MyDialect_Op<"add"> {
  let summary = "Get sum of two values";

  let description = [{
    Scheme of operation's job:
    result value = first + second;
  }];

  let arguments = (ins F64Tensor: $lhs, F64Tensor: $rhs);
  let results = (outs F64Tensor: $result);

  let assemblyFormat = "$lhs `,` $rhs attr-dict `:` type($lhs)";

  let traits = [AllTypesMatch<["lhs", "rhs", "result"]>];
}

#endif
