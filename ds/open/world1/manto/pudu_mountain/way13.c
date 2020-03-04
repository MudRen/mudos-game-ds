inherit ROOM;

void create()
{
       set("short", "小徑");
        set("long", @LONG
望著隨風輕擺地青青竹林，竹林掩映之處，隱隱約約出現朱瓦紅牆，
一座寺廟坐落其中。令人不由心中一清，頗生古樸清幽之情，實在是個好
所在。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"temple01",
  "east" : __DIR__"way12",
]));
        set("objects", ([ 
         __DIR__"npc/scholar" : 1,
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
