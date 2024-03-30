/*
#pragma once
#include <cassert>
#include <SDL_keyboard.h>
#include <SDL_mouse.h>

#include "Math.h"
#include <glm/glm/glm.hpp>

//#include "Timer.h"

namespace dae
{
	struct Camera
	{
		Camera() = default;

		Camera(const glm::vec3& _origin, float _fovAngle) :
			origin{ _origin },
			fovAngle{ _fovAngle }
		{
		}

		glm::vec3 origin{};
		float fovAngle{ 45.0f };
		float fov{ tanf((fovAngle * TO_RADIANS) / 2.0f) };
		float aspectRatio{};
		float nearPlane{ 0.1f };
		float farPlane{ 1000.0f };

		glm::vec3 forward{ glm::vec3::UnitZ };
		glm::vec3 up{ glm::vec3::UnitY };
		glm::vec3 right{ glm::vec3::UnitX };

		float totalPitch{};
		float totalYaw{};
		const float cameraMovementSpeed{ 10.0f };
		const float cameraRotationSpeed{ 2.0f };

		Matrix invViewMatrix{};
		Matrix viewMatrix{};
		Matrix projectionMatrix{};

		void Initialize(float _fovAngle = 90.0f, glm::vec3 _origin = { 0.0f, 0.0f, 0.0f }, float aspect = 1.0f)
		{
			fovAngle = _fovAngle;
			fov = tanf((fovAngle * TO_RADIANS) / 2.0f);
			origin = _origin;
			aspectRatio = aspect;

			CalculateProjectionMatrix();
		}

		void CalculateViewMatrix()
		{
			invViewMatrix = Matrix::CreateRotation(totalPitch, totalYaw, 0.0f);
			invViewMatrix *= Matrix::CreateTranslation(origin);

			//Inverse(ONB) => ViewMatrix
			viewMatrix = Matrix::Inverse(invViewMatrix);
		}

		void CalculateProjectionMatrix()
		{
			projectionMatrix = Matrix::CreatePerspectiveFovLH(fov, aspectRatio, nearPlane, farPlane);
		}

		void Update(const Timer* pTimer)
		{
			const float deltaTime = pTimer->GetElapsed();

			//Keyboard Input
			const uint8_t* pKeyboardState = SDL_GetKeyboardState(nullptr);

			glm::vec3 movementDirection{ };

			if (pKeyboardState[SDL_SCANCODE_W])
			{
				++movementDirection.z;
			}
			if (pKeyboardState[SDL_SCANCODE_A])
			{
				--movementDirection.x;
			}
			if (pKeyboardState[SDL_SCANCODE_S])
			{
				--movementDirection.z;
			}
			if (pKeyboardState[SDL_SCANCODE_D])
			{
				++movementDirection.x;
			}

			//Mouse Input
			int mouseX{}, mouseY{};
			const uint32_t mouseState = SDL_GetRelativeMouseState(&mouseX, &mouseY);

			if (mouseState & SDL_BUTTON_RMASK && mouseState & SDL_BUTTON_LMASK)
			{
				movementDirection.y -= mouseY;
			}
			else if (mouseState & SDL_BUTTON_RMASK)
			{
				totalYaw += mouseX * cameraRotationSpeed * deltaTime;
				totalPitch -= mouseY * cameraRotationSpeed * deltaTime;
			}
			else if (mouseState & SDL_BUTTON_LMASK)
			{
				totalYaw += mouseX * cameraRotationSpeed * deltaTime;
				movementDirection.z -= mouseY;
			}

			if (movementDirection != glm::vec3::Zero)
			{
				movementDirection = (movementDirection.x * invViewMatrix.GetAxisX()) + (movementDirection.y * invViewMatrix.GetAxisY()) + (movementDirection.z * invViewMatrix.GetAxisZ());

				origin += movementDirection.Normalized() * cameraMovementSpeed * deltaTime;
			}

			CalculateViewMatrix();
			CalculateProjectionMatrix();
		}
	};
}*/
