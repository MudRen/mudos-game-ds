#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", RED"幽遮蘭城城西守備隊駐所"NOR);
        set("long", @LONG
這是一個迴廊，有著上去的樓梯，旁邊有個守衛休息的
圓桌跟椅子。
LONG
        );
        set("exits", ([ 
                        "west": __DIR__"ugw2",
                                                "up": __DIR__"ugw5",
            ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

