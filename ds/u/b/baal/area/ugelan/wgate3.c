#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"幽遮蘭城─城西大門─內城"NOR);
        set("long", @LONG
再向內走，就可以進入了幽遮蘭城城內了，此地設有一
個檢察哨，佈有重兵駐守，專門檢查進城做生意的小販、進
貨的馬車、可疑的人士等，從檢查的隊伍大排長龍的情形可
以發現檢查的程序相當的繁雜，不過看來旅客並沒有在檢查
之列，你可以不受阻礙的進入城內。
LONG
        );
        set("exits", ([ 
                        "west": __DIR__"wgate2",
            "east": __DIR__"w1st1",
            ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}

