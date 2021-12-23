// Copyright (C) 2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <editor.hpp>
#include <fstream>
#include <openvino/frontend/input_model.hpp>

namespace ov {
namespace frontend {
namespace onnx {

class InputModel : public ov::frontend::InputModel {
public:
    InputModel(const std::string& path, const std::shared_ptr<ov::frontend::TelemetryExtension>& telemetry = {});
#if defined(OPENVINO_ENABLE_UNICODE_PATH_SUPPORT) && defined(_WIN32)
    InputModel(const std::wstring& path, const std::shared_ptr<ov::frontend::TelemetryExtension>& telemetry = {});
#endif
    InputModel(std::istream& model_stream, const std::shared_ptr<ov::frontend::TelemetryExtension>& telemetry = {});
    // The path can be required even if the model is passed as a stream because it is necessary
    // for ONNX external data feature
    InputModel(std::istream& model_stream,
               const std::string& path,
               const std::shared_ptr<ov::frontend::TelemetryExtension>& telemetry = {});
#ifdef OPENVINO_ENABLE_UNICODE_PATH_SUPPORT
    InputModel(std::istream& model_stream,
               const std::wstring& path,
               const std::shared_ptr<ov::frontend::TelemetryExtension>& telemetry = {});
#endif

    std::vector<ov::frontend::Place::Ptr> get_inputs() const override;
    std::vector<ov::frontend::Place::Ptr> get_outputs() const override;
    ov::frontend::Place::Ptr get_place_by_tensor_name(const std::string& tensor_name) const override;
    ov::frontend::Place::Ptr get_place_by_operation_name(const std::string& operation_name) const override;
    ov::frontend::Place::Ptr get_place_by_operation_name_and_input_port(const std::string& operation_name,
                                                                        int input_port_index) override;
    ov::frontend::Place::Ptr get_place_by_operation_name_and_output_port(const std::string& operation_name,
                                                                         int output_port_index) override;

    void set_name_for_tensor(const ov::frontend::Place::Ptr& tensor, const std::string& new_name) override;
    void set_name_for_operation(const ov::frontend::Place::Ptr& operation, const std::string& new_name) override;
    void free_name_for_operation(const std::string& name) override;
    void set_name_for_dimension(const ov::frontend::Place::Ptr& place,
                                size_t shape_dim_index,
                                const std::string& dim_name) override;

    void add_name_for_tensor(const ov::frontend::Place::Ptr& tensor, const std::string& new_name) override;

    /// \brief  Not applicable for ONNX model. Throws immediately
    void free_name_for_tensor(const std::string& name) override;

    void set_partial_shape(const ov::frontend::Place::Ptr& place, const ngraph::PartialShape& shape) override;
    ngraph::PartialShape get_partial_shape(const ov::frontend::Place::Ptr& place) const override;
    void set_element_type(const ov::frontend::Place::Ptr& place, const ngraph::element::Type& type) override;

    std::shared_ptr<Model> decode();
    std::shared_ptr<Model> convert();

    // Editor features
    void override_all_outputs(const std::vector<ov::frontend::Place::Ptr>& outputs) override;
    void override_all_inputs(const std::vector<ov::frontend::Place::Ptr>& inputs) override;
    void extract_subgraph(const std::vector<ov::frontend::Place::Ptr>& inputs,
                          const std::vector<ov::frontend::Place::Ptr>& outputs) override;

private:
    std::shared_ptr<ov::onnx_editor::ONNXModelEditor> m_editor;

    std::unordered_map<std::string, std::unordered_set<std::string>> m_additional_tensor_names;
    void add_tensor_names(std::shared_ptr<Model>& model);

    std::unordered_map<std::string, ov::PartialShape> m_inputs_to_reshape;
    void reshape_model_inputs(std::shared_ptr<Model>& model);
};

}  // namespace onnx
}  // namespace frontend
}  // namespace ov