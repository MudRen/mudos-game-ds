#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC "星恆"NOR"之怪", ({ "hir" }) );
        set("level",37);
           set("combat_exp",5000);
         set("exp",2000);
set("long","一個充滿謎的妖怪，沒人知道他從哪裡來，會到哪裡去。\n");
;
        set("age",60);
        set("evil",80);
     set("title",WHT"魔空"NOR);
        set("gender","男性");
        set("attitude","killer");
             set_skill("unarmed",90);
        set_skill("dodge",90);
                  set_skill("parry",90);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-helmer")->wear();
}

