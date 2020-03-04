#include <ansi2.h>

inherit NPC;

void create()
{
	set_name(HIR"����ѤH"NOR, ({ "red cloth old man", "man" }));
	set("level", 50);
	set("max_hp", 50000);
	set("max_ap", 50000);
	set("max_mp", 50000);
	set("str", 500);
	set("age", 5134);

	set("long", @long
�b�A���e���o�@��O�@�Ӻ�������۫p�p�������۪��H�A�L������
���A�@�طŷx���Pı�C
long);

	setup();
	add_money("silver", 100);
}

void init()
{
	object me, bag;

	me = this_player();

	if( !me ) return;

	if( !userp(me) ) return;

	if( !objectp(present("xmas2001", me)) )
	{
		bag = new(__DIR__"obj/bag");
		bag->move(this_object());
		command("say �~���H,�Ӱѥ[�Ƴ������ɪ����a.\n");
		command("say �o�̪��񦳭Ӥp�˪L,�A���h���@�Ǥ��Y�^��\n");
		command("say �ڴN�����A�����쳷��,�A�N�γo�Ӥj�U�a���Y�a.\n");
		command("give bag to "+me->query("id"));
	}
	command("smile");
}