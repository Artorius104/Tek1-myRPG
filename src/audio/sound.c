/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-julien.de-waele
** File description:
** sound.c
*/

#include "rpg.h"

sfSound *create_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *sbuff = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(sound, sbuff);
    sfSound_setLoop(sound, sfFalse);

    return sound;
}

sfSound **init_sound(void)
{
    sfSound **list = malloc(sizeof(sfSound *) * 13);

    list[0] = create_sound("./image/sound/Absorb2.ogg");
    list[1] = create_sound("./image/sound/blaster_14.ogg");
    list[2] = create_sound("./image/sound/Cold10.ogg");
    list[3] = create_sound("./image/sound/Collapse4.ogg");
    list[4] = create_sound("./image/sound/Damage3.ogg");
    list[5] = create_sound("./image/sound/Decision1.ogg");
    list[6] = create_sound("./image/sound/Equip1.ogg");
    list[7] = create_sound("./image/sound/Item3.ogg");
    list[8] = create_sound("./image/sound/Open1.ogg");
    list[9] = create_sound("./image/sound/Powerup.ogg");
    list[10] = create_sound("./image/sound/Recovery8.ogg");
    list[11] = create_sound("./image/sound/Teleport_DBZ_Sound_Effect.ogg");
    list[12] = create_sound("./image/sound/Scream-02.ogg");

    return list;
}

sound_t *init_audio(void)
{
    sound_t *audio = malloc(sizeof(sound_t));

    audio->music = sfMusic_createFromFile("./image/sound/mainsong.ogg");
    sfMusic_setLoop(audio->music, sfTrue);
    audio->list = init_sound();

    return audio;
}