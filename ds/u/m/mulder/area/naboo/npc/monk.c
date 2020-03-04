#include <ansi.h>
inherit NPC;
inherit SSERVER;
void cast_fireball();

void create()
{
	set_name(HIW"�צ��"NOR,({"monk"}) );
	set("long","�@�Ө�U�t�z�צ檺�צ�̡C\n");
	set("age",30);
	set("level",40);
	set("race","�H��");
	set("evil",-30);
	set("exp_point",4);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("smile"):),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 65);
	set("chat_msg_combat", ({
		(: cast_fireball :),
	}) );
	set_skill("dodge",70);
	set_skill("block",50);
	set_skill("parry",35);
	set_skill("unarmed",50);

	setup();

}

void cast_fireball()
{
	object ob,me;
	int damage,c;

	me = this_object();

	ob = offensive_target(me);
	if(!ob) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",30);
	message_vision("\n"+ob->query("name")+"�Į�a���A����n�G�ڥX��O�H\n");


	tell_room(environment(me),"\n"+me->query("name")+"��M���l����h�F�@�B\n");
	tell_room(environment(me),"\n�A�J���ݨ�L�⤤�B�{�X�@�ӹ�"HIR"���y"NOR"������\n");

	if( ob->query_int() < random(150) )
	{
	    ob->add_busy(2);
	    message_vision(HIR"\n$N�Pı���@�ؤ������w�P�N�|�o�͡C\n",ob);
	    damage = random(100)+query_int()*3;
	    damage = damage/2+random(damage/2);
	    c=ob->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,ob,damage,"dodge");
	    ob->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n�uť��$N�@�n�G�s�A$N�k���F���y�����աA$N����Ө���Q���y�]���C\n"NOR,ob);
	    else
		message_vision(HIW"\n$N���{�k�פ~���׹L�o�Ӷլ�����"HIR"���y�C\n"NOR,ob);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(ob->query_temp("apply/show_damage") || ob->query_temp("show_damage") )
	        tell_object(ob,HIR"("+damage+")"NOR+" ("+ob->query("hp")+"/"+ob->query("max_hp")+")");
	    message_vision("\n",ob);
	    if(wizardp(ob) && ob->query("env/debug"))
	        tell_object(ob,"  �y��"+damage+"�I�ˮ`!!\n"); 
	    COMBAT_D->report_status(ob);	

	}
	else message_vision("\n���y���V$N���ɡA���ϳQ$N�}�ѤF�C\n",ob);

 	me->start_busy(1);

}