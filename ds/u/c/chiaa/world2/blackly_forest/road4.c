//u/c/chiaa/world2/blackly_forest/road4.c

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
    "east"        : __DIR__"path2",       //�p�|2
    "west"        : __DIR__"road2",       //�L���p��2
    "south"       : __DIR__"road5",       //�����p��5
   ]));
       
            setup();
replace_program(ROOM);
}
