// �o�]�⮣�ƪ� mob ���@, ���I�G�ٱj�\�h
// �L���W�a�F�@�ӭ����ʪ�����, �H�����a�ί��O�� hest �L�h���C�����s
// wilfred@DS  :Q~~~~~~

#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIR"�u����"HIW""BLK"���s"NOR,({"red-eye black dragon","dragon"}) );
  set("long",
HIR"\n�����������A���ª����ߡA�i���R���A���G�b�D���ۨe������\n"
HIR"\n��󲴫e���@���A�e���G�u�s�b�ۤ@�ө��Y\n"
HIR"\n\t\t��������\n\n"NOR
);
  set("race", "dragon");
  set("unit","��");
  set("age",500);
  set("level",60);
  set("attitude", "heroism");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","����","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("addition_armor",80);
  set("addition_damage",80);
  set("Merits/wit",3);
  set("Merits/bar",9);
  set("Merits/bio",5);
  add("apply/hit",50);
  setup();
  set_living_name("dragon_war");
  carry_object(__DIR__"wp/wp9")->wield();
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
   ob->add_temp("hero",3);
   ob->add("popularity",3);
   tell_object(ob,HIC"[�A�o���B�~�� 3 �I�n��!!]\n"NOR);
   ::die();
   return;
}

