import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    answer = 0
    print(answer)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
