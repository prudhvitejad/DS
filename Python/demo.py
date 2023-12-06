with open("1.c", "r") as file1:
    with open("2.c", "r") as file2:
        str1 = file1.read()
        str2 = file2.read()

        print(str1,end="\n")
        print("\n\nSecond:\n")
        print(str2,end="\n")
        
        if(str1 == str2):
            print("Both are same")
        else:
            print("Both are different")