inherit ROOM;

void create()
{
        set("short", "破手套酒吧");
        set("long", @LONG
這裡是間熱鬧的酒吧，雖然裝潢很破舊，但是喜歡這裡的酒的客人
    還是會來到這邊來光顧。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room7",
  "southeast" : __DIR__"room22",
  //"northeast" : __DIR__"room16",
  "east" : __DIR__"room19",
])); 
        set("objects",([
  __DIR__"npc/room18-boss":1,
]));
        set("light",1);
        setup();
        //replace_program(ROOM);
}

