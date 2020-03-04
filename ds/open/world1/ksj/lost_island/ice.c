#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name(HIC"巨冰"NOR, ({"ice"}) );
        set("long",@LONG
一個巨大的冰塊，像座小山似的，裡面有一個看不清的巨大物體
，冰塊以極為緩慢的速度融化，或許可以灑(labber)點東西融化它。
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
        add_action("do_labber","labber");
 
}

int do_labber(string str)
{
        object me,b,z,ob;
        me=this_player();
 
        if(!str || str!="blood") return 0;
        if(!objectp(z=present("shell dragon blood",me) ) )
        return notify_fail("你沒有東西可以灑啊 ? \n");

        // 1/13 新增 by ksj
        ob=find_living("_NPC_SWORD_TIGER_");
        if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N將紅色液體潑灑到冰上，融化成一地的血水。\n",me);
            destruct(z);
            return 1;
          }
        }
         
        destruct(z);
        message_vision(
        HIW"\n$N將紅色液體潑灑到冰上，冰塊隨即冒出蒸氣急速融化。\n"NOR
        HIC"\n突然巨冰裂開，一個巨大的身影出現在你面前！\n"NOR,me);
        message("world:world1:vision",
        HIR"\n\t從"HIG" 遺世島 "HIR"傳來令百獸都為之驚恐的吼叫聲！！\n\n"NOR
        ,users());
        b=new(__DIR__"npc/sword-tiger" );
        b->move(environment(this_object()));
        destruct(this_object());
        return 1;
}
