/**
 *	Shadow's mob - ����k��
 */
#include <ansi.h>
#define SHADOW_GRAVEYARD "/u/s/shadow/area/"

inherit NPC;

void create()
{
	set_name(HIR"����k��"NOR, ({ "red-cloth ghost", "ghost" }) );
	set("level", 50);		
	set("long", @LONG
    ���Y���v�A���W�ܵۤ@ŧ�w�Ʀ�j�����m���k���C�s�誺����
���ϩ��D���ͫe���ۻ����ɪ��s�}�C���H�Y���������{�{�A��r����
�����A���H�ӷX�A���G�n�N�A�ͧ]������a�I
LONG
	);
	set("title", HIG"�q��"NOR);
	set("age", 83);
	set("evil", 0);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("combat", 100);
	
	set("chat_chance_combat", 15);
	set("chat_msg_combat",({
		HIR"����k�����Ҭ�M�ɪ��A�V�A�ƨg�����C\n"NOR,
		HIR"����k����M���Y�v���A����}�A���A�ʼu���o�C\n"NOR,
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
	int i;
	object ob, room;
	if( !ob = query_temp("last_damage_from") )	ob = this_player(1);
	if( !ob ) {
		::die();
		return;
	}
	ob->add("popularity", 3);
	message("world:world1:vision", HIR"\n\t����k�����"+ob->name(1)+HIR+"�y�s�R�q �� "+" �� �n �� �� ��\n\n"NOR, users());

	/* �}�ү��� south �X�f & recall */
	room = load_object(SHADOW_GRAVEYARD"graveyard23");
	room->set("no_recall", 0);
	room->set("exits",([
		"south": SHADOW_GRAVEYARD"graveyard22",
	]));
	
	::die();
	return;
}
