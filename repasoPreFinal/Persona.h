#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct PersonaEstructura * Persona;

Persona cargarPersona(int dni, char nombre[20], char apellido[20]);
Persona cargarPersonaTeclado();

char* getNombre(Persona p);
void setNombre(Persona p, char nombreNew[20]);
int getDni(Persona p);
void setDni(Persona p, int dni);
char* getApellido(Persona p);
void setApellido(Persona p, char apellidoNew[20]);
void mostrarPersona(Persona p);
void mostrarPersonaGenerico(void* dato);
int compararPersona(void* dato, void* dato2);

#endif // PERSONA_H_INCLUDED
