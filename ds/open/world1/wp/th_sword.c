#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name(HIY"�p���C"NOR,({"thunder-god sword","sword"}));
        set("long",@LONG
�p�~���C�Q���A����ܤƦ����C�A�֦��p�q����O�C
LONG
);
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",20);
        set("limit_skill",30);
        set("unit", "��");        
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
                        +HIY"$N��W���p���C�ۤƦ��p�~�A��$n�ĥh�I\n"NOR
                        +HIR"$n�߯��Q�p�~����A�y�ɳQ�q�o�z�z�j�s�I\n\n"NOR,me,victim);
  victim->receive_damage("hp", 100+random(100),me);
 me->receive_damage("mp",30);
 me->add_busy(1);
return;
}
