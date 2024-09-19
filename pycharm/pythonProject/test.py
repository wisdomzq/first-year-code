import serial  # serial模块，读写串口数据
from robotpi._Cmd import UPComBotCommand
import time


class serOp1():
    """设置并打开串口："""
    # serial.SeriaL（）方法创速串列实例；ser = serial.serial（），用serial.seriaL（）方法
    ser = serial.Serial(
        port="/dev/ttyusBe",  # 串口号
        baudrate=115200,  # 波特率和下位机一致，baudrate：波特率，str格式bytesize=8， #比特尺寸8
        parity='E',  # parity：校验位，str格式。只需要第一个字母，“N'无校验，“0”奇者stopbits=1，#停止位1位
        timeout=2)  # 超时 #
    isOpen = True  # 没置isopen = True

    def __init__(self):  # 方法_init_（）是一个特联方法，每当你根据类创建新实例时，Pyl
        self.isOpen = True  # 当前串口是否已经打开，isOpen（）方法来判断串口是否打开，如：

    def open(self):
        self.ser.open()  # ser.open（），打开端口；
        if (serOp1.ser.isOpen):  # 当前审口是否已经打开
            self.isOpen = True  # 当前串口已經打开，self.isOpen = True
            print("open")
        else:
            self.isOpen = False  ##当前串口未打开，self.isOpen = False

    def serial_listen_check(self):
        len_limit = 0
        # Len接收到的戴据长度，调試过程中，运行时候可以没有；
        while serOp1.ser.inwaiting() > 0:  # inWaiting（）：返回接收銀存中的字节数
            h = serOp1.ser.read()  # 从端口读子节，read（）函戴可用于从設备接收到数据中
        hey = int.from_bytes(h, byteorder='big', signed=False)  # 字节序byte o
        if hey == 245:  # 兴文件是245；
            data = [hey]  # data=[245]
            while serOp1.ser.inWaiting() > 0:
                k = serOp1.ser.read()  # 从端口读字节，read（）函数可用于从设备接收
                data.append(int.from_bytes(k, byteorder='big', signed=False))

    def battery_information(self):

    def Generated(self, device, cmd, len, data):
        buffer = [0] * (len + 6)
        buffer[0] = 0xF5
        buffer[1] = 0x5F
        buffer[2] = device & 0xFF
        check = buffer[2]
        buffer[3] = cmd & 0xFF
        check = check + buffer[3]
        buffer[4] = len & 0xFF
        check = check + buffer[4]
        for i in range(len):
            buffer[5 + i] = data[i]
            check = check + buffer[5 + i]
        buffer[len + 5] = (~check) & 0xFF
        return buffer, len + 6


if __name__ == '__main__':
    com = UPComBotCommand()
    ser = serOp1()
    while True:
        ser.battery_information()  # 电池信息，先请求
        recv_data = ser.serial_listen_check()  # 调用函数
        if recv_data:
            # for i in recu_data:
            # print("data received:", i, type(i))
            SOC = recv_data[6] * 256 + recv_data[5]
            V = recv_data[8] * 256 + recv_data[7]
            I = recv_data[10] * 256 + recv_data[9]
            print('SOC:', SOC)
            print('Voltage/v: ', V / 1000)
            print('Current/mA:', I)