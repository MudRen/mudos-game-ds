#include <room.h>
inherit ROOM;
void create()
{
 set("short","��^�j�Y");
 set("long",@LONG
��^�j�Y�|�P���O�M�G����^��, �a�W���\�F�@�Ǥp�֮�,
�A�����i�H�ݨ�X���p�����b�o����Y��. �A�J�ӱ�F�@��,
�e����G�N�O����j�Y�����Y�F, �γ\�A�ӥX�h�ݬ�?
LONG
    );
 set("exits",([
               "north":__DIR__"hall1",
               "south":__DIR__"hall3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
