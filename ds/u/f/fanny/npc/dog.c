#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "dog" }) );
        set("race", "���~");
        set("age", 5);
        set("long", "�e�O�@������ż�����������C\n"
);
        set("level",2);
        set("dex",-1);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
          (: random_move :),
                "������ۧA�p�s�F�X�n�C\n",
        }));
        setup();
}

