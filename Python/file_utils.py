import tempfile


def diff(file_first, file_second):
    file_first_id = open(file_first, "r")
    file_second_id = open(file_second, "r")

    return file_first_id.read() != file_second_id.read()
"""
if __name__ == "__main__":
    file_first = tempfile.mktemp()
    file_second = tempfile.mktemp()
    file_not_found = tempfile.mktemp()


    with open(file_first, "w+") as file_first_id:
        file_first_id.write("")

    with open(file_second, "w+") as file_second_id:
        file_second_id.write("Hello World!\n")
    
    print("result = %d, result = %d" % (diff(file_first, file_first), diff(file_first, file_second)))
"""
