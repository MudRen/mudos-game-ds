#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"�B�����v"NOR, ({ "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��q��z�����C, �O���������t�C�C\n");
                set("material", "blacksteel");
        }
        init_sword(50);
        set("wield_msg",CYN"$N�N�B�����v��X, �b�ɥ��v�{��, �٬O�~�H�C\n"NOR);

        set("unwield_msg",CYN"$N�N�⤤��$n��^�C�T�C\n"NOR);

        setup();
}

void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 50 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
         HIW "\n�u��$N�⤤�B�����v�@�{, �Q�C�D��F���C��¼ĤH�g�h�I�I\n" NOR
        ,me,target);

        damage += me->query_skill("unarmed")+me->query_str()+random(50);
        def += target->query_skill("dodge")+target->query_skill("combat")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIW "$N�{�����ΡA�C��n�ɥ������W�۩I�I�I\n"NOR,target);
      target->receive_damage("hp",damage);
        }
        else
        {
      message_vision(YEL "$N�N�Q�C�D�C��ɼƾ_�}, �@�v���ˡC\n"NOR,target);
        }

        }
        return;
}
