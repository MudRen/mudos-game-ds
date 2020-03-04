inherit ROOM;
void create()
{
        set("short", "泊浪村南側");        
        set("long",@LONG
這裡是泊浪村街道，往北邊一直望過去可以隱約見到大海，那裡也
泊浪村的活力以及賴以維生的地方，不過事實上在海上求生存是一件很
難的事，所以泊浪村也是少數幾個以海維生的村子，最近似乎有著影響
村子安寧的事發生，令村內人們十分不安。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po4",
  "south" : __DIR__"po2",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



