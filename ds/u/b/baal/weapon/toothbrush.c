#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"！！！牙刷！！！"+NOR, ({ "toothbrush","toothbrush" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "牙刷就是牙刷，看三小！？\n");
                set("material", "rubber");
                set("no_sell", 1);
        }
        init_sword(40);
        set("wield_msg",HIW"$N將$n"HIW"執在手中，放聲大喊：「睡覺前一定要刷牙！！」。\n"NOR);

set("unwield_msg",HIW"$N將手中的$n"HIW"收回塑膠袋，放聲大喊：「刷完牙要漱口！！」。\n"NOR);

        setup();
}


void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 10 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
         HIY "\n$N放聲大喊：「小子嘴巴髒，爺爺幫你刷刷牙！！」用力扳開$n的大嘴，就要幫$n刷牙。\n" NOR
        ,me,target);

        damage += me->query_skill("sword")+me->query_str()+random(30);
        def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIG "$N動彈不得，牙齒被狠狠的刷出一道道的刮痕！！\n"NOR,target);
    target->receive_damage("hp",150);
        }
        else
        {
      message_vision(HIC "$N千鈞一髮之際逃了開來，牙齒得以保全。\n"NOR,target);
        }

        }
        return;
}

