inherit ROOM;

void create()
{
        set("short", "海岸");
        set("long", @LONG
這裡是港口的海岸邊，腳底下是用石塊鋪成的道路，岸邊放有許多
    大岩石用來抵擋海浪的侵襲，天空中不時有海鷗盤旋。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room7",
  "southwest" : __DIR__"room17",
  "northeast" : __DIR__"room15",
  //"east" : __DIR__"room38",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}

