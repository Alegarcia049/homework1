#define word1 "7gH!pL9qWz4vR2xT8yU1oI5nJ6kM3lO7aB0cD4eF5hG6jK7lL8mN9oP0qR1sT2uV3wX4yZ5" //Texto aleatorio de 64 chars
#define word2 "9xY#mK8rTz3wQ1vU2oI4nJ7kL5pO6aC0bD3eF6hG7jK8lM9oN0qP1sR2tU3wX4yZ5" //Texto aleatorio de 64 chars

constexpr bool compare_words(const char * w1, const char * w2);
constexpr bool compare_words(const char * w1, const char * w2){
    if (!w1 || !w2 || *w1 != *w2) return false; //Verifico que w1 y w2 no sean nullptr y si son chars distintos ya seran palabras distintas. Entonces devuelvo false
    return *w1 == '\0' || compare_words(w1+1, w2+1); //Si se alcanza \0 se llego al final de la palabra, se cumple para w2 tambien por logica. Si no llegue al final, llamo recursivamente avanzando al proximo char
}