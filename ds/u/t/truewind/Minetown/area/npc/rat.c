#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��g��",({"Radiated rat", "rat" }) );
        set("long",@LONG
�@���`��⪺���j�ѹ��A���W���X�ӯ}�ꪺ�ˤf�A�]������a��
�U�ìV�������v�T���ܱo�ʼɦӨ㦳�����ʡC

LONG
);
        set("title","�a���ͪ�");
        set("race", "���~");
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "���", "�y��", "����", "�y��","����",
        }) );
        set("age",3+random(3));
        set("level",5);
        set("int",3);
        set("attitude","killer");
        set("gender","����");
        set("verbs", ({ "bite","claw" }) );
        set("chat_chance", 9);
        set("chat_msg",({
                (:random_move :),
                (:random_move():),
        })      );
        setup();
}

