// Last Modified by winder on Apr. 25 2001
// pi4.c �t�N �ժꤺ��
#include <ansi.h>
  inherit NPC;
  
  void create()
  {
      set_name("�t�N", ({ "pi jiang", "pi", "jiang" }));
      set("gender", "�k��");
      set("age", random(10) + 30);
      set("str", 25);
      set("dex", 16);
      set("long", "�o�O�@�Ӥj���~���N��A���y���СC\n");
      set("combat_exp", 45000);
      set("shen_type", 1);
      set("attitude", "peaceful");
  
      set_skill("unarmed", 60);
      set_skill("force", 60);
      set_skill("sword", 60);
      set_skill("dodge", 60);
      set_skill("parry", 60);
      set_temp("apply/attack", 50);
      set_temp("apply/defense", 50);
      set_temp("apply/armor", 50);
      set_temp("apply/damage", 30);
  
      set("neili", 400);
      set("max_neili", 400);
      set("jiali", 10);
  
      setup();
  //    carry_object("/d/city/obj/changjian")->wield();
//      carry_object("/d/city/obj/tiejia")->wear();

}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("guosc_mis_flag")==2)
	{
		say("�t�N�K�F�K�ܡG�o��" + RANK_D->query_respect(ob) + "�A�A�٬O�w�ߦu���a�C\n");
	}	
	else if(ob->query_temp("guosc_mis_flag")==1)
	{
		say("�t�N���⻡�D�G�o��" + RANK_D->query_respect(ob) + "�A�A�ӱo���O�ɭԡA�X�j�ޤl�w�g�֧�W���F�C\n");
	}
	if(ob->query_temp("guosc_mis_flag")==3)
	{
		say("�t�N���⻡�D�G�o��" + RANK_D->query_respect(ob) + "�A�A�w�g�i�H�^�h�ЩR�F�C\n");
		return;
	}
}
