#pragma once

#include "Lisa.h"

#include "ParticleSystem.h"

class Sandbox2D : public Lisa::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Lisa::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Lisa::Event& e) override;
private:
	Lisa::OrthographicCameraController m_CameraController;

	// Temp
	Lisa::Ref<Lisa::VertexArray> m_SquareVA;
	Lisa::Ref<Lisa::Shader> m_FlatColorShader;

	Lisa::Ref<Lisa::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;
};