# simple_client_pb.py
import socket

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 55555  # The port used by the server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    print(f"Starting Client Python!")
    s.connect((HOST, PORT))
    # s.sendall(b"Hello, world - from client")
    s.sendall(b"Hi friends !<|EOM|>")
    data = s.recv(1024)
    print(f"Received {data}!")
