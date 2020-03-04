#include <ansi.h>
inherit ROOM;

void show(object me) ;
void create()
{
        set("short", HIR"銅屏門前"NOR);
        set("long", @LONG
你來到一扇巨大的銅門前，銅門的正中央刻有一惡魔像，但是卻
不完整，因為魔像的右眼不見了，大小跟天魔的惡魔之眼差不多，且
是極為吻合，讓人產生無限聯想，如果把其放到裡面，不知道會產生
什麼狀況？ 
LONG
        );

        set("item_desc",([
    "眼洞":"魔像的右眼，因缺眼球，所以呈現出一個深洞，似乎可以放什麼進去？(put someone in hole)\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "up" : __DIR__"room5",
        ]));
        set("world", "past");
        set("
no_clean_up", 0);  
    setup();
}
void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
        object me,eye;
        me=this_player();
 
      if(!arg || arg!="eye in hole") return notify_fail("你要放什麼?\n");
      if(!objectp(eye=present("evil eye",me) ) ) 
                return notify_fail("你沒有這項東西啊 ? \n"); 
     destruct(object evil_eye);
     message_vision(HIW"$N"HIR"膽戰心驚的將惡魔之眼放進眼洞裡\n\n"NOR,me);  
     message_vision(HIR"一陣咆嘯聲響從惡魔像傳出，惡魔像竟活了過來，並化作一道紅光直達天際！\n\n"NOR,me);     message("world:world1:vision",HIW"\t\t一道"HIR"紅光"HIW"從地下墓穴的深處噴出！！\n"  
                                   HIG"\n\t\t\t    『"HIR"修羅門"HIG"』\n"  
                                   HIW"\n\t\t\t    開啟•••••\n"NOR,users());  
     message_vision(HIM"你被吸入了門內\n"NOR,me);     
        me->start_busy(5); 
        call_out("show",3,me);
        return 1;        
} 
void show(object me)
{ 
        tell_object(me,"你的身形漸漸凝聚。\n"); 
        me->move(__DIR__"start_shiro");  
        tell_room(environment(me),me->query("name")+"突然出現在你的面前。\n",me);
        return;
}

