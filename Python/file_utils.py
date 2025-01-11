"""Module comparant des fichiers texte."""

def diff(file_first, file_second):
    """Fonction vérifiant si deux fichiers sont différents."""
    result = False
    with open(file_first, "r", encoding="utf-8") as file_first_id :
        result=file_first_id.read()!=""
    return result
