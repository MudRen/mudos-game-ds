inherit ROOM;
void create()
{
	set("short", "�B�F����j���e");
	set("long",@LONG
�o�̬O��j�����e���A�b�o�̦��\�\�h�h���ȫȨӨө����A���Ʀn
����F�j���٭n�z���ˤl�A�b�����Ǧ��@�Ӧu�ö�A���L�n�������H�H
�K�K���N�i�h���ˤl�A����N�O��j���F�A�ӪF��h�O�B�F��������j
��W�C
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest4.c",
  "west" : __DIR__"bdoor3.c",
]));
	set("objects",([
  __DIR__"npc/traveller.c": 3,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("�A�٦b����I\n");
	message_vision("$N���}�F�u�ö�U���@�����A�M�᰽���N�N���i�F�h�C\n",me);
	me->move(__DIR__"tower.c");
	return 1;
}