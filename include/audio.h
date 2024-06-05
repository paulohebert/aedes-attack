#ifndef AUDIO_H
#define AUDIO_H

/* Quantidade de Áudios */
#define NUM_AUDIOS 2
/* Áudios */
#define SHOT 0 /* Índice do Áudio da Espingarda */
#define RAIN 1 /* Índice do Áudio de Fundo com a Chuva */

// Inicializa o som na memória
void initAudios();

// Aumenta o Volume de todos os áudios
void upVolume();

// Diminui o Volume de todos os áudios
void downVolume();

// Libera o som da memória
void freeAudios();

// Toca o som
void playSound(int audioID);

// Desabilita o som em loop
void stopSoundLoop(int audioID);

#endif