#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"玲瓏魚"NOR,({ "fish" }) );
         set("level",14);
        set("race", "野獸");
        set("age", 1);
        set("long", "這是極為少見的一種魚類, 通常都是居住在海洞之中。\n");
        set("limbs", ({ "胸鰭", "尾鰭", "腹鰭", "尾部", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"../obj/light_cloth");
}