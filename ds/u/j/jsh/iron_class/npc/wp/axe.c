#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit AXE;

void create()
{
  set_name(HIY"黃鐵巨斧"NOR,({"iron axe","axe"}) );
  set("long",
"一把沉重的斧頭，能揮動它的人，想必一定不是泛泛之輩。\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("volume",2);
                set("unit","把");
               set("value",15450);
                set("limit_str",35); 
                set("limit_con",30); 
                set("replica_ob",__DIR__"axe2");
        }
                set("weapon_prop/parry",10); 
               set("weapon_prop/con",1);
                set("weapon_prop/str",3);
                set("weapon_prop/dex",-2);
init_axe(43);
        setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
 if( me->query("mp") < 50 ) return;
 if( random(10) < 6 ) return;
 message_vision("\n"
                        +HIY"$N使勁的將手上的巨斧一劈！\n"NOR
                        +HIR"$n被沉重的巨斧之力衝撞著，留下了巨大的傷口！\n\n"NOR,me,victim);
  victim->receive_damage("hp", 150+random(100),me);
 me->receive_damage("mp",30);
 me->add_busy(1); 
 victim->add_busy(2);return;
}

