#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR "血腥"NOR"老怪", ({ "hir" }) );
        set("level",37);
           set("combat_exp",5000);
         set("exp",2000);
set("long","這是一個噬血如狂的邪惡妖怪，渾身充滿邪氣，一雙血紅的眼睛正狠狠的瞪著你。\n");
;
        set("age",60);
        set("evil",80);
     set("title",WHT"五代"NOR);
        set("gender","男性");
        set("attitude","killer");
             set_skill("unarmed",80);
        set_skill("dodge",90);
                  set_skill("parry",90);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-cloth")->wear();
}

