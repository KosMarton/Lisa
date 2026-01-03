#include <Lisa.h>

#include "imgui/imgui.h"

class ExampleLayer : public Lisa::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Lisa::VertexArray::Create()); // TRIANGLE

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
		};

		std::shared_ptr<Lisa::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Lisa::VertexBuffer::Create(vertices, sizeof(vertices)));
		Lisa::BufferLayout layout = {
				{ Lisa::ShaderDataType::Float3, "a_Position" },
				{ Lisa::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indicies[3] = { 0, 1, 2 };
		std::shared_ptr<Lisa::IndexBuffer> indexBuffer;
		indexBuffer.reset(Lisa::IndexBuffer::Create(indicies, sizeof(indicies) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Lisa::VertexArray::Create()); // SQUARE

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Lisa::VertexBuffer> squareVB;
		squareVB.reset(Lisa::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
				{ Lisa::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Lisa::IndexBuffer> squareIB;
		squareIB.reset(Lisa::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;
			
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;
			
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Lisa::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			
			void main()
			{
				color = vec4(0.278, 0.0, 0.439, 1.0);
			}
		)";

		m_BlueShader.reset(new Lisa::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(Lisa::Timestep ts) override
	{
		if (Lisa::Input::IsKeyPressed(LS_KEY_A))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (Lisa::Input::IsKeyPressed(LS_KEY_D))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Lisa::Input::IsKeyPressed(LS_KEY_W))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Lisa::Input::IsKeyPressed(LS_KEY_S))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Lisa::Input::IsKeyPressed(LS_KEY_Q))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Lisa::Input::IsKeyPressed(LS_KEY_E))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		Lisa::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Lisa::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Lisa::Renderer::BeginScene(m_Camera);

		Lisa::Renderer::Submit(m_BlueShader, m_SquareVA);
		Lisa::Renderer::Submit(m_Shader, m_VertexArray);

		Lisa::Renderer::EndScene();
	}
	
	virtual void OnImGuiRender() override
	{
		
	}

	void OnEvent(Lisa::Event& event) override
	{
	}
private:
	std::shared_ptr<Lisa::Shader> m_Shader;
	std::shared_ptr<Lisa::VertexArray> m_VertexArray;

	std::shared_ptr<Lisa::Shader> m_BlueShader;
	std::shared_ptr<Lisa::VertexArray> m_SquareVA;

	Lisa::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;
};

class Sandbox : public Lisa::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Lisa::Application* Lisa::CreateApplication()
{
	return new Sandbox();
}