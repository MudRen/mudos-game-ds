#include <ansi.h>
inherit NPC;

void create()
{
       set_name("吳一",({"wu yi","wu"}));
       set("long",@LONG
    他是神武流無形的得意弟子，長期跟著師父東征西跑的，可是他自己
心裡想著這一切都是值得的，還有一點這個弟子非常好學，可是神武教算
少數的文武雙全的人。
LONG);
       set("gender","男性");
       set("age", 30);
       set("level", 35);
       set("nickname",HIW"織火飛天"NOR);
       create_family( HIC "ξ神武教ξ" NOR ,3,"弟子");


        set_spell("god-fire",70);
        set_spell("god-benison",50);
        set_skill("godsword",80);
        set_skill("mirage-steps",90);


       set("chat_chance", 10);
       set("chat_msg", ({
            (:command("hmm"):),
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
        
             }));


        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("cast god-benison"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
                  (:command("cast god-benison"):),
                  (:command("cast god-fire"):),
        }) );

    
        setup(); 
       carry_object("/open/world1/acme/area/npc/wp/sword2")->wield();
       carry_object("/open/world1/acme/area/npc/eq/surcoat.c")->wear();
        carry_object("/open/world1/acme/area/npc/eq/wrists")->wear();         

}
