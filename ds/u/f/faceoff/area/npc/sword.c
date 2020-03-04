#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"浮"+NOR+""+CYN+"光"+NOR+""+HIW+"掠"+NOR+""+CYN+"影"+NOR+", ({ "light sword","sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把通體透明的劍, 是邱奕捷的配劍。\n");
                set("material", "blacksteel");
        }
        init_sword(50);
        set("wield_msg",CYN"$N將浮光掠影抽出, 剎時光影閃動, 煞是嚇人。\n"NOR);

        set("unwield_msg",CYN"$N將手中的$n放回劍鞘。\n"NOR);

        setup();
}

void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 50 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
         HIW "\n只見$N手中浮光掠影一閃, 十七道凌厲的劍氣朝敵人射去！！\n" NOR
        ,me,target);

        damage += me->query_skill("sword")+me->query_dex()+random(50);
        def += target->query_skill("dodge")+target->query_skill("combat")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIW "$N閃躲不及，劍氣登時全往身上招呼！！\n" NOR,target);
      target->receive_damage("hp",damage);
        }
        else
        {
      message_vision(YEL "$N將十七道劍氣盡數震開, 毫髮未傷。\n"NOR,target);
        }

        }
        return;
}
