inherit ROOM;
void create()
{
        set("short", "山間空地");
        set("long",@LONG
這裡是山中的空地，四周看來十分空曠，可是卻有十分多的小土堆，
看來該是亂葬的墳地，往空地東邊望去，遠遠的似乎有一個遺跡，不知內
裡是做什麼的，東北邊雲氣繚繞，看來是個小丘。
LONG
        );
  
set("exits", ([
  "east" : __DIR__"zk9",
  "northeast" : __DIR__"zk5",
  "southeast" : __DIR__"zk3",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

