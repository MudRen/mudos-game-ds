#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", HIC"�j��" HIB"�g�c�}"NOR);
        set( "long", @LONG
 �o�̬O�j�Ӭ��F����ĤH��i�@�B���I�����ӡA�үS�O�]�p���g�c�}
 �A�Ө�o�̡A�u�໡�n���a�B��F�C
 �|�g�������P���A�P��ܵL�U�C
LONG
);
        set("hide_exits", ([ /* sizeof() == 7 */
                  "east" : __DIR__"room5",
                  "west" : __DIR__"room5",
                  "north" : __DIR__"room5",
                  "south" : __DIR__"room5",
                  "northeast" : __DIR__"room5",
                  "northwest" : __DIR__"room5",
                  "southwest" : __DIR__"room5",
        ]));
        set("objects",([
                   __DIR__"statue" : 1,
                 ]) );
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}

