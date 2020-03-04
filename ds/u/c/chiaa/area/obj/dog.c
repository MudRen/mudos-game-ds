#include <ansi.h>
inherit NPC;
void create()
{
        set_name("大狼狗", ({ "dog" }) );
        set("race", "野獸");
        set("age", 7);
        set("long", "一隻可愛滴大狼狗。\n");
        set("str", 30);
        set("cor", 20);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 500);
        set("potential", 10);
        set_temp("apply/attack", 15);
        set_temp("armor", 3);
        set("chat_chance", 10);
        set("chat_msg", ({
                HIY"大狼狗對著你狂吠：汪!汪..汪..。"NOR"\n",
                (: random_move :),
        }) );
        setup();
}

