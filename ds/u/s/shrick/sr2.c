// sr2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"��s�ǡ��G��"NOR);
        set("long",@LONG
�o�O�E��s�ǡ��G���E�w�R�@�I,���n�n��L�̤F��!
�L�̥��b��s����"�U��(TRASH)"�ܦ����Ϊ��F��E
LONG
        );
        set("exits", ([
                "east" : __DIR__"sr1",
                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}

