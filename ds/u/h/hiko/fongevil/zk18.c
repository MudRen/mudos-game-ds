inherit ROOM;
void create()
{
        set("short", "山間空地");
        set("long",@LONG
這是一條山間小徑，東面一面垂直的山壁，看來十分的高聳入雲，可以
想見無法攀爬其上，而小徑旁的樹林枝葉茂密，雖然林外陽光刺眼，卻完全
無法滲透其內，東北方一片黑暗，似乎是一片山林。
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk17",
  "southwest" : __DIR__"zk19",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 


