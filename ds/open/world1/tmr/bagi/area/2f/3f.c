// Room: /open/world1/tmr/bagi/area/2f/3f.c
#include <room.h>
inherit DOOR;

inherit ROOM;

void create()
{
        set("short", "�۫�");
        set("long", @LONG
�A���B�b�@���۫Ǥ��A�|�g��������O���M�Z���奴������A�Ǩ�
�٦��C�B�K��w�������H���A���W����סB��A���w�g�ꪺ����A���G�O
�b�ƤQ�~�e�o�ͪ��ơC���M�O�b�a�W���۫Ǥ��A���٬O�D�`������C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "east":__DIR__"3f-1",
          "up" : __DIR__"map_17_10",

        ]));
        set("current_light", 1);
        set("light",1);
        setup();
        create_door("up","�۪�","down",DOOR_LOCKED,"bagi_key");
}

