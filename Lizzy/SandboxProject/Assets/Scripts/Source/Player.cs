using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Lisa;

namespace Sandbox
{
    public class Player : Entity
    {
        private TransformComponent m_Transform;
        private Rigidbody2DComponent m_Rigidbody;

        public float Speed;
        public float Time = 0.0f;

        void OnCreate()
        {
            Console.WriteLine($"Player.OnCreate - {ID}");

            m_Transform = GetComponent<TransformComponent>();
            m_Rigidbody = GetComponent<Rigidbody2DComponent>();
        }

        void OnUpdate(float ts)
        {
            Time += ts;
            // Console.WriteLine($"Player.OnUpdate: {ts}");

            float speed = Speed;
            Vector3 velocity = Vector3.Zero;

            if (Input.IsKeyDown(KeyCode.Up))
                velocity.Y = 1.0f;
            else if (Input.IsKeyDown(KeyCode.Down))
                velocity.Y = -1.0f;

            if (Input.IsKeyDown(KeyCode.Left))
                velocity.X = -1.0f;
            else if (Input.IsKeyDown(KeyCode.Right))
                velocity.X = 1.0f;

            velocity *= speed;

            m_Rigidbody.ApplyLinearImpulse(velocity.XY, true);

            //Vector3 translation = m_Transform.Translation;
            //translation += velocity * ts;
            //m_Transform.Translation = translation;
        }

    }
}

/*
 public float FloatVar;
 public double DoubleVar;
 public bool BoolVar;
 public char UByteVar;
 public short ShortVar;
 public int IntVar;
 public long LongVar;
 public byte ByteVar;
 public ushort UShortVar;
 public uint UIntVar;
 public ulong ULongVar;
 public Vector2 Vector2Var;
 public Vector3 Vector3Var;
 public Vector4 Vector4Var;
 */