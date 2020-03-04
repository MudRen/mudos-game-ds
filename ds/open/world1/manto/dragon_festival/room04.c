inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"汨羅江邊"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    一路上，深黛色的奇峰下，碧綠的鳳尾竹中，不時露出幾處黑瓦白
牆。那片片彷彿記載著厚重歷史的黑瓦，或清晰或朦朧，既深刻凝重又簡
單明瞭，讓人不得不嫉妒居住其間的主人。沿途的村民早已習慣了絡繹不
絕的旅客，悠然地坐在家門口看著風塵僕僕的旅人。

LONG
        );
    set("exits",([
 "north" : __DIR__"room03",
 "south" : __DIR__"room05",
]));

        set("objects", ([ 
  __DIR__"mob06" : 2,
]));

        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}
