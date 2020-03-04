// support.c

#include <ansi.h>
#include <dbase.h>
#include <localtime.h>
#include <skill.h>
#include <type.h>

inherit CHARACTER;
inherit F_CLEAN_UP;	// Only to clean up master copy of NPCs.

static mixed next_chat;
static int last_scheduled_time_tag = 0;

int chat();

void heart_beat()
{
	mapping schedule;

	if( living(this_object()) && !is_busy() ) {
		chat();
		if( !this_object() ) return;
	}

	if( living(this_object())
	&& clonep(this_object())
	&& mapp(schedule = query("schedule")) ) {
		mapping gt;
		int time_tag;

		gt = NATURE_D->game_time(1);
		time_tag = gt[LT_HOUR] * 100 + (gt[LT_MIN] / 10) * 10;
		if( time_tag != last_scheduled_time_tag ) {
			evaluate(schedule[time_tag]);
			last_scheduled_time_tag = time_tag;
		}
		if( !this_object() ) return;
	}

	::heart_beat();
}

void die()
{
	object ob;
	mapping bounty;

	::die();
	if( (ob = query_temp("last_damage_from"))
	&&	(ob != this_object())
	&&	(bounty = query("bounty")) ) {
		string score;
		int amount;

		foreach(score, amount in bounty)
			ob->gain_score(score, amount);
	}
}

mixed carry_object(string file)
{
	object ob;

	// Don't let master copy clone equips
	if( !clonep() ) return VOID_OB;

	if( !objectp(ob = new(file)) ) return 0;

	// Support of uniqueness.
	if( ob->violate_unique() ) ob = ob->create_replica();
	if( !ob ) return VOID_OB;

	ob->move(this_object());
	return ob;
}

object carry_money(string type, int amount)
{
	object ob;

	ob = carry_object("/obj/money/" + type);
	if( !ob ) return 0;
	ob->set_amount(amount);
}

int is_chatting() { return functionp(next_chat)!=0; }

void do_chat(mixed c) { next_chat = c; }

mixed eval_chat(mixed chat)
{
	mixed ret;

	chat = evaluate(chat);
	switch(typeof(chat)) {
		case STRING:
			say(CYN + chat + NOR);
			return 0;
		case ARRAY:
			if( !sizeof(chat) ) return 0;
			chat[0] =  eval_chat(chat[0]);
			return chat - ({ 0 });
		case FUNCTION:
			return chat;
		default:
			return 0;
	}
}

int chat()
{
	string *msg;
	mixed ret;
	int chance, rnd;

	if( !environment() ) return 0;

	// Evaluate programmed chat first.
	if( next_chat ) {
		next_chat = eval_chat(next_chat);
		return 1;
	}

	// Else, do random chat if any.
	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( random(100) > chance ) return 0;
		rnd = random(sizeof(msg));
		if( stringp(msg[rnd]) )
			say(CYN + msg[rnd] + NOR);
		else if( functionp(msg[rnd]) )
			evaluate(msg[rnd]);
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
	mapping exits;
	string *dirs;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
	string spell_skill;

	if( stringp(spell_skill = skill_mapped("spells")))
		SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	string force_skill;

	if( stringp(force_skill = skill_mapped("force")))
		SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
	object weapon;
	string martial_skill, act;

	if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
		return 0;
	martial_skill = skill_mapped(martial_skill);
	if( stringp(martial_skill) )
		return SKILL_D(martial_skill)->perform_action(this_object(), act);		
}

