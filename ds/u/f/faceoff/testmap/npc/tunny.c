#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�C��",({ "tunny" }) );
         set("level",15);
        set("race", "���~");
        set("age", 2);
        set("long", "�@���C��, ���M�׽�S���D����, ���P���]���t�C\n");
        set("limbs", ({ "���_", "���_", "���_", "����", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/tunny_meat");
}