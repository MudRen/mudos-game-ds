// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIB "�µL�`���D�R�ޡT�s�Ӫ��M�A�s����W�r�S\n\n" NOR,
	HIB "�µL�`�Ω_���������n�ۧA�M�n���n�ݬ�A���@�������C\n\n" NOR,
	HIB "�µL�`�u��v���@�n�M�q�S���ǥX�@�����b�U���F��½�ݵۡC\n\n" NOR,
	HIB "�µL�`�פW�U�l�M���D�R�x�S���إ��ɡS���i��S\n\n" NOR,
	HIB "�µL�`�k�F�k�Y�M�۹D�R�}�F�}�F�M�A���a�C\n\n"
		"�@�ѳ��N���@����M�X�{�M�ܧ֦a�]��F�A�C\n\n" NOR,
});

void create()
{
	set_name("�µL�`", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"�µL�`���۪��������Y���ۧA�M�K�ª��y�W�ݤ��X����߫�s�֡C\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
		"�µL�`�o�X�@�}���D�u���n���M��L�o�{�A���`���ۥL���ɭԡM���F�A�@���C\n",
		"�µL�`����������Y���X�ӡM�w�w�a�Q�F�Q�ۤv�S�¤S��������C\n"
	}) );
	set("age", 217);
	set("level", 99);
	set("combat_exp", 20000);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) ) return;

	if( !ob->is_ghost() ) {
		command("say �ޡT���H�ӳ���������S");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	ob->move(REVIVE_ROOM);
	message("vision",
		"�A���M�o�{�e���h�F�@�ӤH�v�M���L���H�v�S�n���w�g�b����\n"
		"�ܤ[�F�M�u�O�A�@���S�oı�C\n", environment(ob), ob);
}


