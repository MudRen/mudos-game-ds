inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG 
這裡是鎮外的道路，也是經商的要道，往來港都的食品、貨物都要經過這條道
    路，道路上明顯地有兩條車痕，兩旁望去則是一片農田。
        [此與東北方的小鎮相連，暫未完工，故不開放]
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"northeast" : __DIR__"room56",
  //"west" : __DIR__"room54",
  //"north" : __DIR__"room34",
  "southwest" : __DIR__"room55",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

