inherit ROOM;

void create()
{
        set("short", "大鬍子酒吧");
        set("long", @LONG
這間酒吧實在有點髒亂，凌散的桌椅上躺臥著一些醉醺醺的酒客，其它
    客人則是粗暴地大口喝酒，整個酒吧鬧哄哄地亂成一團。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room21",
  "south" : __DIR__"room25",
  "northwest" : __DIR__"room18",
  "east" : __DIR__"room23",
]));  
       set("objects",([
__DIR__"npc/room22-boss":1,
]));
        set("light",1);

        setup();
        //replace_program(ROOM);
}

