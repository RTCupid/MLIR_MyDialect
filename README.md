
<div align="center">

# My MLIR Dialect — Custom Dialect and Transform Pass Example
  ![C++](https://img.shields.io/badge/C++-23-blue?style=for-the-badge&logo=cplusplus)
  ![CMake](https://img.shields.io/badge/CMake-3.20+-green?style=for-the-badge&logo=cmake)
  ![MLIR](https://img.shields.io/badge/MLIR-18.1+-yellow?style=for-the-badge&logo=llvm&logoColor=white)
  ![LLVM](https://img.shields.io/badge/LLVM-18.1+-blue?style=for-the-badge&logo=llvm)

</div>

Generic out-of-tree MLIR project generated from a cookiecutter template.

This project demonstrates how to create a custom MLIR dialect with several operations and implement a simple transformation pass. It serves as a learning example and shows the basic steps: defining operations in TableGen, writing a C++ transformation pass, and integrating it with MLIR.

Based on the [Toy-tutorial](https://mlir.llvm.org/docs/Tutorials/Toy/)

## Build and Run

This project expects a working MLIR/LLVM build with `MLIRConfig.cmake` available.

```bash
cmake -S . -B build -DMLIR_DIR=/path/to/lib/cmake/mlir
cmake --build build
```

Run:

```bash
./build/bin/my-mlir-opt examples/basic.mlir
```

## Structure

- `include/`: public headers and TableGen definitions
- `lib/`: dialect, transforms, and conversion implementations
- `tools/`: custom optimizer driver
- `test/`: lit configuration and sample tests
- `examples/`: example MLIR inputs

## MyDialect Overview

The dialect is defined in include/my-mlir/Dialect/MyDialect/IR/ using TableGen (.td files). It includes the following operations:
Operations

`wrap` — wraps a value into the dialect.
Syntax: `%result = mydialect.wrap %input : type`

`unwrap` — extracts a value from the dialect.
Syntax: `%result = mydialect.unwrap %input : type`

`transpose` — transposes a tensor.
Traits: pure operation (Pure), input and output types match.
Syntax: `%out = mydialect.transpose %in : tensor<...xf64>`

`add` — adds two tensors element-wise.
Traits: all operand and result types must match.
Syntax: `%result = mydialect.add %lhs, %rhs : tensor<...xf64>`

`print` — prints a tensor value (useful for debugging).
Syntax: `mydialect.print %input : tensor<...xf64>`

All operations work with `f64` tensors.

## Transform Pass

The my-transform pass (implemented in lib/Dialect/MyDialect/Transforms/MyTransform.cpp) simplifies redundant transpositions.
It applies the pattern SimplifyRedundantTranspose, which looks for a sequence like:

```mlir
%1 = mydialect.transpose %arg0
%2 = mydialect.transpose %1
```

and replaces it with the original value `%arg0` when the tensor types match.
The pass uses the greedy pattern rewrite driver (`GreedyPatternRewriteDriver`) and can be included in an `MLIR` optimization pipeline.

## Example Usage

Original MLIR code:
```mlir
module {
  func.func @test(%arg0: tensor<4x4xf64>) -> tensor<4x4xf64> {
    %1 = mydialect.transpose %arg0 : tensor<4x4xf64>
    %2 = mydialect.transpose %1   : tensor<4x4xf64>
    return %2 : tensor<4x4xf64>
  }
}
```

After applying the my-transform pass:

```mlir
module {
  func.func @test(%arg0: tensor<4x4xf64>) -> tensor<4x4xf64> {
    return %arg0 : tensor<4x4xf64>
  }
}
```

Two consecutive transpositions are removed because their combined effect is equivalent to an identity operation.

## Extending the Project

You can easily add new operations to the dialect by describing them in TableGen files. You can also write additional transformation passes by following the pattern shown in MyTransformPass.

For more in‑depth information, check the official MLIR documentation:
https://mlir.llvm.org/
