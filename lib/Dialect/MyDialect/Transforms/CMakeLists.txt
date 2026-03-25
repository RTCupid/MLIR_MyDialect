set(LLVM_TARGET_DEFINITIONS
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../../include/my-mlir/Dialect/MyDialect/Transforms/MyDialectPasses.td
)

mlir_tablegen(MyDialectPasses.h.inc
  -gen-pass-decls
  -name MyDialect
)

add_public_tablegen_target(MLIRMyDialectPassIncGen)

add_mlir_library(MLIRMyDialectTransforms
  Passes.cpp
  Patterns.cpp
  GroupedPasses.cpp
  ExampleTransform.cpp
  MyTransform.cpp

  DEPENDS
  MyDialectIRIncGen
  MLIRMyDialectPassIncGen

  LINK_LIBS PUBLIC
  MyDialectIR
  MLIRArithDialect
  MLIRFuncDialect
  MLIRIR
  MLIRPass
  MLIRTransforms
)

target_include_directories(MLIRMyDialectTransforms PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../../include
  ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS MLIRMyDialectTransforms
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
