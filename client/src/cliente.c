#include "client.h"
#include "utils.h"
#include <readline/readline.h>


int main(int argc, char ** argv)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	log_info (logger,"hola! soy un log");

	

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	valor = config_get_string_value(config, "VALOR");

	log_info(logger, "La IP es %s el puerto es %s y el valor es %s\n", ip, puerto, valor);

	/* ---------------- LEER DE CONSOLA ---------------- */

	//leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(valor, conexion);
	enviar_mensaje("estoy viendo si no rompo", conexion);
	

		char* mensaje;
		mensaje = argv;
		enviar_mensaje(mensaje, conexion);

	
	
	// Armamos y enviamos el paquete
	//paquete(conexion);
	log_info(logger, "estoy por terminar programa");
	terminar_programa(conexion, logger, config);
	log_info("termine",logger);


	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}
void terminar_programa(int, t_log* logger, t_config* config){
	if (logger=!NULL){
		log_destroy (logger);
		
		return 0;
	}
	if (config=!NULL){
		config_destroy(config);
		return 0;
	}
}

t_log* iniciar_logger(){
	t_log* logger;
	logger = log_create("cliente.log", "CLIENTE",1,LOG_LEVEL_INFO);
	return logger;
}

t_config* iniciar_config(){
	t_config* config;
	config = config_create("./cfg/cliente.config");
	return config;
}
//void paquete(int){}