#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�¯T" , ({ "dark wolf","wolf","dark" }) );
        set("level",15);
        set("race","���~");
        set("gender","�k��");
        set("age",35);
        set_skill("parry", 30);
set("attitude","aggressive");
set("verbs", ({ "claw" }));
        set_skill("unarmed", 20);
        set_skill("dodge", 30);
        set("long","�@�����r���ʪ��C\n");
        setup();
}


