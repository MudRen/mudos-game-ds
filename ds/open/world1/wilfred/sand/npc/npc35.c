#include <ansi.h>
inherit NPC;

void create()
{
  set_name(WHT"�ۯ�"NOR,({"stone statue","statue"}) );
  set("long",@LONG

�@�Ӥ��ư_�����۹��A�n����b�o�̤v���۷��ɶ��F�A
�ܩ󬰦�F�z�����o�L�۹��A�K�L�q�o���F�A�u���o�۹�
���ث��Y�A�ݮݦp�͡A�{�p�����C

LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",1000);
  set("level",43);
  set("attitude", "heroism");
  set("limbs", ({ "�Y��", "����","�ݳ�","�ۮ�","�۸}","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",90);
  add("addition_damage",80);
  setup();
  carry_object(__DIR__"eq/eq3")->wear();
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
HIW+BLK"\n\t�i�Z�L�����j"+
NOR+WHT"�e�j���L�y�ۯ��z�ѵ��F"HIW +ob->name(1)+ NOR"�C\n\n",users());

   ob->add("popularity",1);
   ::die();
   return;
}
