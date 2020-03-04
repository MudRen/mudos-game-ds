#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N�i�j�L�ک�$n��$l�r�r",
		"attact_type":  "bar",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"�r��",
	]),
	([	"action":		"$N�ĤO��$n��$l���F�L�h",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
	([	"action":		"$N�R�X�����G�Ĺ��$n��$l�Q�F�L�h",
		"attact_type":  "bio",
		"damage_type":	"�G�k",
	]),
	([	"action":		"$N�i�}�j�L���$n��$l�R�X�@��U��",
		"attact_type":  "bar",
		"damage_type":	"����",
	]),
});

void do_clean();

void create()
{
        set_name("���l",({"yeah chuay", "yeah","chuay" }) );
	set("long",@LONG

  �e�N�O�ǻ������]�~���l, �~��ݰ_�ӹ��O�@�����j���I, ���j��
�L�کP���S�F�n�X�h�������C�e���ʱ��Q���ũM, ���{�l�o�û���
���C���ӷ|�X�{�b���\�h�U�����a��, ���g���H�ݹL�e�b�@�Ѥ�����
�@��y�s���U���Y�o�����b�b, �ҥH�H�̤S�٥L���y�����Ρz�C

LONG
);
        set("title","�]�~");
        set("limbs", ({
		"�Y��",	"�V��",	"�ݤf",	"���",	"�y��",	"����",	"�j�L","����",
	}) );
        set("age",500+random(99));
        set("level",40);
        set("dex",58);
        set("gender","����");
        set("race","monster");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"���l�Q�F�Q�L�B, �w�w���|�Bį�ʡC\n",
  	"���l��������G�V�ӶV�j�F�C\n",
}));
	set("addition_armor",50);
	set_skill("mob_bite", 64);
	set_skill("dodge", 37);
	set("addition_armor",62);
	add("apply/hit",50);
	set("addition_damage",58);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
	          (: do_clean :),
       	 }) );
	set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
	carry_object(__DIR__"eq/sacer_armor.c")->wear();
}

void do_clean()
{
        object ob,env,*item,obj;
        int i,k=0;

	ob=this_object();
	if(!ob) return;
	if( ob->is_busy() ) return;
	env=environment(ob);
	if(!env) return;
	item=all_inventory(env);
	if(sizeof(item)>1)
	{
	 for(i=0;i<sizeof(item);i++)
	 {
          if( living(item[i]) && userp(item[i])) continue;
          if(item[i]->query("no_get")) continue;
        if(item[i]->query("id") == "yeah chuay" ) continue;
	  k++;
	 }
	 if(k>1)
	 {
	  obj=item[random(sizeof(item))];
          if(living(obj) && userp(obj)) return;
	  else if(obj->query("no_get")) return;
        else if(obj->query("id") =="yeah chuay" ) return;
	  message_vision("$N�i�}�j�L��$n�]�i�F�L�̡C\n",ob,obj);
	  ob->receive_heal("hp",1+random(30));
	  destruct(obj);
	 } else 
	 {
	  	message_vision("$N��M��������, �w�w���p�i�F�a���C\n",ob);
	  	destruct(this_object());
	 }
	}
	return;
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void die()
{
	object ob,env,*item;
	int i;
	
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	env=environment(this_object());
	if(!env) return;
	item=all_inventory(env);
	for(i=0;i<sizeof(item)/2;i++)
	{
	  if(item[i]->is_character()) continue;
	  if(item[i]->query("no_get")) continue;
	  destruct(item[i]);
	}
	message_vision("  $N�γ̫᪺�O��@�f��]�U�F����j�b���F��C\n",this_object());
	if( !ob )
	{
		::die();
		return;
	}
	message("world:world1:vision",
	CYN"\n  [�p�D����] �ǻ������]�~���l�Q"+ob->name(1)+"�����F�C\n\n"+NOR
	,users());
	ob->add("popularity",1); //�n��
	::die();
	//destruct(this_object());
	return;
}
