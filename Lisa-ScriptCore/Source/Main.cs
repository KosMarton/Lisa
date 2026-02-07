using System;
using System.Runtime.CompilerServices;

namespace Lisa
{

    public struct Vector3
    {
        public float X, Y, Z;

        public Vector3(float x, float y, float z)
        {
            X = x;
            Y = y;
            Z = z;
        }
    }

    public class Main
    {
        public float FloatVar { get; set; }

        public Main()
        {
            Console.WriteLine("Main constructor!");
            Log("Lisa", 8058);

            Vector3 pos = new Vector3(5, 2.5f, 1);
            Vector3 result = Log(pos);
            Console.WriteLine($"{result.X}, {result.Y}, {result.Z}");
            Console.WriteLine("{0}", NativeLog_VectorDot(ref pos));
        }

        public void PrintMessage()
        {
            Console.WriteLine("Hello World from C#!");
        }

        public void PrintInt(int value)
        {
            Console.WriteLine($"C# says: {value}");
        }

        public void PrintInts(int value1, int value2)
        {
            Console.WriteLine($"C# says: {value1} and {value2}");
        }

        public void PrintCustomMessage(string message)
        {
            Console.WriteLine($"C# says: {message}");
        }

        private void Log(string text, int parameter)
        {
            NativeLog(text, parameter);
        }

        private Vector3 Log(Vector3 parameter)
        {
            NativeLog_Vector(ref parameter, out Vector3 result);
            return result;
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static void NativeLog(string text, int parameter);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static void NativeLog_Vector(ref Vector3 parameter, out Vector3 result);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static float NativeLog_VectorDot(ref Vector3 parameter);
    }

}