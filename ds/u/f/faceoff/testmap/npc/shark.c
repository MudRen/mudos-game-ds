#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�T��",({ "shark" }) );
         set("level",24);
       set("attitude", "aggressive");
        set("race", "���~");
        set("age", 3);
        set("long", "�o�O����̥��r������, �q�`�J�쳣�O���h�N�֡C\n");
        set("limbs", ({ "���_", "���_", "���_", "����", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/shark_bone");
}