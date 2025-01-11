"""Module comparant des fichiers texte."""

def diff(file_first, file_second):
    """Fonction vérifiant si deux fichiers sont différents."""
    result = False
    with open(file_first, "r") as file_first_id :
        with open(file_second, "r") as file_second_id :
            result=file_first_id.read() != file_second_id.read()
    return result

