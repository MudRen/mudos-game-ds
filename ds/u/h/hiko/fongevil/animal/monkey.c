#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���U",({ "monkey" }) );
        set("race", "���~");
        set("age",6);
        set("long", "�e�O�ͬ��b�`�s�����U�A�ݨӬ۷��i�R�C\n");
        set("level",20);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "���U�b��W�������h�A�ݰ_�ӤQ���ּ֡C\n", }) );
        setup();
}


