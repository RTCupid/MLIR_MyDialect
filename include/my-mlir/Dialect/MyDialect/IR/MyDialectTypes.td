#ifndef MYDIALECT_TYPES_TD
#define MYDIALECT_TYPES_TD

include "my-mlir/Dialect/MyDialect/IR/MyDialectBase.td"

class MyDialect_Type<string name, string typeMnemonic>
    : TypeDef<MyDialect_Dialect, name> {
  let mnemonic = typeMnemonic;
}

#endif
