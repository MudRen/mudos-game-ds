#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIW "�p�ը�" NOR ,({ "rabbit" }) );
        set("level",1);
        set("race", "���~");
        set("age", 1);
        set("long", "�e�O�@���i�R���p�ըߡC\n");
set_temp("apply/hit",-10);
set_temp("apply/dodge",-10);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );

        setup();
}
