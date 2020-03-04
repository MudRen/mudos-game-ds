#include <ansi.h>
inherit ITEM;
void dest_scroll(object me);

void create()
{
        set_name(HIW"傳送卷軸─暗斯德塔"NOR,({"transpot scroll","scroll"}) );
        set("long","
從小販那買來的傳送卷軸，是暗斯德塔的法師為了方便各地
的人民行走於世界各地所施法製成的，只要讀上面的咒文便可以
傳送至世界各地，不過價值不斐，這個卷軸是傳送到暗斯德塔的
卷軸(use scroll).
\n"
        );
        set("value", 25000);
        setup();                
}
void init()
{
        add_action("typeuse","use");
}
     int typeuse(string arg)
{
        object me;
        me=this_player();
        if( arg != "卷軸" && arg != "transpot scroll" && arg != "scroll" )
         return 0;
  if(me->is_ghost()) return notify_fail("魔法卷軸造成的魔法力場會讓你魂飛魄散的！！\n");
   if(me->query_temp("killer"))
          return notify_fail("你殺了人，魔法師們設下的結界讓你看不懂卷軸！！\n");
   if(me->query_temp("invader"))
     return notify_fail("你攻擊了玩家，魔法師們設下的結界讓你看不懂卷軸！！\n");

  if(me->is_busy() || me->is_fighting())
  {
    write("你正在忙，沒空作其他事情。\n");
    return 1;
  }

        else {
        message_vision( HIG "$N看著卷軸上的文字，緩緩唸道：「ㄚ撒呀卡那它勒得...」卷軸上的文字一個一個的化成輕煙，消失了...\n\n" NOR ,me);
        message_vision( RED "一團黑色的薄霧罩住了$N，過了一會，$N與薄霧一同消散在空氣中...\n\n" NOR ,me);
        me->move("/u/b/baal/area/dst/dst1");
        return 1;
             }
        call_out("dest_scroll",me);
        return 1;

}

void dest_scroll(object me)
{
        if(!me) return;
        if(!this_object() ) return;
  message_vision("卷軸在$N手中慢慢變脆、變舊，最後化成灰，消失了...\n",me);
  destruct(this_object());
}


