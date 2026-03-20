add_llvm_executable(my-mlir-opt
  my-mlir-opt.cpp
)

llvm_update_compile_flags(my-mlir-opt)

target_link_libraries(my-mlir-opt PRIVATE
  MyDialectIR
  MLIRMyDialectTransforms
  MLIRMyDialectConversion
  MLIRArithDialect
  MLIRFuncDialect
  MLIRIR
  MLIRParser
  MLIRPass
  MLIRSupport
  MLIROptLib
)

install(TARGETS my-mlir-opt
  RUNTIME DESTINATION bin
)
