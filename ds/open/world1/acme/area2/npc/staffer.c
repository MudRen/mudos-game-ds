#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "鬼杖客", ({ "ghost staffer","ghost","staffer" , "__GUARD__"}) );
        set("level",30);
           set("combat_exp",3000);
set("exp",2000);
set("long","他是幽冥地窖中的使杖高手，在許\許\多多的戰役中，殺了不少敵人的大將。\n");
        set("age",50);
       set("evil",40);
                set("title",CYN"鬼出神沒"NOR);
         set("gender","男性");
                 set("attitude","killer");
           set_skill("staff",60);
          set_skill("dodge",60);
           set_skill("parry",60);
        set("Merits/wit",2);
        setup();
        carry_object(__DIR__"wp/staff.c")->wield();
}
