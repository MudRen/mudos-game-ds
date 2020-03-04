#include <ansi.h>
inherit NPC;
void create()
{
   set_name("忍者 練習生", ({ "trainee" }) );
   set("gender", "男性" );
   set("age",14 );
   set("long", "一個努力練習的小伙子\n");
   set("str",10 );
   set("cor",10 );
   set("combat_exp", 1000);
   set("potential", 30);
   set_temp("apply/attack", 30);
   set_temp("apply/armor", 20);
   add_money("silver",10);
   set_skill("sword",300);//技能設定
   set_skill("unarmed",300);//技能設定
   set_skill("dodge",300);//技能設定
   set("max_gin", 200);
   set("max_kee", 800);
   set("max_sen", 200);
   carry_object("/u/c/chiaa/obj/eq/wood blade")->wield();
   carry_object("/u/c/chiaa/obj/eq/leather cloth")->wear();
  setup();
}
