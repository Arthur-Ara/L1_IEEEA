// Liste des fonctions utiles vu en cours d'Algo 1

int taille = sizeof(); // Peut être aussi mit en long int ou autre
size_t taille = sizeof();
// Permet de retourner la taille d'un tableau en OCTET. 

const char* = strstr("CHAINE1", "ELEMENT CHERCHE");
// Permet de trouve run morceau de chaîne de carractère dans une châine de caractère

int main ( int argc, char *argv[] ) {}
// Ici argc représente la taille de argv[]
// Et argv[] est un tableau avec tout les élements entré à l'exécution de la commande du prog y compris le ./

errno = 0;
// Errno change de valeur si une erreur se passe dans un strtol par exemple.

long int value = strtol( ELEMENT, &end, 10);
// Convertir une chaîne de carractère en long int.
