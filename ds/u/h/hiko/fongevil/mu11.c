inherit MOBROOM;
void create()
{
        set("short", "山腰");
        set("long",@LONG
這裡是約接近山腰的地方，道路到此竟然有些修茸過，也許附近有
人居住於此，道路雜草較為低矮，，看來該是有人清理過的痕跡，使你
更加確信這裡有人跡，東北邊有一條路往半山腰，西南則是往山下。
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"mu12",
  "southwest" : __DIR__"mu4",
]));
        set("chance",50);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"animal/bee",
}) );
set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 






