#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"沙加"NOR, ({"shaak"}) );
        set("race", "野獸");
        set("age",20);
        set("level",5);
        set("attitude","friendly");    
        set("long","沙加是人隻溫和,友善的動物。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("chat_chance",70);
        set("chat_msg",({
	(: "random_move" :),
        }) );
        set("verbs", ({ "bite", "claw","hoof" }) );
        setup();
}
