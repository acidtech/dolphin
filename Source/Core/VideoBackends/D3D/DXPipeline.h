// Copyright 2017 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <d3d11.h>
#include <memory>
#include "VideoCommon/AbstractPipeline.h"

namespace DX11
{
class DXPipeline final : public AbstractPipeline
{
public:
  DXPipeline(ID3D11InputLayout* input_layout, ID3D11VertexShader* vertex_shader,
             ID3D11GeometryShader* geometry_shader, ID3D11PixelShader* pixel_shader,
             ID3D11RasterizerState* rasterizer_state, ID3D11DepthStencilState* depth_state,
             ID3D11BlendState* blend_state, D3D11_PRIMITIVE_TOPOLOGY primitive_topology,
             bool use_logic_op);
  ~DXPipeline() override;

  ID3D11InputLayout* GetInputLayout() const { return m_input_layout; }
  ID3D11VertexShader* GetVertexShader() const { return m_vertex_shader; }
  ID3D11GeometryShader* GetGeometryShader() const { return m_geometry_shader; }
  ID3D11PixelShader* GetPixelShader() const { return m_pixel_shader; }
  ID3D11RasterizerState* GetRasterizerState() const { return m_rasterizer_state; }
  ID3D11DepthStencilState* GetDepthState() const { return m_depth_state; }
  ID3D11BlendState* GetBlendState() const { return m_blend_state; }
  D3D11_PRIMITIVE_TOPOLOGY GetPrimitiveTopology() const { return m_primitive_topology; }
  bool HasGeometryShader() const { return m_geometry_shader != nullptr; }
  bool UseLogicOp() const { return m_use_logic_op; }

  static std::unique_ptr<DXPipeline> Create(const AbstractPipelineConfig& config);

private:
  ID3D11InputLayout* m_input_layout;
  ID3D11VertexShader* m_vertex_shader;
  ID3D11GeometryShader* m_geometry_shader;
  ID3D11PixelShader* m_pixel_shader;
  ID3D11RasterizerState* m_rasterizer_state;
  ID3D11DepthStencilState* m_depth_state;
  ID3D11BlendState* m_blend_state;
  D3D11_PRIMITIVE_TOPOLOGY m_primitive_topology;
  bool m_use_logic_op;
};
}  // namespace DX11
