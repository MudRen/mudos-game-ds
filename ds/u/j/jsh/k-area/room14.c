inherit ROOM;

void create()
{
        set("short", "海岸");
        set("long", @LONG
這裡是港口的海岸邊，腳底下是用石塊鋪成的道路，岸邊放有許多
    大岩石用來抵擋海浪的侵襲，往海面看去有幾艘船隻正在行進。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room5",
  "southwest" : __DIR__"room15",
  "north" : __DIR__"room13",
  "east" : __DIR__"room35",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}

