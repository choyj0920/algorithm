# baek5532 방학 숙제
import math
def main():
    l=int(input())
    a=int(input())
    b=int(input())
    c=int(input())
    d=int(input())

    print(l-max(math.ceil(a/c),math.ceil(b/d)))

if __name__ == '__main__':
    main()
    