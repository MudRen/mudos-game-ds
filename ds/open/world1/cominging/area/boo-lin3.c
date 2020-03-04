#include <ansi.h>
inherit MOBROOM;
void create()
{
	set("short", "�B�F���n�j��_");
	set("long",
"�A���b�B�F�����n�j��A�b�o�̦��\\�h���צb�a�W���^���A�L�̥�\n"
"�b�V�H�^�Q�F��Y�A�b�_��O�B�F�������������A�b�����\\�h�F��i�H\n"
"�ʶR�A�Ӧb�o�̪����񦳤@�a�s�}���Z�����Ať���̭��檺�F�躡�Q��\n"
"���O�o�֦��۷��W�n�A�s�B�F���çL���������|�쨺�ʶR���~�A�b�o\n"
"���n��O�B�F�����n�j��A���̦���j���s���A�]���ܦh���H�A�b�o��\n"
"�����䦳�@���p���A���G�u���H�ϡC\n"
	);
	set("exits", ([
  "north" : __DIR__"boo-lin2.c",
  "south" : __DIR__"bsouth.c",
  "east" : __DIR__"weapon.c",
]));
	set("item_desc",([
  "�p��" : "�@���u���H�g�L���p���A�b�����G���@��������C\n",
  "road" : "�@���u���H�g�L���p���A�b�����G���@��������C\n",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me,sidestreet;
	me = this_player();
	sidestreet = load_object(__DIR__"sidestreet4.c");
	if( !arg )return notify_fail("�A�n�i�J���r�H\n");
	if( arg!="road" && arg!="�p��" )
		return notify_fail("�A�n�i�J���r�H\n");
	else
	{
		tell_room(environment(me),me->name()+"���p���̨��h�C\n",({ me }));
		me->move(sidestreet);
		tell_room(environment(me),me->name()+"���F�i�ӡC\n",({ me }));
		return 1;
	}
}