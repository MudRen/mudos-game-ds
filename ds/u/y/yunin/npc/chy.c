#include <ansi.h>
inherit NPC;
void create()
{
  set_name("����", ({ "chy chen","chy" }) );
  set("gender", "�k��" );
  set("long",@LONG
�L�O�ѤU�i�H�u�e���v�B�u�K���v�B�u���Z�v�Ҭ۴��ýת������w�j��y�����ǤH
�L��U�F���ު��������d�j���A�ӨӦ��B��|��Ѥ��A���䤤���G�t�������C
LONG
);

 set("age",420);
  set("level",50);
  set("title",HIR"�|��Ѥ����@"NOR);
  set("max_hp",50000);
  set("max_mp",3000);
  set("max_ap",3000);
  set("exp",35000+random(4000));
  set("race","human");
  set("chat_chance", 20);
  set_skill("unarmed",91);
  set_skill("sword",100);
  set_skill("parry",80);
  set_skill("dodge",80);
  set("Merits/bar",4);

setup();
  
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

HIR"\n�i�Z�L��ǡj"+HIW""+ob->name(1)+"�}�F�����|�𤧤@���Ȥ��C\n\n"NOR,users());
tell_object(ob,HIR"[���F"HIB"����"HIR"���A�i�o��3�I�n��]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

