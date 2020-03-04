#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("深洞", ({"hole"}) );
        set("long",@LONG
一個寬約三尺，深不見底的地洞，不時有強烈的氣流進出地洞，像是
在呼吸似的，或許可以丟東西下去看看有什麼反應(throw 某物)。
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "個");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
        add_action("do_throw","throw");
}

int do_throw(string str)
{
        object me,b,z,ob;
        me=this_player();
 
        if(!str || str!="heart") return 0;
        if(!objectp(z=present("silver dragon heart",me) ) )
        return notify_fail("你沒有東西可以丟啊 ? \n");
       
        // 1/13 新增 by ksj
        ob=find_living("_NPC_BLOOD_EYE_DRAGON_");
        if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N將一件物事丟入深洞中，但沒有任何動靜。\n",me);
            destruct(z);
            return 1;
          }
        }
  
        destruct(z);
        message_vision(
        HIW"\n$N將一件物事丟入深洞中，隨後洞中冒出絲絲白煙。\n"NOR
        HIR"\n突然地面崩裂翻起，一個巨大的身影從地底冒了出來！\n"NOR,me);
        message("world:world1:vision",
        HIR"\n\t"HIG" 遺世島 "HIR"上突然一陣山搖地動，上古沼地下的惡龍再次甦醒！！\n\n"NOR
        ,users());
        b=new(__DIR__"npc/blood-eye-dragon" );
        b->move(environment(this_object()));
        destruct(this_object());
        return 1;
}
