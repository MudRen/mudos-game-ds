#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"�ܺإ��^"NOR,({"mutated weasel", "weasel" }) );
        set("long",@LONG
�����F����ìV���ܺت��j���ͪ��A�w�g�ݤ��X�e�쥻�O�����
���A�u���D�L�{�b�ݰ_�ӴN�O�@���Τj���^���Ӥw�I

LONG
);
        set("title","�a���ͪ�");
        set("race", "���~");
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "���", "�y��", "����", "�y��","����",
        }) );
        set("age",50+random(19));
        set("level",10);
        set("int",8);
        set("gender","�۩�");
        set("attitude","killer");
        set("verbs", ({ "bite","claw" }) );
        set("chat_chance", 9);
        set("chat_msg",({
                (:random_move :),
                (:random_move():),
        })      );
        setup();
}



