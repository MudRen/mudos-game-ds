#include <ansi.h>
#include <weapon.h>

inherit FIST;
inherit F_UNIQUE;

void create()
{
        set_name(HIM"點液爪"NOR,({"dab-aqua-claw","claw"}) );
        set("long","一隻龍爪，色作淡紅，略帶香味，似乎為「狡龍  點液」的爪。\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","隻");
        set("value",16000);
        set("material","leather");
        set("weapon_prop/int",2);
                set("volume",2);
        set("weapon_prop/hit",5);
        set("limit_str",30);
        set("limit_level",15);
        set("replica_ob",__DIR__"dab-aqua-claw2");

        set("wield_msg","$N裝備一隻$n"+NOR"當武器，身上似乎散放地一股香味。\n" NOR);
        }
        set("weapon_prop/hit",5);
        set("weapon_prop/int",2);
        set("beast_weapon_prop/damage",55);
        set("beast_weapon_prop/hit",5);
        set("beast_weapon_prop/int",2);
        init_fist(55);
        setup();
}

void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
    
        if(random(100)<30 && !me->is_busy())
        {
          message_vision(HIM+ob->query("name")+ HIM "發出的香味被$N吸了幾口。\n" NOR,me);
          tell_object(me,HIW "你覺得週身內勁川流不息！！\n" NOR);
           me->receive_heal("ap",50);
        }
        return;
}


