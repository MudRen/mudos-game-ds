#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"�I�I�I����I�I�I"+NOR, ({ "toothbrush","toothbrush" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����N�O����A�ݤT�p�I�H\n");
                set("material", "rubber");
                set("no_sell", 1);
        }
        init_sword(40);
        set("wield_msg",HIW"$N�N$n"HIW"���b�⤤�A���n�j�ۡG�u��ı�e�@�w�n����I�I�v�C\n"NOR);

set("unwield_msg",HIW"$N�N�⤤��$n"HIW"���^�콦�U�A���n�j�ۡG�u�꧹���n���f�I�I�v�C\n"NOR);

        setup();
}


void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 10 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
         HIY "\n$N���n�j�ۡG�u�p�l�L��ż�A�ݷ����A�����I�I�v�ΤO��}$n���j�L�A�N�n��$n����C\n" NOR
        ,me,target);

        damage += me->query_skill("sword")+me->query_str()+random(30);
        def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIG "$N�ʼu���o�A�����Q��������X�@�D�D�����I�I\n"NOR,target);
    target->receive_damage("hp",150);
        }
        else
        {
      message_vision(HIC "$N�d�v�@�v���ڰk�F�}�ӡA�����o�H�O���C\n"NOR,target);
        }

        }
        return;
}

