#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�Q�~",({ "crow" }) );
         set("level",10);
        set("race", "���~");
        set("age", 3);
        set("long", "�@�������ʻ�j���p�ʪ��C\n");
        set("limbs", ({ "�Y��", "����", "�e��", "���", "����", "���l" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
}