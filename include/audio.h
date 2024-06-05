#ifndef AUDIO_H
#define AUDIO_H

/* Quantidade de Áudios */
#define NUM_AUDIOS 1
/* Áudios */
#define SHOT 0 /* Índice do Áudio da Espingarda */

// Toca o som
void playSound(int audioID);

// Inicializa o som na memória
void initAudios();

// Libera o som da memória
void freeAudios();

#endif