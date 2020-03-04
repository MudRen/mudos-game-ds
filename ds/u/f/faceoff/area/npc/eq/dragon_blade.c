#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIY"�s"+NOR+""+MAG+"��"+NOR+""+HIY+"�S"+NOR+""+MAG+"��"NOR, ({ "dragon blade","blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�E�ɪ��t�M, �O�b�@�����M���|���o�쪺���@�_�M!\n");
                set("material", "blacksteel");
		set("value",20000);
        }
        init_blade(40);
        set("wield_msg",MAG"$N�N�s���S���X, �b�������Ǩ��s�S���n...�C\n"NOR);

        set("unwield_msg",CYN"$N�N�⤤��$n��^�M�T�C\n"NOR);

        setup();
}


void attack(object me,object target)
{
        int damage,def;

    if(me->query_skill("sword") > 50 && me->query_dex() > 20 && random(10)<3 )
        {
        message_vision( 
          HIW "\n���D$N�⤤�s���S��j�_, �@���s�𳺱q�s���S�뤤�g�X, ���V�ĤH�I�I\n" NOR
        ,me,target);

        damage += me->query_skill("blade")+me->query_str()+random(30);
        def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
        def = def/3;
        if(damage-def>0 && random(10)>5)
        {
    damage=damage+random((damage-def));
       message_vision(HIR "$N�����p�����, �N�s��ӳ�����I�I\n"NOR,target);
    target->receive_damage("hp",damage);
        }
        else
        {
      message_vision(HIG "$N�j�ܤ@�n, �N�s������촲, ���p���¡C\n"NOR,target);
        }

        }
        return;
}
