using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Lisa;

namespace Sandbox
{
    public class Camera : Entity
    {
        public Entity OtherEntity;

        void OnUpdate(float ts)
        {
            float speed = 3.0f;
            Vector3 velocity = Vector3.Zero;

            if (Input.IsKeyDown(KeyCode.W))
                velocity.Y = 1.0f;
            else if (Input.IsKeyDown(KeyCode.S))
                velocity.Y = -1.0f;

            if (Input.IsKeyDown(KeyCode.A))
                velocity.X = -1.0f;
            else if (Input.IsKeyDown(KeyCode.D))
                velocity.X = 1.0f;

            if (Input.IsKeyDown(KeyCode.Q))
                velocity.Z -= 1.2f;
            else if (Input.IsKeyDown(KeyCode.E))
                velocity.Z += 1.2f;

            velocity *= speed;

            Vector3 translation = Translation;
            translation += velocity * ts;
            Translation = translation;
        }

    }
}
