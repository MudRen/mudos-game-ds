#include <ansi.h>
#include <weapon.h> 
//inherit F_UNIQUE;
inherit AXE;

void create()
{
  set_name("���K����",({"iron axe","axe"}) );
  set("long",
"�@��I�������Y�A�ധ�ʥ����H�A�Q���@�w���O�x�x�����C\n"
);
        set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("volume",2);
                set("unit","��");
               set("value",2500);
                //set("limit_str",35); 
                //set(limit_con",30); 
               // set("replica_ob",__DIR__"axe2");
        }
                //set("weapon_prop/parry",10); 
               //set("weapon_prop/con",1);
               // set("weapon_prop/str",3);
                //set("weapon_prop/dex",-2);
init_axe(20);
        setup();
} 

/*
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
 if( me->query("mp") < 50 ) return;
 if( random(10) < 6 ) return;
 message_vision("\n"
                        +HIY"$N�ϫl���N��W������@�A�I\n"NOR
                        +HIR"$n�Q�I�������򤧤O�ļ��ۡA�d�U�F���j���ˤf�I\n\n"NOR,me,victim);
  victim->receive_damage("hp", 150+random(100),me);
 me->receive_damage("mp",30);
 me->add_busy(1); 
 victim->add_busy(2);
 return;
}
*/
