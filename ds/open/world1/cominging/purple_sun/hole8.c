// �����s���ݤs�}��
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A�{�b���b�s�}���A�o�̸��褣�P���O�A���X�ӦѤH���b�@����
�������䪺�p�۹��W�A�C�ӤH�������A�����O�~���w�����H�A�L�̪�
�y�W��������G�����n�A�b�A���}�U���\�h�p�p�������Y�A��P��
�a�誺�٭n�h�X�\�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hole7.c",
  "south" : __DIR__"hole5.c",
  "east" : __DIR__"hole9.c",
]));
	set("item_desc", ([
  "�۾�" : "�@���ܤj���۾��A�����٦��Ǥp���_�A���G�ݰ_�Ӧ�����@�ΡC\n",
]));
	set("objects", ([
  __DIR__"npc/oldman.c" :1,
  __DIR__"npc/oldman2.c" :1,
  __DIR__"npc/oldman3.c" :1,
  __DIR__"npc/oldman4.c" :1,
]));
	set("no_fight",1);
	set("no_cast",1);
	set("no_exert", 1);
	set("no_steal", 1);
	set("world", "past");
	set("no_clean_up", 0);
	set("light",1);

	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if( arg != "�۾�" && arg != "stone" )
		return 0;
	if( !me->query_temp("open_stone_door") )
	{
		message_vision(HIW"$N�ϫl���ʥ۾��A�o���۾��@�ʤ]���ʡC\n"NOR,me);
		return 1;
	}
	message_vision(HIW"$N�ϫl���ʥ۾��A�u���۾��Ƿ����@�_�A��ӤH��½�F�L�h�C\n"NOR,me);
	me->move(__DIR__"4f_secret.c");
	tell_room(environment(me), "�u���۾��@�}�̰ʡA"+me->name()+"��M�X�{�b�o�̡I\n", ({ me }));
	me->start_busy(1);
	if( me->query_temp("open_stone_door") > 0 ) me->add_temp("open_stone_door", -1);
	else me->delete_temp("open_stone_door");
	return 1;
}
