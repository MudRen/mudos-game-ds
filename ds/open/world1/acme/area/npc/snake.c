#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�D", ({ "small snake","snake" }) );
        set("race", "���~");
        set("age", 1);
        set("long", "�e�O�@������b�ت��¦�p�D�A���ӬO���Ѭr�ʡC\n");
        set_temp("apply/hit",-20);
        set_temp("apply/dodge",-10);
        set("level",1);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite" }) );
        setup();
}
