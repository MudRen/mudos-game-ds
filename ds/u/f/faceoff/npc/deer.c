#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���",({ "deer" }) );
         set("level",9);
        set("race", "���~");
        set("age", 3);
        set("long", "�e�O�@���ͪ��b�`�s�̪�����C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "�������L�ӬݤF�A�@���C\n",
                "������C�U�Y�~��Y��C\n",
           }) );
        setup();
}