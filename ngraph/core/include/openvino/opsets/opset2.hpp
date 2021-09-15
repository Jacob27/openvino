// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/op/ops.hpp"

namespace ov {
namespace opset2 {
#define OPENVINO_OP(a, b) using b::a;
#include "openvino/opsets/opset2_tbl.hpp"
#undef OPENVINO_OP
}  // namespace opset2
}  // namespace ov