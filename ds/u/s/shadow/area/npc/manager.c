/**
 *	Shadow's mob - �޲z��
 */
#include <ansi.h>
inherit NPC;

void create()
{
	set_name( "�޲z��", ({ "graveyard manager", "manager" }) );
	set("level", 30);
	set_skill("dodge", 80);
	set_skill("unarmed", 100);
	set_skill("combat", 100);
	
	set("long", @LONG
    �@�ө_�Ǫ����Y�A�b���������H�Y�֤@�_�o�¡C�ӤW���ۤ@��
�w�g�ͺ��F�ê��S�Y�A���W����A�P�Y�W��������g���F���g�A���A
�p�Q����G�o�_�Ǫ����Y�O��q�g�̪��X�Ӫ��Pı�I
LONG
	);
	set("title", HIG"�q��"NOR);
	set("age", 83);
	set("evil", 0);
	set("attitude", "killer");
	set("chat_chance_combat", 15);
	set("chat_msg_combat",({
		HIG"�q���޲z�����L���a��ۧA��\n"NOR,
		(: command("ghost") :),
	}));
	
	setup();
	add_money("coin", 800);
	set_living_name("GraveyardWar");
}

void init()
{
	::init();
	if(!this_object()->visible(this_player())) return;
}

void die()
{
	object ob, ghost, room, env, npc;
	if( !ob = query_temp("last_damage_from") )	ob = this_player(1);
	if( !ob ) {
		::die();
		return;
	}
	::die();
	return;
}
