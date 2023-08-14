#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
# include<readline/readline.h>
# include<readline/history.h>
#include <unistd.h>

/*
	SIGTSTP funciona con CTRL + Z (Lo printea pero mete un salto de linea) pero tambien con CTRL + D
	SIGINT funciona ocn CTRL + C (pero lo printea) y con CTRL + D (no lo printea)
*/

int	i = 0;
void rl_replace_line(const char *text, int clear_undo);

void	sighandle(int sigint)
{
	sigint = 0;
	write(2, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", sigint);
    rl_redisplay();
}

int	main(void)
{
	rl_catch_signals = 0; //esta variable esta definida en la libreria readline. Esta inicializada a 1 normalmente.
							//Si su valor es 1 maneja las señales la propia librería, sino las manejas tu.
	char	*s;
	int eof = 1;
	struct sigaction sa;
	sa.sa_handler = &sighandle; //esta linea y las 2 siguiente estan copiadas de un video de codevault
	sa.sa_flags = SA_RESTART; //Basicamente configura una estructura para que gestione la señal
	signal(SIGINT, sighandle); //En este caso la señal que gestiono es CTRL + C. 
	//sigaction(SIGINT, &sa, NULL); // en este caso la señal que gestiona el Ctrl + z y hace lo que haría la terminal en caso de pulsar Ctrl + C.
	while(eof) //Este bucle es algo arbitrario. Le he puesto 5 para que cuando acabe pueda comprobar que libera correctamente los recursos del historial y que no hay ningun leak.
	{
		s = readline(">>>"); //CTRL + D devuelve null.
		if (!s) //Si input no es nulo y el primer caracter no es nulo (input vacio) y el primer caracter no es un espacio (por algun motivo mi terminal de bash no guarda eso pero lo podemos cambiar) no guarda el comando
		{	
			//write(2, "\n", 1);
    		//rl_on_new_line();
    		rl_replace_line("", );
			rl_redisplay();
			eof = 0;
		}
		if (s && *s)
		{
			printf("%s\n", s);
			add_history(s);
			free(s);
		}

		i++;
	}
	rl_clear_history(); //El historial se limpia de manera automatica. Supongo que esto deberiamos utilizarlo cuando se nos meta exit en la terminal, aunque igual deberiamos utilizar solo exit con execve.
						//Lo decidiremos más adelante porque el subject dice que si se justifican se permiten los leaks que causa el readline.
	return (0);
}

