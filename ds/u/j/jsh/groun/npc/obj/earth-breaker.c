#include <weapon.h> 
#include <ansi.h>
inherit FORK; 
void create()
{
        set_name(HIB"�}�a���p"NOR, ({ "earth breaker","breaker" }) );
        set_weight(3400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");  
                set("limit_str",50);
                set("long",  
 "�o�O�@��I������j�A�����ο��K��y�Ӧ��A���׬O�����άO��
  �峣�i�H�y���j�j���}�a�A�j�W�I���l�p�G��A�i�H��ӹp�q��
  ��Ѱʦa���@���A�]�����}�a���p���O��\n");
                set("value", 4000);
        }
        init_fork(68);
        setup();
}
void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(10) < 6 && !me->is_busy()) return;
        message_vision(HIW"$N�|�_�⤤"+this_object()->query("name")+HIW"�y�ɤѤW�Q���E���A�K�ɤ@�D�{�q�H�ۺj�y���V$n�I\n"NOR,me,victim);
        me->receive_heal("mp",-50);  
        victim->receive_damage("hp",100) ;
        return;
}

