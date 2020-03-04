#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟茶水使",({"bird waiter","waiter"}));
 set("long","你看了看眼前的茶水小弟, 只想起天梟有所謂的[一茶, 二帳, 三神匕],\n"
              "這句話來, 看來這句話真不是亂說的.\n"
    );
 set("attitude","peaceful"); 
 set("age",18);
 set("gender","男性");
 set("level",10);
 set_skill("unarmed",30);
 set("chat_chance",20);
 set("chat_msg", ({"茶水使殷勤的添滿了桌上的茶杯.\n",
                            "茶水使將桌子擦了一擦 .\n",
                        "茶水使把床鋪整理的一塵不染.\n",
                   (:command("sweat"):),
 }));

 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

