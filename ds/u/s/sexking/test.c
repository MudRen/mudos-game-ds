#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"伊恩的工作室"NOR);
        set("long", @LONG
這裡就是伊恩的工作室, 這裡冷的不得了, 你不禁慶幸穿了皮裘進
來, 不然這時你可能變成一坐冰雕了, 這間房間中央擺著一張冰雕刻而
成的辦公桌, 辦公桌前的皮椅已經結冰, 在房間的另一角還有一個水池
, 上面漂著一塊塊的浮冰, 更誇張的是, 居然有幾隻企鵝和北極熊, 你
不禁懷疑, 這個工作室的主人是不是精神病院跑出來的...
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"workroom",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);  // 不能recall也可以刪掉
        set("no_kill",1);  // 不會有戰鬥也可以刪掉它
        setup();
}
void init()
{
  object me;
  
  ::init();
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
object robe;
if(!objectp(robe=present("robe",me) ) )
{
        message_vision(HIC"$N一進來這裡..便冷的不停的發抖...。\n"NOR,me);
        me->receive_damage("hp",30); //因為冷所以減hp
        call_out("cold",10,me);
        return;
}
else
{
message_vision(HIG"$N突然發現這裡冷的不得了,但因為穿著皮裘保暖所以並沒有大礙。\n"NOR,me);
return;
}
}
void cold(object me)
{
     if(!me) return;
     message_vision(HIC"$N感到越來越冷...如果不找個可防寒的東西穿起來的話..可能會被冷死的。\n"NOR,me);
     me->receive_damage("hp",30);
     call_out("cold2",7,me);
     return;
}
void cold2(object me)
{
     if(!me) return;
     message_vision(HIC"$N已經無法支撐這種低溫了.再不離開這的話一定會凍死的.。\n"NOR,me);
     me->receive_damage("hp",60);
     call_out("cold3",8,me);
     return;
}
void cold3(object me)
{
     if(!me) return;
     message_vision(HIR"漸漸的你已經結凍成冰了.快失去意識了....。\n"NOR,me);
     me->set_temp("freeze",1);
     call_out("cold4",30,me);
     return;
}
void cold4(object me)
{
     if(!me) return;
     message_vision(HIC"最後$N完全結了冰...閉上了雙眼..永遠沉睡了。\n"NOR,me);
     me->set_temp("temp/death_type",HIC"[結凍了]"NOR);
     me->die();
     return;
}

 

