#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����",({ "eel" }) );
         set("level",6);
       set("attitude", "aggressive");
        set("race", "���~");
        set("age", 1);
        set("long", "�o�O����`�������r����, �J��F�n�۷�p�ߡC\n");
        set("limbs", ({ "���_", "���_", "���_", "����", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/lee_meat");
}