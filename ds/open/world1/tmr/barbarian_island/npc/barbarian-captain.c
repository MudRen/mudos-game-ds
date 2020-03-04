#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name("野蠻人", ({ "barbarian captain","barbarian","captain" }) );
        set("long",@long
在你眼前的這個野蠻人看起來比其他人高大威猛，似乎是這附近野蠻
人的首領。瞧他正對著一旁的族民講話，不知在交待什麼事情。
long
);
        set_race("human");
        set("title","首領");
        set("age", 35);
        set("chat_chance", 5);
        set("chat_msg", ({
                  "野蠻人首領說道：「te-o tsunai dara itemiyo」\n",
                  "野蠻人首領似乎在自言自語道：「mo eruyo natsukino kagayaku okani」\n",

        }));
        set_skill("twohanded blunt",60);        // 雙握棒法
        set_skill("parry",80);
        set_skill("dodge",50);
        setup();
        set_level(20);
        carry_object(__DIR__"obj/monster_pants")->wear();
         carry_object(__DIR__"obj/monster-waist")->wear();
        carry_object(__DIR__"obj/big-blunt")->wield();
}


