// gebi5.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","���j���");
       set("long", @LONG
�o�O��쪺�j����A�n���X�o�̨ëD���ơC�����B�Фg�F�ɾQ�ѻ\
�a��j�ӡA�ݨӭn�_���ɤF�C
LONG);
        set("exits", ([
                "east" : __DIR__"gebi4",
                "southwest" : __DIR__"road1",
        ]));
        set("outdoors", "land");
        setup();
}

