// sr1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"��s�ǡ��@��"NOR);
        set("long",@LONG
�o�O�E��s�ǡ��@���E�w�R�@�I,���n�n��L�̤F��!
LONG
        );
        set("exits", ([
                "east" : __DIR__"bigdoor",
                "west" : __DIR__"sr2",
                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
