#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIG"�v���"NOR, ({ "meat-eat worm","worm" }) );
        set("race", "���~");
        set("age", 1);
        set("level",2);
        set("long", "���Ѧb�U���襤���u�����ΡA���o���L�Q���C\n");
        set("limbs", ({ "�Y��", "����", "����" }) );
        set("verbs", ({ "bite" }) );
        set("chat_chance", 10);
        set("chat_msg", ({
           (: this_object(), "random_move" :),
           "�v���b���䪺�U�����½��½�h�C\n" }) );
        setup();
}

int special_attack(object me,object victim,int hitrole)
{
        if(!me || !victim) return 0;
        if(random(5)) return 0;
        
        message_vision(HIW"$N���L�Q����$n�@�}�ër�A"NOR,me,victim);
        if(hitrole > 100)
        {
                victim->apply_condition("poison", victim->query_condition("poison")+3);
                message_vision(HIW"$n�{�����ΦӳQ�r���A�ˤf�o���C\n"NOR,me,victim);
                victim->receive_damage("hp",20+random(20),me);
                return 1;
        }
        else message_vision(HIW"���Q$n��ĵ���{�F�L�h�C\n"NOR,me,victim);
        return 0;
}
