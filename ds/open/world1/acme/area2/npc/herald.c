#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "丈運使", ({ "estimate destiny herald","estimate","destiny","herald" , "__GUARD__"}) );
        set("level",37);
           set("combat_exp",3700);
set("exp",2500);
        set("long","他是一位手上拿著鐵尺的老人，眼神十分兇惡。\n");
        set("age",70);
        set("evil",70);
        set("title",HIR"群魔亂舞"NOR);
        set("gender","男性");
        set("attitude","killer");
            set_skill("dagger",74);
//        set_skill("darkdagger",74);
           set_skill("dodge",74);
          set_skill("parry",74);
        set("chat_chance_combat",70);
        set("chat_msg_combat", ({
           (:command("exert darkdagger"):),
        }) );
        setup();
      carry_object(__DIR__"wp/ruler.c")->wield();
    carry_object(__DIR__"eq/surcoat.c")->wear();
}
