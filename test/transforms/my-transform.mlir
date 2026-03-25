module {
  func.func @test(%arg0: tensor<4x4xf64>) -> tensor<4x4xf64> {
    %1 = mydialect.transpose %arg0 : tensor<4x4xf64>
    %2 = mydialect.transpose %1   : tensor<4x4xf64>
    return %2 : tensor<4x4xf64>
  }
}
