#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB "殭屍"NOR"王", ({ "ghost kind","ghost","kind" }) );
        set("level",35);
           set("combat_exp",4000);
         set("exp",3000);
set("long","這是一隻帶領殭屍投套秦始皇的頭頭，身上的寶貝也不少喔。\n");
;
        set("age",50);
        set("evil",70);
     set("title",CYN"幻度"NOR);
        set("gender","男性");
        set("attitude","killer");
             set_skill("unarmed",90);
        set_skill("dodge",70);
                  set_skill("parry",70);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-mask")->wear();
}
