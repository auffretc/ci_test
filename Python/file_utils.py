"""Module comparant des fichiers texte."""

def diff(file_first, file_second):
    """Fonction vérifiant si deux fichiers sont différents."""
    result = False
    with open(file_first, , mode="r", encoding="utf-8") as file_first_id :
        with open(file_second, , mode="r", encoding="utf-8") as file_second_id :
            result=file_first_id.read() != file_second_id.read()
    return result
