#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"溫加"NOR, ({"rancor"}) );
        set("race", "野獸");
        set("age",10);
        set("level",10);
        set("attitude","aggressive");
        set("long",HIY"一隻可怕的食肉野獸。他有一對不成比例的長臂，巨大的尖牙和銳利的爪。\n"NOR);
        set("limbs", ({ "頭部", "身體", "前腎", "後腳", "尾巴" }) );
        set("chat_chance",65);
        set("chat_msg",({
	(: "random_move" :),
        }) );
      set_skill("mob_bite",10);
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (:command("exert mob_bite sacer"):),
           	 }) );
        set("verbs", ({ "bite", "claw"}) );
        setup();
}
