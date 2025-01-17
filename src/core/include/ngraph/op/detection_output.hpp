// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "ngraph/op/op.hpp"
#include "openvino/op/detection_output.hpp"

namespace ngraph {
namespace op {
using DetectionOutputAttrs = ov::op::v0::DetectionOutput::Attributes;

namespace v0 {
using ov::op::v0::DetectionOutput;
}  // namespace v0
using v0::DetectionOutput;
}  // namespace op
}  // namespace ngraph
