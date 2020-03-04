#include <ansi.h>
inherit NPC;
void create()
{
        set_name("花鹿",({ "deer" }) );
         set("level",9);
        set("race", "野獸");
        set("age", 3);
        set("long", "牠是一隻生長在深山裡的花鹿。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴", "鹿角" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "梅花鹿轉過來看了你一眼。\n",
                "梅花鹿低下頭繼續吃草。\n",
           }) );
        setup();
}
