#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���W",({"fox"}));
        set("level",15);
        set("race", "���~");
        set("age", 16);
        set("long", "�o�O�@���j�����W�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
