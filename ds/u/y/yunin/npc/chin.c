#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�����W", ({ "chin yo min","chin" }) );
  set("gender", "�k��" );
  set("long",@LONG
���O�Z�L�Q�D���w����l�A���]�@�f���i��ӨӨ�F�ѬɤS��W�F�|��Ѥ����@�C
LONG
);

 set("age",819);
  set("level",41);
  set("title",HIR"�|��Ѥ����@"NOR);
  set("max_hp",41201);
  set("max_mp",2100);
  set("max_ap",3000);
  set("exp",35000+random(3000));
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

HIR"\n�i�Z�L��ǡj"+HIR""+ob->name(1)+"�}�F�����|�𤧤@���]���C\n\n"NOR,users());
tell_object(ob,HIR"[���F"HIB"�����W"HIR"���A�i�o��3�I�n��]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

