#include <ansi.h>
inherit NPC;
void create()
{
        set_name("乾天將" , ({ "sky general","general" }) );
        set("long",
                  "他是神武教護法八神將之一的乾天將，\n"
                  "他彷如蓄勢待起的騰龍，外表冷靜、剛\n"
                  "健，似乎是很有氣力之人，活力充沛成\n"
                  "為領導。\n"
            );
        set("title",HIC"ξ神武教ξ 八神將"NOR );
        set("level",25);
        set("race","人類");
        set("gender","男性");
        set("age",40);
//        set_spell("god-benison",60);
        set_skill("godsword",60);
        set_skill("mirage-steps",60);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
     set("chat_chance", 5);
        set("chat_msg", ({
                "乾天將說道：施迅，據密報指出你府上有包藏邪派教徒，這事是真還假！\n",
                "乾天將說道：施迅，你還不快快招認！\n",
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
      carry_object(__DIR__"wp/longsword.c")->wield();
  carry_object(__DIR__"eq/surcoat2.c")->wear();
}
