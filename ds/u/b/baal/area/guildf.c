#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天鷹聖廊"NOR);
 set("long",@LONG
看來這條天鷹聖廊已經到盡頭了, 你不禁鬆了一口氣, 走廊上每一隻老
鷹在你一進入他們的視線範圍時便緊緊瞪著你不放, 使這條長廊變的更不易
過了, 你擦了擦額頭上斗大的汗珠, 長吁了一口氣, 趕緊往前走去...
LONG
    );
 set("exits",([ "south":__DIR__"guilde",
                "north":__DIR__"center4",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
