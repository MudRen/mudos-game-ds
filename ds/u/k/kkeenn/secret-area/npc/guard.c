#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIW"防衛隊員"NOR,({"defend guard","guard"}) );
        set("long",@LONG
地下城的守衛。
LONG
);
        set("title","『城內自衛隊』");
         set("age",35);
         set("level",50);
         set("gender","男性");
         set("race","human");
         set("attitude", "aggressive");
         set("chat_chance", 13);
         set("chat_msg",({ 
               (: random_move :),
        "防衛隊員說: 為城主報仇阿！！\n",
              }));
          set("addition_armor",100);
          set("Merits/wit",3);
          set("addition_damage",50);
          add("apply/hit",50);

        setup();
}

