#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "崇椎", ({ "chong jui","chong","jui", "__GUARD__" }) );
        set("level",15);
           set("combat_exp",1500);
        set("long" ,
            "他是幽冥地窖中的椎使，從小就習椎法，但在一次戰役中，不幸受了重傷\n"
            "從此武功\大退，只恢復以往功\力的三成，從他的眼中可看見一絲的怨恨。\n"
           );
        set("age",30);
        set("gender","男性");
           set("attitude","killer");
       set("evil",45);
        set_skill("dagger",30);
//    set_skill("darkdagger",30);
        set_skill("dodge",30);
        set_skill("parry",30);
     set("chat_chance_combat",70);
        set("chat_msg_combat", ({
           (:command("exert darkdagger"):),
        }) );
        setup();
        carry_object(__DIR__"wp/dagger.c")->wield();
     carry_object(__DIR__"eq/finger.c")->wear();
}
