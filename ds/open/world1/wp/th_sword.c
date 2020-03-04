#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name(HIY"雷神劍"NOR,({"thunder-god sword","sword"}));
        set("long",@LONG
雷獸奴耶被馴服後所變化成的劍，擁有雷電的能力。
LONG
);
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",20);
        set("limit_skill",30);
        set("unit", "把");        
        set("value",1000);
        set("volume",4);        
        set("material","steel");       
              }        
        init_sword(50);
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
                        +HIY"$N手上的雷神劍幻化成雷獸，往$n衝去！\n"NOR
                        +HIR"$n心神被雷獸所攝，頓時被電得哇哇大叫！\n\n"NOR,me,victim);
  victim->receive_damage("hp", 100+random(100),me);
 me->receive_damage("mp",30);
 me->add_busy(1);
return;
}
