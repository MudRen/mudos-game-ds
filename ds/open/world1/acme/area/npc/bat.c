#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "bat" }) );
        set("race", "���~");
        set("age", 2);
        set("long", "�e�O�@���¦⪺�p�����C\n");
        set_temp("apply/hit",-20);
        set_temp("apply/dodge",-10);       
        set("level",2);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
