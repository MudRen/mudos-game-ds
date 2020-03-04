inherit ROOM;

void create()
{
	set("short", "�˪L��");
	set("long", @LONG
�A�{�b�b�˪L�����A�b�o�̪���U���ۭZ������Ĭ������M�@�ǥi
���������Ӫ��A�A�Y�O�j�F�]�i�H�Ķ��@�ǤU�ӭ��ΡA�A�]�ݨ�F�o��
�񦳤@�Ǳ��ĵ��b�ĺK��G�A�o����L�Z���A�餣���ѡA�D�n�ɤH�A��
���B��e����D�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"fgo2.c",
  "west" : __DIR__"fgo4.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(5),
]));
	set("item_desc",([
  "��Ĭ������" : "�@�د��Ӫ�, �A�i�H�K(pick)�U�ӬݬݡC\n",
]));
	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object me=this_player(),flower;
	flower = new(__DIR__"npc/obj/gsflower.c");
	if( arg !="gei-su flower" && arg !="��Ĭ������" )
		return notify_fail("�A�n�K����F��r�H\n");
	else if( !me->query_temp("rflower")) {
		message_vision("$N�Τ���U����Ĭ������K�F�@���_�ӡC\n",me);
		me->set_temp("rflower",1);
		flower->move(me);
	} else {
		message_vision("$N�Q�Τ�K�_��Ĭ������A�S�ƫo�����䪺�ᵹ��F�C\n",me);
		me->receive_damage("hp",1);
	}
	return 1;
}