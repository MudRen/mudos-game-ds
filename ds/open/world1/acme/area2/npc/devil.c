#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "地魔女", ({ "devil girl","devil","girl", "__GUARD__" }) );
        set("level",32);
           set("combat_exp",3200);
set("exp",1000);
        set("long","他是一位臉色蒼白，毫無血色，且是殺人不貶眼的妖女。\n");
        set("age",30);
        set("evil",70);
set("title",HIR"群魔亂舞"NOR);
        set("gender","女性");
        set("attitude","killer");
             set_skill("blade",64);
             set_skill("dodge",64);
                   set_skill("parry",64);
        set("Merits/wit",2);
        setup();
}
