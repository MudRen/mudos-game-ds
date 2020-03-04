inherit ROOM;
void create()
{
        set("short", "山崗口");
        set("long",@LONG
這裡看起來十分陰森，再往前進便是人稱的亂葬岡了，給人一些害
怕的樣子，並且陰風吹動草葉的嗚嗚聲極像哀鳴，使你心裡毛毛的，這
裡幾乎是無人敢住，而且越往前感覺就越強烈，就連天上的烏鴉鳴叫也
令人不舒服，而眼前出現三條小路，令你不知該往那個方向前進。
LONG
        );
  
set("exits", ([
  "north" : __DIR__"zk1",
  "northwest" : __DIR__"zk2",
  "northeast" : __DIR__"zk19",
  "southdown" : __DIR__"mu10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 
int valid_leave(object me, string dir)
{
       if( dir=="southdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}



