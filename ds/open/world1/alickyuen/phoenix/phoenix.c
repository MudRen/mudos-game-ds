#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

mapping list = ([]);
string get = "";

int random_go();
string reply_ask();
void auto_kill(object me, object ob);

void create()
{
	set_name(HIR"�����"NOR, ({ "phoenix" }) );
	set("long",@LONG
�b�A���e���ʪ��o���e�M�����A�N�O�ǻ��������~��ġC�����W���O
���⪺�Ф�A�������U�N�۬��⪺���K�A�D�`�}�G�C����������|�X
�{�b�o...?
LONG
);
	set("title", HIY"�j���~"NOR );
        set("limbs", ({
		"�Y��",	"�V��",	"�ݤf",	"���",	"�y��",	"����",	"�j�L","����",
	}) );
	set("age", 50000);
	set("level", 70);
	set("exp", 0);
	set("max_hp", 40000);
	set("max_ap", 20000);
	set("max_mp", 20000);
        set("gender","����");
        set("race","monster");
        set("addition_armor", 105);
        set("addition_damage", 100);
        set("addition_shield", 10);
        set("Merits/wit", 8);
//        set("chat_chance", 1);
	set("chat_msg", ({
		(: return_home(load_object("/open/world1/cominging/area/boo-lin")) :),
	}));
//        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: random_go :),
       	 }) );
	set("can_speak", 1);
        set("inquiry/�i�h", (: reply_ask :) );
	set_temp("fly", 1); 
	//set("fly", 1);
        setup();
        set_temp("apply/armor",200);
        set_temp("apply/shield",200);
        set_temp("apply/damage",150);
	set_living_name("phoenix");
        call_out("test", random(16)+random(16));
	call_out("home", 900);
}

void die()
{
	object ob,env,*item;
	
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	env=environment(this_object());
	if(!env) return;
	item=all_inventory(env);
/*
	if( !ob )
	{
		::die();
		return;
	}
*/
	if( ob )
	{
	message("world:world1:vision",
		HIY"\n\t�j���~"HIW"["HIR"�����"HIW"]�Q"+ob->name()+"("+ob->query("id")+")���ѤF�I\n\n"NOR
	,users());
        ob->add("popularity", 10);
        tell_object(ob, HIY"�A�o��F 10 �I�n��C\n"NOR);
	} else {
	message("world:world1:vision",
                HIY"\n\t�j���~"HIW"["HIR"�����"HIW"]�Q���ѤF�I\n\n"NOR
	,users());
	}
	this_object()->set("hp", this_object()->query("max_hp") );
	this_object()->remove_all_killer();
	this_object()->set("no_kill", 1);
	this_object()->delete("chat_chance");
        this_object()->set("doll", random(2));
	this_object()->delete("can_speak");
	this_object()->query_list();
	command("tchat ��,�ڷ|��{���\\�D�ԹL�ڪ��i�̪��@���@��,�Чi���A�̪��@��a(reward)�C");
	call_out("timeout", 60, this_object());
	remove_call_out("test");
	remove_call_out("home");
	remove_call_out("auto_kill");
	return;
}

int receive_damage(string type, int damage, object who)
{
	object plume;

	if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
	if( type!="hp" && type!="mp" && type!="ap" )
		error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
	if( objectp(who) && type=="hp")
	{
		set_temp("last_damage_from", who);
                if( damage > 100 ) 
		{
                        if( userp(who) ) list[who->query("id")] += 1;
			plume = new(__DIR__"plume");
			plume->move(environment(this_object()));
		}
//                if( this_object()->is_busy() && random(10) >= 5 )
                if( !random(2) )
		{
                        message_vision("$N"HIW"��ı��$n�������A��M�V$n�o�X�����I\n\n"NOR, this_object(), who);
                        this_object()->add("addition_damage", 100);
			this_object()->special_attack(this_object(), who, 200);
                        this_object()->add("addition_damage", -100);
		}
	}

	::receive_damage(type, damage, who);
}

string query_list()
{
	string *id, msg;

	id = keys(list);
	msg = "";
	this_object()->delete("dollcount");
	foreach(string ppl in id)
	{
		msg += ppl+",";
		this_object()->add("dollcount", 1);
	}
	if( this_object()->query("dollcount") == 1 ) this_object()->delete("doll");

	if( sizeof(msg) ) return msg;
	else return "�L";
}
void special_attack(object me, object victim, int hitrole) //�ۭq�S����, ��npc��.
   /* special_attack(<obj>������,<obj>�����,<int>�R���p��)     */
{
	int damage;

        if( hitrole >= 135 )
	{
                damage = me->query_damage() + random(me->query_damage()) + random(me->query_damage()/4) - victim->query_armor();
		if( damage < 10 ) damage = 10;
                victim->receive_damage("hp", damage , me);
		message_vision("$N"NOR HIY"��M���l�j�O�@�ʡA�@�ڦФ�q�Ѧӭ��A�������V$n"NOR HIY"�����W�C("+damage+")\n"NOR, me, victim);
                victim->receive_wound("head", random(3));
                victim->receive_wound("body", random(3));
                victim->receive_wound("right_arm", random(3));
                victim->receive_wound("left_arm", random(3));
                victim->receive_wound("right_leg", random(3));
                victim->receive_wound("left_leg", random(3));
		me->receive_damage("mp", 20);
		me->receive_damage("ap", 20);
		COMBAT_D->report_status(victim);
		if( !random(10) )
		{
                        message_vision(HIM"\n(�@���p��)"HIR"$n��$N"HIR"�������X�ʦ̤����I�I�I\n\n"NOR, me, victim);
                        if( ( environment(victim) == load_object("/open/world1/cominging/area/boo-lin") ) || random(2) )
			{
				victim->move("/open/world1/tmr/area/hotel");
			} else victim->move("/open/world1/cominging/area/boo-lin");

			victim->start_busy(2);
			victim->remove_killer(me);
			me->remove_killer(victim);
		}
		// else
		if( !random(10) )
		{
			int time;
			time = 5+random(10)+random(10);
			victim->add_temp("conditions/blooding", time);
			victim->apply_condition("blooding", victim->query_condition("blooding") + time);
		}
	} else {
                message_vision("$N"NOR HIY"��M���l�j�O�@�ʡA�@�ڦФ�q�Ѧӭ��A�������V$n"NOR HIY"�����W�C(0)\n"NOR, me, victim);
                message_vision("�u��$N�T�V�a�׶}�F�C\n\n"NOR, victim);
	}
	me->kill_ob(victim);
	return;
}

void init()
{
	object me , ob;
	me = this_player();
	ob = this_object();

	if( !me ) return;

	add_action("do_reward", "reward");

	if( ob->query("no_kill") ) return;

	if( me->is_corpse() ) return;

	if( list[me->query("id")] )
	{
		ob->special_attack(ob, me, 300);
		return ;
	}

        if( (userp(me) && !wizardp(me) && me->query("level") > 30 && !ob->query("no_kill") && environment(me) == environment(ob)) || ( !userp(me) && !me->query("no_kill") ) ) 
		call_out("auto_kill", 1, me, ob);
}

void auto_kill(object me, object ob)
{
	if( ob->query("no_kill") ) return;
	{
//                ob->special_attack(ob, me, random(300));
//                command("kill "+me->query("id"));
                foreach(object item in all_inventory(me))
		{
			if( !item->query_autoload()
                        && strsrch(file_name(item), "open/world") != -1
			&& userp(me) )
				ob->add_temp("attackcheck", 1);
		}
                if( ob->query_temp("attackcheck") || !userp(me) )
		{
		message_vision(HIR"$N"HIR"��M�V$n�o�ʧ����I\n\n"NOR, ob, me);
		ob->kill_ob(me);
		}
	}
	ob->delete_temp("attackcheck");
	return;
}

void timeout(object ob)
{
	if( !ob ) ob = this_object();
	command("tchat �i�h�̡A�ڭn���F��");
	command("tchat* bye");
        find_living("phoenix_asker")->clean();
        find_living("phoenix_asker")->delete("pearl");
	destruct(ob);
	return;
}

int do_reward(string arg)
{
	object me;
	string id;

	me = this_player();
	id = this_player()->query("id");

	if( !this_object()->query("no_kill") )
		return 0;

    if( strsrch(get, id) != -1 )
        return notify_fail(this_object()->name()+"���G�C�H�u������@��.\n");

//        if( strsrch(this_object()->query_list(), id) == -1 )
    if( !list[id] ) 
        return notify_fail(this_object()->name()+"���G�A�èS���D�ԧڦ��\\�C\n");

    if( this_object()->query("dollcount") == 1 )
    {
        message("world:world1:vision", HIW"\t"+me->name()+"("+id+")�����F"+this_object()->name()+HIW"���W�ż��y.\n"NOR, users());
        me->add("popularity", 5);
        me->add("war_art", 10);
        me->add("exp", 100000);
        new("/open/always/phoenix_doll")->move(me);
        me->set("guild_rank", HIW"��D"HIY"���~"HIR"���"HIW"�i�h"NOR);
        map_delete(list, id);
        get+=id+", ";
        me->delete_temp("no_quit");
        timeout(this_object());
        return 1;
    }

	switch( arg )
	{
		case "popularity" : 
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")�����F"+this_object()->name()+HIW"�����y��\n"NOR, users());
                        me->add("popularity", 4);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
		case "exp" : 
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")�����F"+this_object()->name()+HIW"�����y��\n"NOR, users());
                        me->add("exp", 40000);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
		case "doll" :
			if( this_object()->query("doll") )
				return notify_fail(this_object()->name()+"���G�藍�_�Adoll�w�g�����F�C\n");
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")�����F"+this_object()->name()+HIW"�����y��\n"NOR, users());
              new("/open/always/phoenix_doll")->move(me);
			this_object()->set("doll", 1);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
		default:
		return notify_fail("�A�i�H�n�H�U�����y�G\n"+
                "(popularity)�G�n�梳�I\n"+
		"(combat)�G�԰����m�ע��������I\n"+
                "(exp)�G�g��Ȣ����������I\n"+
		"(doll)�G���������@��\n"+
		""NOR);
		break;
		case "combat" :
			message("world:world1:vision", HIW"\t"+me->name()+"("+id+")�����F"+this_object()->name()+HIW"�����y��\n"NOR, users());
			me->add("combat_exp", 1500);
			map_delete(list, id);
			get+=id+", ";
			me->delete_temp("no_quit");
			return 1;
		break;
	}


	return 1;
}
int random_go()
{
        object env;
        mapping exits;
        string *dirs;
        env=environment(this_object());
        if(!env) return 0;
        if( !mapp(exits = env->query("exits")) ) return 0;
        if( sizeof(exits) < 1 ) return 0; // �ץ��ж��S�X�f�ɤ�bug by -Acme-
        dirs = values(exits);
	message_vision(HIW"$N��M���������̭����F�C\n"NOR, this_object());
	this_object()->move(dirs[random(sizeof(dirs))]);
	return 1;
}
void test()
{
	remove_call_out("test");

	random_go();

        call_out("test", 25+random(6));
}
void home()
{
	remove_call_out("home");
	return_home(load_object("/open/world1/cominging/area/boo-lin"));
	call_out("home", 900);
	return;
}

mapping query_ppl()
{
	return list;
}
string reply_ask()
{
	return "�ȮɬD�ԧڦ��\\���i�h: "+this_object()->query_list();
}
