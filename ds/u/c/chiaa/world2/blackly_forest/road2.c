//u/c/chiaa/world2/blackly_forest/road2.c

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
        set("exits", ([ /* sizeof() == 3 */
    "south"  : __DIR__"road3",                //�L���p��3
    "east"   : __DIR__"road4",                //�L���p��4
    "west"   : __DIR__"forest_entranceway",   //�˪L�J�f�B 
]));
       
            setup();
replace_program(ROOM);
}
