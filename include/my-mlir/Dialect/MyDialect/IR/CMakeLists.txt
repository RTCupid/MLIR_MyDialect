set(LLVM_TARGET_DEFINITIONS MyDialect.td)

mlir_tablegen(MyDialectBase.h.inc -gen-dialect-decls -dialect=mydialect)
mlir_tablegen(MyDialectBase.cpp.inc -gen-dialect-defs -dialect=mydialect)
mlir_tablegen(MyDialectOps.h.inc -gen-op-decls)
mlir_tablegen(MyDialectOps.cpp.inc -gen-op-defs)

add_public_tablegen_target(MyDialectIRIncGen)
