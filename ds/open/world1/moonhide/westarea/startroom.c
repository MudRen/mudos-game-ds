#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "神堂");
        set("long", @LONG
這裡是雲端的最尾邊，往下一探，離地萬尺，抬頭一望，浩月千里，
只見這裡的周圍，圍繞著薄薄的雲霧，有種神聖不可侵犯的感覺。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

