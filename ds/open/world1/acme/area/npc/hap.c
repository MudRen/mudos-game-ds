#include <ansi.h>
inherit NPC;
void create()
{
        set_name("歐陽合",({ "hap ou yang","hap","ou","yang"}));
        set("title", HIC "劍癡" NOR);
         set("race","人類");
         set("gender","男性");
        set("age",43);
        set("level", 25);
        set_skill("sword",80);
        set_skill("parry",60);
        set_skill("dodge",70);
        set("long",
            "他是絕代劍癡，愛劍如狂，劍法造詣亦高，與「刀狂」併稱【神劍邪刀】。\n");
        setup();
        carry_object(__DIR__"wp/sword3.c")->wield();
} 
