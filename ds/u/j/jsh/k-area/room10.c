inherit ROOM;

void create()
{
        set("short", "海案");
        set("long", @LONG   
這裡是港口的海岸邊，腳底下是用石塊鋪成的道路，岸邊放有許多
    大岩石用來抵擋海浪的侵襲，岩石上有幾隻小螃蟹爬來爬去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room21",
  "west" : __DIR__"room2",
  "northwest" : __DIR__"room9",
  "southeast" : __DIR__"room11",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}

