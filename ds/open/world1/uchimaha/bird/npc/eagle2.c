#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���N",({"eagle"}));
        set("level",8);
        set("race", "���~");
        set("age", 8);
        set("long", "�o�O�@�����N�C\n");
        set("limbs", ({ "�Y��", "����", "�}", "����" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
        carry_object(__DIR__"eq/fist.c")->wield();
}
