#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "勤軼", ({ "chin yi","chin","yi", "__GUARD__" }) );
        set("level",18);
           set("combat_exp",1800);
set("exp",1000);
      set("evil",35);
set("long" ,"他是幽冥地窖中的神射手，有千步穿揚的神力。\n");
        set("age",40);
      set("gender","男性");
          set_skill("bow",36);
          set_skill("dodge",36);
          set_skill("parry",36);
              set("attitude","killer");

     set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                  (:command("shoot"):),
        }) );

        setup();
       carry_object(__DIR__"wp/bow.c")->wield();
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
       carry_object(__DIR__"obj/arrow.c");
}


