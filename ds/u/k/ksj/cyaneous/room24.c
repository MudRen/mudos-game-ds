inherit ROOM;

void create()
{
        set("short", "巴那那酒吧");
        set("long", @LONG
這間酒吧中擺放著一些植物，有的上面還結著果子，這家酒吧的主人是南洋
    來的旅客，酒吧中提供特釀的南洋水果酒，有其獨特的風味。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room23",
  "south" : __DIR__"room27",
  "northwest" : __DIR__"room20",
  //"east" : __DIR__"room24",
]));  
        set("objects",([
__DIR__"npc/room24-boss":1,
]));
        set("light",1);

        setup();
        //replace_program(ROOM);
}

