#include <ansi.h>
#include <weapon.h>

inherit FIST;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"破獄"HBK"三界爪"NOR,({"break-hell claw","claw"}) );
        set("long","破獄三界爪為雲中子的神兵武器，上頭滿是符咒及圖畫，似乎記載傳說中的地獄景象。\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("wield_msg", HIC "$N握起$n"+HIC"當武器，只見風雷消散，三界敬依。\n" NOR);
        }
                set("value", 16000);
                set("material","gold");
                set("weapon_prop/int", 2);
                set("weapon_prop/str", 1);
                set("weapon_prop/hit", 5);
                set("weapon_prop/wit", 1);
                set("weapon_prop/bio", -1);
                set("volume",2);
                set("limit_int", 40);
                set("limit_level", 30);
                set("replica_ob",__DIR__"tiger-claw.c");

        init_fist(50);
        setup();
}

void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(100) > 30) return;
        // 30%
       tell_object(me, HIM "你腦海中閃過地獄三界中的一副圖錄，你從圖錄中獲得一絲法力！！\n" NOR);
       me->receive_heal("mp",50);
}

