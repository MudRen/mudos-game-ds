#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�츭�p��"NOR);
	set("long", @LONG

�o�̬O�e�����������@���ȩСA�b�o�̦��@�Ǫ��ǹСA��O�W�]��
�Ǿ���A���E���\�Τ��A�O���A���A���p��~�P�ҡA�|�P��W�D�F�X��
�֡A�]���F�X�T�W�e�A��ֱ��e�N���ˤl�A���p��W�A�b�p�٤����A��
�ɦ��Ǳq�~����W�����ƶi�Τ��A�]�����X���ʪ��b����̨Ӯ̥h�A
��y�v���ˤl�C

LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry20.c",
]));
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
	object me=this_player();
	if( arg!="�W�e" )return 0;
	else {
		message_vision("$N���F���@�U�W�e�A���G�����n���ǨӡC\n",me);
		return 1;
	}
}