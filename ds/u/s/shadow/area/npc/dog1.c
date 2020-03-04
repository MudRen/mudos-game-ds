/**
 *	Shadow's mob - ���ͤ�
 */
#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "���ͤ�", ({ "eat-corpse dog", "dog"}) );
	set("race", "���~");

	set("level", 10+random(5));
	set_skill("dodge", 80+random(20));
	set_skill("unarmed", 70);
	set_skill("combat", 60);
	set_temp("apply/armor", 200);     /* ���[���z�ʨ��@�O */
	set("limbs", ({ "�Y��", "����", "�e�}", "��}" }) ); 
	set("verbs", ({ "bite"}) );  /* �����覡: �r*/

	set("long", @LONG
    �@�Y���r���c���A���j�����߻P�a�����p���[���O�C�Ѻ񪺲��]
�z�S�X�X���޲��A�L���٥p�ۤ@�ڤH���Ⱙ�A�a����񪺤������`�y
�U�A�Y�Q�r�W�@�f�֩w�|�Y�����I
LONG
	);
	set("title", HIY"�ø��^"NOR);
	set("age", 5+random(5));
	set("evil", 3+random(3));
	set("chat_chance", 4);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("attitude", "killer");
	set("chat_chance_combat", 15);
	
	setup();
	set_living_name("GraveyardWar");
}

void init()
{
	::init();
	if(!this_object()->visible(this_player())) return;
	if(this_player()->query("level") > 10 && userp(this_player()))
		this_object()->kill_ob(this_player());
}

void die()
{
	int i;
	object ob;
	if( !ob = query_temp("last_damage_from") )	ob = this_player(1);
	if( !ob ) {
		::die();
		return;
	}
	::die();
	return;
}
