#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�ն��a", ({ "by yun zan","by" }) );
  set("gender", "�k��" );
  set("long",@LONG
�����|�𤧤@���u��Ѥ��A�쬰�@���H�C�ȡA���b�@������L�M�q���A�Q��T�l�ݨ��A
��T�l�K�a�ն��a�h���Ѭɸt���A�g�@�f����A���o�|��Ѥ����@���\�W�C
LONG
);

 set("age",819);
  set("level",41);
  set("title",HIR"�|��Ѥ����@"NOR);
  set("max_hp",33012);
  set("max_mp",1900);
  set("max_ap",2100);
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

HIR"\n�i�Z�L��ǡj"+HIC""+ob->name(1)+"�}�F�����|�𤧤@���a�Ӷ�C\n\n"NOR,users());
tell_object(ob,HIR"[���F"HIB"�ն��a"HIR"���A�i�o��3�I�n��]\n"NOR);

 ob->add("popularity",3);
 ::die();
   return;

}

