#ifndef MYDIALECT_BASE_TD
#define MYDIALECT_BASE_TD

include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/OpBase.td"

def MyDialect_Dialect : Dialect {
  let name = "mydialect";

  let summary = "A high-level dialect that provides addition and multiplication operations";

  let description = [{
    The Compute language is a tensor-based language that allows you to define
    functions, perform some match computation, and print results.
  }];

  let cppNamespace = "::mlir::my_project";
}

#endif
