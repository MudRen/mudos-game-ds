#include <ansi.h>
#include <weapon.h>

inherit FIST;
inherit F_UNIQUE;

void create()
{
        set_name(HIM"�I�G��"NOR,({"dab-aqua-claw","claw"}) );
        set("long","�@���s���A��@�H���A���a�����A���G���u���s  �I�G�v�����C\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",16000);
        set("material","leather");
        set("weapon_prop/int",2);
                set("volume",2);
        set("weapon_prop/hit",5);
        set("limit_str",30);
        set("limit_level",15);
        set("replica_ob",__DIR__"dab-aqua-claw2");

        set("wield_msg","$N�˳Ƥ@��$n"+NOR"��Z���A���W���G����a�@�ѭ����C\n" NOR);
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
          message_vision(HIM+ob->query("name")+ HIM "�o�X�������Q$N�l�F�X�f�C\n" NOR,me);
          tell_object(me,HIW "�Aı�o�g�����l�t�y�����I�I\n" NOR);
           me->receive_heal("ap",50);
        }
        return;
}


