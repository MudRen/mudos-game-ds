#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�P�D��", ({ "yan fa yan","yan" }) );
  set("gender", "�k��" );
  set("long",@LONG
�����|�𤧤@���u��Ѥ��A�֦~�ɡA�b�Y�����Z�N�j�|�̡A����
������̴ݼɪ��H���A�ҥH�Q�Ѭɸt�����l�ܯ����|��̷���u��
�Ѥ��C
LONG
);

 set("age",997);
  set("level",41);
  set("title",HIR"�|��Ѥ����@"NOR);
  set("max_hp",31012);
  set("max_mp",3000);
  set("max_ap",2900);
  set("race","human");
  set("chat_chance", 20);
  set_skill("unarmed",91);
  set_skill("sword",100);
set_skill("dodge",80);
  set("Merits/bar",4);

setup(); 
carry_object(__DIR__"wp/only1")->wield();
carry_object(__DIR__"eq/shu12")->wear();
carry_object(__DIR__"eq/shu11")->wear();
carry_object(__DIR__"eq/shu10")->wear();
carry_object(__DIR__"eq/shu9")->wear();
carry_object(__DIR__"eq/shu8")->wear();
carry_object(__DIR__"eq/shu7")->wear();
carry_object(__DIR__"eq/shu6")->wear();
carry_object(__DIR__"eq/shu5")->wear();
carry_object(__DIR__"eq/shu4")->wear();
carry_object(__DIR__"eq/shu3")->wear();
carry_object(__DIR__"eq/shu2")->wear();
carry_object(__DIR__"eq/shu1")->wear();
carry_object(__DIR__"eq/shu0")->wear();
carry_object(__DIR__"eq/shu00")->wear();
  }
void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
 ob = this_player(1);
   if( !ob )
   {
 ::die();

     return;

   }

 message("world:world1:vision",

HIR"\n�i�Z�L��ǡj"+HIY""+ob->name(1)+"�}�F�����|�𤧤@����ù��C\n\n"NOR,users());
tell_object(ob,HIR"[���F"HIB"�P����"HIR"���A�i�o��3�I�n��]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

