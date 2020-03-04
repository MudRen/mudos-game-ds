#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N�i�j�L�ڥΦy����$n��$l�r�r",
		"attact_type":  "bar",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"�r��",
	]),
	([	"action":		"$N�ĤO��$n��$l���F�L�h",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
	([	"action":		"$N�R�X�ĲG���$n��$l�g�F�L�h",
		"attact_type":  "bio",
		"damage_type":	"�G�k",
	]),
	([	"action":		"$N�@���ਭ�A���j�����ڱۭ��몺���V$n��$l",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
});

void do_clean();

void create()
{
         set_name( CYN "����" NOR,({"huge rat", "rat" }) );
	set("long",@LONG

  �e�N�O�ǻ��������j�չ��C�e���髬��H�ٰ��j�A�L�ڸ̪��T���y
���N���_�C�@��U�Q�C�Q���p���ԷV���e�A���`�ä��|�X�{�b���H��
�a��A���b���\�h�U�����a�谸�ӷ|���H�ݨ�e�C�ǻ��Ҧ����ѹ���
�|ť�q�e�������ҥH�H�̤S�٥L���y�����z�C

LONG
);
        set("title","�]�~");
        set("limbs", ({
		"�Y��",	"�V��",	"�ݤf",	"���",	"�y��",	"����",	"�y��","����",
	}) );
        set("age",100+random(99));
        set("level",43);
        set("int",48);
        set("gender","�۩�");
        set("race","monster");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"�����Q�F�Q�e�}�C\n",
    "�������{�l���G�V�ӶV�j�F�C\n",
}));
	set_skill("mob_bite", 72);
	set_skill("dodge", 77);
	set("addition_armor",62);
	add("apply/hit",70);
	set("addition_damage",69);
        set("chat_chance_combat", 38);
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
	  	message_vision("$N��M���F�Ӧa�}, ���t���p�F�i�h�C\n",ob);
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
	CYN"\n  [�����Y���s�D] �ǻ����������Q"+ob->name(1)+"�����F�C\n\n"+NOR
	,users());
	ob->add("popularity",1); //�n��
	::die();
	//destruct(this_object());
	return;
}
