using System;
using System.IO.Ports;
using System.Threading;
class Program {
    static SerialPort _serialPort;
    public static void Main () {
        _serialPort = new SerialPort ();
        _serialPort.PortName = "COM4"; //Set your board COM
        _serialPort.BaudRate = 9600;
        _serialPort.Open ();
        while (true) {
            string a = _serialPort.ReadExisting ();
            Console.WriteLine (a);
            Thread.Sleep (200);
        }
    }
}