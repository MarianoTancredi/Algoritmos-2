#include "util.h"
#include "lista.h"
#include <string.h>

size_t vtrlen(void* ptr){
    if(ptr == NULL){
        return 0;}
    else{
        size_t i = 0;
        void** array = ptr;
        while(array[i] != NULL){
            i++;} 
        return i;
        }       
}

void* vtradd(void* ptr, void* item){
    void** array = ptr;
    size_t i = vtrlen(ptr);
    array = realloc(array,(i+2)*sizeof(item));
    if (array == NULL){
        return NULL;} 
    else{
        array[i] = item;
        array[i+1] = NULL;
        return array;}    
    
}

void vtrfree(void* ptr){
    size_t i = 0;
    void** array= ptr;
    for(i = 0; i<vtrlen(ptr);i++){
        free(array[i]);
    }
    free(array);
}

lista_t* split(const char* str, char separador){
    if (str == NULL  || str[0] == 0){
        return NULL;
    }
    
    lista_t* lista = lista_crear();
    if(!lista){
        return NULL;
    }

    char* token = strtok(str, ";");
    lista_insertar(lista,token);
    
    while(token != NULL){
      token = strtok(NULL, ";");
      lista_insertar(lista,token);
    }
    
    return lista;
}


char* fgets_alloc(FILE* archivo){
    size_t tamanio = 512;
    size_t char_leidos = 0;
    char* temp;
    int leidos = 0;
    int bytes = 512;
    char* linea = malloc(tamanio);
    if(linea == NULL){
        return NULL;
    }
    
    while(fgets(linea + leidos, bytes - leidos,archivo)){
        size_t posicion = strlen(linea + char_leidos);
        if(posicion > 0 && linea[char_leidos+posicion-1] == '\n'){
            linea[char_leidos+posicion] = 0;
            return linea;
        }
        else{
            temp = realloc(linea,tamanio*2);
            if(temp == NULL){
                free(temp);
                return NULL;
            }
            linea = temp;
            tamanio *=2;
            bytes *= 2;
        }
        char_leidos+=posicion;
        leidos += (int) posicion;
    }
    if(char_leidos == 0){
        free(linea);
        return NULL;
    }
    return linea;
}
void fclosen(FILE* archivo){
    if(archivo != NULL){
        fclose(archivo);
    }
}
