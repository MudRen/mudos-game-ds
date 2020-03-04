#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�u�ö�U");
	set("long", @LONG

�A�p���l�l���i�ӤF�o�Ӧu�ö𪺤U��A�o�̦��\�h�������M����
�A�i�H�ѵ����U�^���h�L�𮧤��ΡA�٦��ǧ��E�A�W�����@���j�ֳQ�A
�i�H���çL�̷������ΡA�o�̬O�@�Ӷ��������p�a��A�|�P���O�Υ��Y
�Ұ������۾��A�W���ٱ��ۨǪo�O�C

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"tower_2.c",
  "out" : __DIR__"bwest5.c",
  "north" : __DIR__"lav.c",
]));
	set("objects",([
  __DIR__"npc/t_guard.c": 1,
]));
	set("item_desc",([
  "����" : "�@�ǥβ����˰_�Ӫ����A�ݰ_�ӫܲM���A����ܦn�C\n",
  "����" : "�o�ǭ����D�n�O���C�Y�զ����A��b���W�A����N�O�@�����������C\n",
  "���E" : "�o�O�@�Ӧ˰������E�A�W���Q�@���j�ֳQ�A�񪺨ä�������A�n�����H��ιL���ˤl�C\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	set("level","tower_1");
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if( dir=="north" )
		tell_object(me,YEL"�A���G�D��F�ǩǩǪ�����Ǩ�A�󤤡C\n"NOR);

	return ::valid_leave(me, dir);
}