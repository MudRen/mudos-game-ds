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
"east" : __DIR__"temple06",
"west" : __DIR__"temple07",
"north" : __DIR__"temple04",
  "south" : __DIR__"temple02",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
