//u/c/chiaa/world2/blackly_forest/road3.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�L���p��");
        set("long", @LONG
�A�����b�L�����@���p��.�դ����ɥiť��@���λﳾ�s,
�O���@�f�M�դ��N,�L����찪�q�s�K,���ر�t���˪��Pı!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */

    "north"      : __DIR__"road2",     //�L���p��2
    "east"       : __DIR__"road5",     //�����p��5
]));
       
            setup();
replace_program(ROOM);
}


