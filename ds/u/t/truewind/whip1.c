#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIM"��ýt"NOR,({"Marriage needle-whip","whip"}) );
        set_weight(1000);
        set("long",@long
�@�����������u�A�q��ȥաA���@�����⪺���ݱq�Y�e��A�٬O�n�ݡC
long
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1500);
        set("unit","��");
        set("wield_msg","$N�N$n���a��X�A��¶�b��W�C\n");
        set("material","iron");
        }
        init_whip(30);
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
                        +HIW"$N���۫��y�A��ýt�Y�����ު���$n���h�I\n"NOR
                        +HIW"��ýt�e��F$n������A�r�a�@�n���T�I\n\n"NOR,me,victim);
  victim->receive_damage("hp", 100+random(100),me);
 me->receive_damage("mp",30);
 me->add_busy(1);
return;
}
