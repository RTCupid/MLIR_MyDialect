#ifndef MYDIALECT_BASE_TD
#define MYDIALECT_BASE_TD

include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/OpBase.td"

def MyDialect_Dialect : Dialect {
  let name = "mydialect";
  let cppNamespace = "::mlir::my_project";
}

class MyDialect_Type<string name, string typeMnemonic>
    : TypeDef<MyDialect_Dialect, name> {
  let mnemonic = typeMnemonic;
}

class MyDialect_Op<string mnemonic, list<Trait> traits = []>
    : Op<MyDialect_Dialect, mnemonic, traits>;

#endif
