#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"竹網"NOR, ({ "bamboo net","net" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一枝捕捉(catch)動物用的竹網。\n");
                set("unit", "枝");
                set("value",5);
                set("material","wood");
        }
        setup();
}

void init()
{ 
        add_action("do_catch","catch");
}

int do_catch(string arg)
{
        object me,obj;
        me=this_player();
        if( !arg ) return notify_fail("你想捕捉誰？\n");
   if(me->is_busy() ) return notify_fail("你正忙著。\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("這裡沒有這種東西。\n");
        if( !obj->is_character() || obj->is_corpse() ) return notify_fail("你只能捕捉活的生物。\n");
         if(userp(obj)) return notify_fail("你不能夠捕捉玩家哦。\n");

        message_vision("$N抄起手中的竹網，一把往$n罩去。\n",me,obj);

        if(!obj->query("Merry_Xmas"))
        {
                message_vision(YEL"$n狠狠摑了"+me->query("name")+"("+me->query("id")+")幾個大耳光.\n"NOR,me,obj);
        }
        else {
        if( random(100) > 70 )
        {

message_vision(HIW "火雞隨既化成一道紅光直衝上天！！\n"NOR,me);
                me->add("Merry_Xmas/chicken",1);
        tell_object(me,HIC"因為你剛才捕捉到了一隻動物，覺的心情相當愉快。\n"NOR);
        me->receive_heal("hp",10);
me->receive_heal("mp",10);
        me->receive_heal("ap",10);
        set("long", "這是一枝捕捉(catch)動物用的竹網，在竹網握柄上記載著：\n"
        +me->query("name")+"目前共捕捉了"+me->query("Merry_Xmas/chicken")+"隻動物。",
        );

                destruct(obj);
        }
        else
        {
        message_vision(HIW "火雞察覺$N的舉動，翅膀一振，躲過了竹網。\n"NOR,me);
        me->start_busy(1);
        }
        }
        return 1;

}

