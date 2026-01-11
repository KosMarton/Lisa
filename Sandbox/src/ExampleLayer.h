#pragma once

#include "Lisa.h"

class ExampleLayer : public Lisa::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Lisa::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Lisa::Event& e) override;
private:
	Lisa::ShaderLibrary m_ShaderLibrary;
	Lisa::Ref<Lisa::Shader> m_Shader;
	Lisa::Ref<Lisa::VertexArray> m_VertexArray;

	Lisa::Ref<Lisa::Shader> m_FlatColorShader;
	Lisa::Ref<Lisa::VertexArray> m_SquareVA;

	Lisa::Ref<Lisa::Texture2D> m_Texture, m_ChernoLogoTexture;

	Lisa::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
