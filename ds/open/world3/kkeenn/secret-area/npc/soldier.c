#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIY"小風沙"NOR,({"wind robot","robot"}) );
        set("long",@LONG
黃塵怪最忠實的手下。
LONG
);
        set("title","『助紂為虐』");
         set("age",90);
         set("level",55);
         set("gender","中性");
         set("max_hp",10000);
         set("hp",10000);
         set("race","robot");
         set("attitude", "aggressive");
         set("chat_chance", 13);
         set("chat_msg",({ 
               (: random_move :),
        "小風沙的四周捲起了重重的龍捲風？\n",
        "小風沙昂天狂哮~~。\n",
        "小風沙緩緩的舉起手，像大門揮了一下。\n",
        "小風沙身上的殺氣慢慢的散發出來。\n",
        }));
          set("addition_armor",100);
          set("Merits/wit",3);
          set("addition_damage",50);
          add("apply/hit",50);

        setup();
}

