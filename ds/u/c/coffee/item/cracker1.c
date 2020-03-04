#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"鞭炮"NOR, ({ "cracker" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個紅色的鞭炮，爆炸威力十足。\n");
                set("unit", "個");
                set("value",0);
        }
        setup();
}

void init()
{ 
        add_action("do_bombing","bombing");
}

int do_bombing(string arg)
{
        object me,obj,test;
        test = new("/u/c/coffee/game/newyear/monster-beard");
        me = this_player();

        if( !arg ) return notify_fail("你要炸誰？\n");
        if ((arg!="year monster")&&(arg!="monster")) return notify_fail("鞭炮不要拿來亂炸..= =\n");
        if(me->is_busy() ) return notify_fail("你正在忙，沒空啦。\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("這裡沒有這種東西。\n");

        message_vision("$N將鞭炮點燃，並且快速地丟往$n！\n",me,obj);

        if(!obj->query("monster-beard"))
        {
           message_vision(YEL"$n狠狠踹了"+me->query("name")+"("+me->query("id")+")一腳...\n"NOR,me,obj);
        }
        else 
        {
             if( random(40) > 30 )
             {
                message_vision(HIW"年獸被鞭炮炸到了，不停的吼叫..！\n"NOR,me);
                me->add("monster-beard",1);
                tell_object(me,HIC"鞭炮的爆炸威力讓年獸不禁嚇到，掉了一跟鬚到你的手上。\n"NOR);
                test->move(environment(me));
//              destruct(obj);   //加了這行monster就會不見
             }
             else
            {
                message_vision(HIW "年獸發現了$N想攻擊他，急忙的躲掉鞭炮，並將憤怒的一拳打向$N！！\n"NOR,me);
                me->receive_damage("hp",500,this_object());
                me->start_busy(1);
            }
        }
 return 1;
}

