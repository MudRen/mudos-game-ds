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
        set("gender","����");
        set("race","���]");
        set("chat_chance", 40);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"���l�Q�F�Q�L�B, �w�w���|�Bį�ʡC\n",
  	"���l��������G�V�ӶV�j�F�C\n",
}));
	set_skill("mob_bite", 60);
	set("addition_armor",60);
	set("addition_damage",60);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
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
	if( ob->is_fighting() ) return;
	if( ob->is_busy() ) return;
	env=environment(ob);
	if(!env) return;
	item=all_inventory(env);
	if(sizeof(item)>1)
	{
	 for(i=0;i<sizeof(item);i++)
	 {
	  if(item[i]->is_character()) continue;
	  if(item[i]->query("no_get")) continue;
	  k++;
	 }
	 if(k>1)
	 {
	  obj=item[random(sizeof(item))];
	  if(obj->is_character()) return;
	  else if(obj->query("no_get")) return;
	  message_vision("$N�i�}�j�L��$n�]�i�F�L�̡C\n",ob,obj);
	  ob->start_busy(2);
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
