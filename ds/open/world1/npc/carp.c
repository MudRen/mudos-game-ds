#include <ansi.h>
inherit NPC;
void create()
{
        set_name("鯉魚",({ "carp" }) );
         set("level",13);
        set("race", "野獸");
        set("age", 2);
        set("long", "一隻鯉魚, 它的肉質鮮美, 一直是商人的最愛。\n");
        set("limbs", ({ "胸鰭", "尾鰭", "腹鰭", "尾部", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
	carry_object(__DIR__"../obj/carp_meat");
}