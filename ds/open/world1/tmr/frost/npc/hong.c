#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�x��i", ({ "hong lingbo", "hong", "lingbo" }));
        set("long", "�x��i�O����P�l�����T�j�̤l�A���۲����A�`�o�v�L���߷R�C\n");
        set("gender", "�k��");
        set("attitude","heroism");

        set("level", 30);
        
        set_skill("whip",100);
        set_skill("block",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("sword",100);

        create_family("�j�Ӭ�", 4, "�̤l");

        setup();
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 50);
        carry_object(__DIR__"wp/steel-sword")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon;
    if(!me || !target)
        return 0;
    if(random(10)<7) return 0;

    message_vision(HIC"\n$N"HIC"�b�ܤ@�n�A�Y�X�@�D�G�զ⪺���~�S�J$n"HIC"���u�̡A���M�O�B�z�Ȱw�I�I\n" NOR,this_object(), target);
    target->receive_damage("hp", query_damage()/2 + random(query_damage()), this_object());
    target->apply_condition("poison", 5);
    target->add_busy(1);
    return 1;
}

