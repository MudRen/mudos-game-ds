#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�Ѫ�", ({ "tiger" }) );
        set("race", "���~");
        set("age", 25);
        set("long", "�@���­��������Ѫ�A�ݨӦ��G�����ۧA�C\n"
);
        set("level",20);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "�Ѫ�C�n���q�ۡC\n",
        }));
        setup();
}
