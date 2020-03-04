#include <ansi.h>
inherit NPC;
void create()
{
        set_name(YEL"沼澤怪物"NOR, ({ "monster" }) );
        set("long", "一個全身佈滿蛔蟲和蛆的噁心生物。\n");
        set("race", "野獸");
        set("gender","雄性");   // 1999.2.28 增加此註解
        set("age", 1000);
        set("level",20);
        set("str", 20);
        set("dex", 20);
        set("con",10);
        set("limbs", ({ "頭部", "身體", "前肢", "後肢"  }) ); //受攻部位
        set("verbs", ({ "bite", "claw" }) );
        set_skill("unarmed",20);               
        set_temp("apply/damage", 10);   //附加傷害力
        set_temp("apply/hit", 20);      //附加命中率
        set_temp("apply/armor", 10);     //附加防禦力 
        set("chat_chance",20);
set("chat_msg", ({HIW"沼澤怪物吐出一團臭屎~~~\n"NOR,
        (:command("bite hunter"):),
         }));
        setup();
}
