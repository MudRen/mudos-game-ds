#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"魯拉"NOR, ({"nuna"}) );
        set("race", "野獸");
        set("age",12);
        set("level",9);
        set("attitude","aggressive");
        set("long", HIY"魯拉Naboo森林的土產生物。\n"NOR);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("chat_chance",45);
        set("chat_msg",({
	(: "random_move" :),
        }) );
      set_skill("mob_bite",10);
      set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
       	 }) );
        set("verbs", ({ "bite", "claw","crash" }) );
        setup();
}
