#include <ansi.h>
inherit NPC;
void create()
{
        set_name("坎水將" , ({ "water general","general" }) );
        set("title",HIC"ξ神武教ξ 八神將"NOR );
        set("long",
                   "他是神武教護法八神將之一的坎水將，\n"
                   "他看起來心高氣傲，但是個講義氣，重\n"
                   "感情之人，做起事來全力以赴，毫不退\n"
                   "縮。\n"
             );
        set("level",25);
        set("race","人類");
        set("gender","男性");
        set("age",40);
//        set_spell("god-benison",60);
        set_skill("mirage-steps",60);
        set_skill("godsword",60);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
        set("chat_chance",5);
        set("chat_msg",({
            "坎水將喃喃自語地說道：這個施迅不知把邪教一干人藏到哪去了。\n",
            (: random_move :),
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
      carry_object(__DIR__"wp/longsword.c")->wield();
     carry_object(__DIR__"eq/shield2.c")->wear();
}
