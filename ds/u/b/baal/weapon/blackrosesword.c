#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(MAG"�ª������C"+NOR, ({ "black rose sword","sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ª������C�A���A�G�����������M�h�w���䪺�t�C�C\n");
                set("material", "blacksteel");
                set("value",20000);
        }
        init_sword(40);
        set("wield_msg",RED"$N�N$n"RED"���b�⤤�A���n�j�ۡG�uEst Sularus Oth Mithas�I�I�v�C\n"NOR);

set("unwield_msg",RED"$N�N�⤤��$n"RED"���^�C�T�A�V�b����{ģ���·t���Z���P�y��̷q§�C\n"NOR);

        setup();
}


void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 10 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
         HIW "\n$N���n�j�ۡG�uEst Sularus Oth Mithas�I�I�v�L�ƹD���F�Q����A�ĦV�ĤH�I�I\n" NOR
        ,me,target);

        damage += me->query_skill("sword")+me->query_str()+random(30);
        def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIR "$N���פ��ΡA�uı�����ͩR�O�����y���ӥX�I�I\n"NOR,target);
    target->receive_damage("hp",1500);
        }
        else
        {
      message_vision(HIG "$N�f������w�۩��ԤB��ë��A�L���󨸴c���O�q�C\n"NOR,target);
        }

        }
        return;
}
