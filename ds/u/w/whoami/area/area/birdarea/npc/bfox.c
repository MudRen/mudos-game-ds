#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�j���W",({"big fox", "fox"}));
        set("level",20);
        set("race", "���~");
        set("age", 16);
        set("long", "�o�O�@���髬��A�t���h�j�����j���W�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
