#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ܦ�",({ "antelope" }) );
       set("level",8);
        set("race", "���~");
        set("age", 3);
        set("long", "�e�O�@�����۶ø����ܦϡC\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
