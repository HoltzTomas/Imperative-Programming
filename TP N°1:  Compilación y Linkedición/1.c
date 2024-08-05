int
main(void)
{
 		/* Esto es un primer comentario
 		*/
 	 	\* Que buen comentario! *\ 
 	/* Es valido /* o no */  este comentario?  */
 	/      *  Esto es un ultimo comentario */


return 0
}


//Errores

//1.c:6:5: error: expected expression
//            \* Que buen comentario! *\

// 1.c:6:31: warning: backslash and newline separated by space [-Wbackslash-newline-escape]
//                 \* Que buen comentario! *\ 

// 1.c:7:16: warning: '/*' within block comment [-Wcomment]
//         /* Es valido /* o no */  este comentario?  */