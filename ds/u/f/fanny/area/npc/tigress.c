#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���Ѫ�", ({ "tigress" }) );
        set("race", "���~");
        set("age", 23);
        set("long", "�@�����ڤڪ����Ѫ�A�ݨӦ��G�����ۧA�C\n"
);
        set("level",20);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "���Ѫ깳���p�ߤ@�˾a�b�Ѫꨭ�W�C\n",
        }));
        setup();
}
