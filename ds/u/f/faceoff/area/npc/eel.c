#include <ansi.h>
inherit NPC;
void create()
{
        set_name("鰻魚",({ "eel" }) );
         set("level",6);
       set("attitude", "aggressive");
        set("race", "野獸");
        set("age", 1);
        set("long", "這是近海常見的兇猛魚類, 遇到了要相當小心。\n");
        set("limbs", ({ "胸鰭", "尾鰭", "腹鰭", "尾部", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/lee_meat");
}