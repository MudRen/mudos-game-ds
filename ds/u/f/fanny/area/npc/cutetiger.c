#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�Ѫ�", ({ "small tiger","tiger" }));
        set("race", "���~");
        set("age", 5);
        set("long", "�@���ܥi�R���p�Ѫ�A���M�e���S�̭̪��o����֥G�C\n"
);
        set("level",10);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "�p�Ѫ갽�������F�Ѫ�@�U�C\n",
        }));
        setup();
}
