void setup(){
    int s1 = digitalRead(pino do sensor 1); //setar os pins aos sensores de luz e aos controladroes dos motores (pwm)
    int s2 = digitalRead(pino do sensor 1);
    int m1; //aquela bagaça la do motor
    int m2; 
    int erro, erroa = 0;
    int kp = 4; //constantes para configurar o controlador
    int ki = 2;
    int kd = 1;
    int P, I, D, PID = 0; //inicia a Integral, nao faz pate das constantes
}
void loop(){
    if (s1 == 1 && s2 == 1){ //ambos os sensores estao na linha
        erro = 0;
    }
    elif (s1 == 0 and s2 == 1) { //lado do motor 1 esta fora da linha
        erro = 1;
    }
    elif (s1 == 1 and s2 == 0){ //lado do motor 2 esta fora da linha
        erro = -1;
    }
    elif (s1 == 0 and s2 == 0){ //deu merda e perdemos a linha, o robo retrocede ate encontrar pelo menos um ponto da linha 
        while (s1 == 0 or s2 == 0){
            m1 = -75%;
            m2 = -75%;
        }
    }
    P = kp*erro; //controlador PID, Proporcional define a "força" com que o robo vai virar para corrigir a tragetoria
    I = I + ki*erro; //Integral extrapola pequenos erros ao longo do tempo para serem corrigidos a "perfeiçao"
    D = kd*(erro-erroa); //Derivada diminui a "força" a medida que se aproxima do objetivo esperado, limitado no nosso caso por ntermos apenas dois sensores
    PID = P+I+D;
    erroa = erro; //salva o erro anterior para ser usado em D

    m1 = 250 + PID; //se encontra em porcentagens pois nao sei a potencia do motor
    m2 = 250 - PID;
}