#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�Զc", ({ "chin yi","chin","yi", "__GUARD__" }) );
        set("level",18);
           set("combat_exp",1800);
set("exp",1000);
      set("evil",35);
set("long" ,"�L�O�խߦa���������g��A���d�B�ﴭ�����O�C\n");
        set("age",40);
      set("gender","�k��");
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


