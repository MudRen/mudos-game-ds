// gebi1.c
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
                "west" : __DIR__"gebi3",
                "east" : __DIR__"gebi1",
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
}
