#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "刀疵", ({ "blade chi","chi","blade", "__GUARD__" }) );
        set("level",14);
       set("gender","男性");
set("exp",500);
          set("combat_exp",1400);
              set("attitude","killer");
        set("long" ,"他是幽冥地窖中的刀使，但他生性不好武，故刀法造詣亦不強。\n");
        set("age",40);
        set("evil",40);
           set_skill("blade",28);
                set_skill("dodge",28);
                set_skill("parry",28);
        setup();
        carry_object(__DIR__"wp/blade.c")->wield();
}
