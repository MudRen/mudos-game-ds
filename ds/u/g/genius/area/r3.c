#include <ansi.h>
inherit ROOM;

void create()
{
set("short","�A��");
        set("long", @LONG
�o�̩M�@�몺�A�a�G�m�S�������ˡA���@�i�C�G�����l�M�T�Ӥ�s
�Ȥl�A��u���㪺���ǲʩ�C
LONG
        );
        set("exits", ([
        "east":__DIR__"al4",
]));
        set("objects", ([
        __DIR__"npc/farmer1" :1,
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

