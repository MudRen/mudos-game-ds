#include <ansi.h>
inherit NPC;
void create()
{
      int x;
      x = random(10);
        set_name("蚌",({ "clam" }) );
         set("level",20);
        set("race", "野獸");
        set("age", 3);
        set("long", "這是近海有時會見到的貝類, 有時裡面會有珍珠。\n");
        set("limbs", ({ "殼", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
    carry_object(__DIR__"../obj/clam_shell");
     if (x == 1 || x == 2 || x == 3)
	{
      carry_object(__DIR__"../obj/pearl");
	}
    if (x == 5)
	{
    carry_object(__DIR__"../obj/black_pearl");
	}

}