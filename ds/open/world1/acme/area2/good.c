#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","巨石堆");
        set("long", YEL"你身處在巨石堆之間，這是一道錯綜複雜，奇奧無比的陣勢。\n"NOR);
        set("outdoors","land");
        set("exits", ([ 
            "east" : __DIR__"good.c",
            "north" : __DIR__"good.c",
            "west" : __DIR__"good.c",
            "south" : __DIR__"good.c",
            "northeast" : __DIR__"good.c",
            "northwest" : __DIR__"good.c",
            "southeast" : __DIR__"good.c",
            "southwest" : __DIR__"good.c",
        ]));
set("objects",([
    __DIR__"obj/sign" : 1,
]));
        setup();
}
void init()
{ 
  int i,x;
  object me;
  me=this_player();      
  add_action("do_stone","stone");
  if(me->environment() ) return 0;

       i=me->query_temp("STONE/total");
       x=random(5)+1;
       me->set_temp("STONE/total",i+x);

        if(me->query_temp("STONE/total")>25)
        {
         message_vision(HIR"\n$N因走錯了路徑，竟回到了最外圍的竹林。\n\n"NOR,me);
         me->delete_temp("STONE");
         me->start_busy(1);
         me->move(__DIR__"start");
        }
        if(me->query_temp("STONE/total")==25)
        {
         message_vision(HIC"\n$N成功\的破解了這道巨石陣。\n\n"NOR,me);
         me->delete_temp("STONE");
         me->start_busy(1);
         me->move(__DIR__"p9");
        }

}

void do_stone(string arg)
{
       int stone;
       object me;
       me=this_player();
       if( arg = "")
       stone=me->query_temp("STONE/total");
       notify_fail("你目前破石陣數為："+ stone +"。\n");
}
