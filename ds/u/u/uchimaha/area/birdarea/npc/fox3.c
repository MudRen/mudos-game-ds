#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���W",({"fox"}));
        set("level",10);
        set("race", "���~");
        set("age", 14);
        set("long", "�o�O�@�����W�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
