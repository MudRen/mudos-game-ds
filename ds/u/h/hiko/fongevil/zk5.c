inherit ROOM;
void create()
{
        set("short","山間小丘");
        set("long",@LONG
你來到了小丘上，這裡視野十分清晰，卻依然無法看清整個山崗，似
有一層陰暗的物質遮掩你的視線，使你感到無法了解，東北邊看來是個岩
層的小隙，而西南則是個空地。
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk6",
  "southwest" : __DIR__"zk4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

