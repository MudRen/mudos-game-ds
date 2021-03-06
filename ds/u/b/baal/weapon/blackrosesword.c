#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(MAG"黑玫瑰之劍"+NOR, ({ "black rose sword","sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "黑玫瑰之劍，受詛咒的索蘭尼亞騎士─索思的配劍。\n");
                set("material", "blacksteel");
                set("value",20000);
        }
        init_sword(40);
        set("wield_msg",RED"$N將$n"RED"執在手中，放聲大喊：「Est Sularus Oth Mithas！！」。\n"NOR);

set("unwield_msg",RED"$N將手中的$n"RED"收回劍鞘，向在天邊閃耀的黑暗之后的星座行最敬禮。\n"NOR);

        setup();
}


void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 10 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
         HIW "\n$N放聲大喊：「Est Sularus Oth Mithas！！」無數道怨靈被釋放，衝向敵人！！\n" NOR
        ,me,target);

        damage += me->query_skill("sword")+me->query_str()+random(30);
        def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIR "$N躲避不及，只覺全身生命力源源流洩而出！！\n"NOR,target);
    target->receive_damage("hp",1500);
        }
        else
        {
      message_vision(HIG "$N口中喃喃唸誦著帕拉丁的禱文，無視於邪惡的力量。\n"NOR,target);
        }

        }
        return;
}
