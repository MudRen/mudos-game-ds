#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�", ({ "yuan","yuan" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",33);
        set("age",35);
        set("evil",-20);
        set("attitude", "peaceful");
        set("title",HIR"�t�����"NOR);
        set("long",@LONG
�H�p��W�A��Ө���N���O�Ӳy�@�ˡA��u�u���A��ߦa��
�ܷO�d�A�O�Ӱ@�۪���Ю{�A���߰����A�]���L����O�j��
�O���m�ʪ��O�q�C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/bs_hands")->wear();
        carry_object(__DIR__"../eq/bt_neck")->wear();
}

int special_attack(object me,object target,int hitchance)
{
	if(!me || !target) return 0;
        if(random(4)) return 0;
        if(me->query("mp")<16) return 0;
        message_vision(HIM"$N���G��_�F�@��������O\n"NOR,me,target);
        me->receive_heal("hp",100+random(100) );
        me->receive_damage("mp",16);
        me->add_busy(1);
        return 1;
}
