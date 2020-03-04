// �� �@�볥�~
inherit NPC;

void create()
{
	set_name("����", ({ "dog" }) );
	set("race", "���~");
	set("age", 3);
	set("level",2);

        set("long", "�@������ż�����������A�ݤF�O�H�ͼ��C\n");
	
	set("str",1);
	set("max_hp",10);
	set("dex",-3);
	set("int",1);
	set("con",1);

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�����λ�l�D�F�D�A���}�C\n",
		"�����b�A���}������������M�Q�Q�F��Y�C\n",
		"������ۧA�n�F�n���ڡC\n",
		"�����Ϋ�L��F��ۤv���զ��C\n" }) );
		

	setup();
}


int accept_object(object who, object ob)
{
	if( ob->id("bone") || ob->is_food())
	{
		set_leader(who);
		message("vision", name() + "�ܧ֪��Y���F"+ob->name(1)+", �����a�L�L�s�F�_�ӡC\n", environment());
		destruct(ob);
		return 1;
	}
}

// ���� ���S�𪺳��~(1) (�S���O�S�𪺼g�k)


inherit NPC;

void create()
{
	set_name("��j��", ({"dark spider","spider"}) );
	set("long", "�@���¦⪺�j�j��A�o�ػj�藍�����ӬO�a�r�������y���C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" })); //���𳡦�
	set("verbs", ({ "bite","claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 10);
	set("level",19);
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));

	setup();

}

int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIW"$N���X�r�����$n�@�}�ër�A"NOR,me,victim);
	if(hitrole > 100)
	{
		victim->->apply_condition("posion", target->query_condition("posion")+3);
		message_vision(HIW"$n�{�����ΦӳQ�r���A�y��o���C"NOR,me,victim);
		victim->receive_damage("hp",20+random(20),me);
		return 1;
	}
	else message_vision(HIW"���Q$n��ĵ���{�F�L�h�C"NOR,me,victim);
	return 1;
}


// ������ ���S�𪺳��~(2) (�ޯড���S��g�k) 


inherit NPC;
inherit SSERVER;
void create()
{
	set_name("�H���j��", ({"face pattern spider","spider"}) );
	set("long", "�@���I�����ۤH���᯾�����j�j��A��������઺���ۧA�C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" })); //���𳡦�
	set("verbs", ({ "bite","claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 6);
	set("level",13);
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));
        set("chat_chance_combat", 20); //�԰��ʧ@���v
        set("chat_msg_combat", ({
	        (: this_object(), "random_move" :),
	        (: do_hold :),
	        (: do_hold :),
       	 }) );
	setup();

}

void do_hold()
{
	object me,victim;
	me=this_object();
	if(!me ) return;
	if(!me->is_fighting()) return;
	victim=offensive_target(me);
	if(!victim) return;
	
	message_vision(HIW"$N��$n�R�X�@���H�G�A"NOR,me,victim);
	if(random(victim->query_dex()*3+victim->query_skill("dodge")) < random(200))
	{
		message_vision(HIW"$n�{�����ΦӳQ�H�G�Q���A�ʼu���o�C"NOR,me,victim);
		victim->start_busy(2);
		return 1;
	}
	else message_vision(HIW"���Q$n��ĵ���{�F�L�h�C"NOR,me,victim);
	return 1;
}


// ���������� �����ʧ@�����~(�S�𳡤��g��npc�M�Χޯ�)

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
        set("race","���]");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"���l�Q�F�Q�L�B, �w�w���|�Bį�ʡC\n",
  	"���l��������G�V�ӶV�j�F�C\n",
}));
	set_skill("mob_bite", 64);
	set_skill("dodge", 37);
	set("addition_armor",42);
	set("addition_damage",48);
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
	::die();
	//destruct(this_object());
	return;
}