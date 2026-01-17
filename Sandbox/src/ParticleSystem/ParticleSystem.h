#pragma once

#include <Lisa.h>

struct ParticleProps
{
	glm::vec2 Position;
	glm::vec2 Velocity, VelocityVariation;
	glm::vec4 ColorBegin, ColorEnd;
	float SizeBegin, SizeEnd, SizeVariation;
	float LifeTime = 1.0f;
};

class ParticleSystem
{
public:
	ParticleSystem(uint32_t maxParticles = 100000);

	void OnUpdate(Lisa::Timestep ts);
	void OnRender(Lisa::OrthographicCamera& camera);

	void Emit(const ParticleProps& particleProps);
private:
	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity;
		glm::vec4 ColorBegin, ColorEnd;
		float Rotation = 0.0f;
		float SizeBegin, SizeEnd;

		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;

		bool Active = false;
	};
	std::vector<Particle> m_ParticlePool;
	uint32_t m_PoolIndex;
};

////////////////////////- IMPLEMENTATION -//////////////////////////////
#if LS_PARTICLE_EXAMPLE

 	ParticleSystem m_ParticleSystem;
 	ParticleProps m_Particle;
 	
 	// Should happen on Init
 	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
 	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
 	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
 	m_Particle.LifeTime = 5.0f;
 	m_Particle.Velocity = { 0.0f, 0.0f };
 	m_Particle.VelocityVariation = { 3.0f, 1.0f };
 	m_Particle.Position = { 0.0f, 0.0f };
 	
    // Should happen in the Runloop
 	if (Lisa::Input::IsMouseButtonPressed(LS_MOUSE_BUTTON_LEFT))
 	{
 		auto [x, y] = Lisa::Input::GetMousePosition();
 		auto width = Lisa::Application::Get().GetWindow().GetWidth();
 		auto height = Lisa::Application::Get().GetWindow().GetHeight();
 	
 		auto bounds = m_CameraController.GetBounds();
 		auto pos = m_CameraController.GetCamera().GetPosition();
 		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
 		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
 		m_Particle.Position = { x + pos.x, y + pos.y };
 		for (int i = 0; i < 5; i++)
 			m_ParticleSystem.Emit(m_Particle);
 	}
 	
 	m_ParticleSystem.OnUpdate(ts);
 	m_ParticleSystem.OnRender(m_CameraController.GetCamera());
   

#endif
////////////////////////!!!!!!!!!!!!!!//////////////////////////////////