#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�˪L�~��");
	set("long",@LONG
�o�̬O�B�F���n�誺�j�˪L���_��A�A���G�i�H�ݨ��˪L���j���
�ѡA���y�᭻���ˤl�Ať�B�F�������H�Ҩ��A�b�������ǻ��b�ߤW�ɡA
�|���\�h�����W���H�b���̡A�����H�Q�m�T�L�A�b�_��O�B�F���~���@
���e�A�b�o���n��O���˪L���ӥh�C
LONG
	);
	set("exits", ([
  "southwest" : __DIR__"forest2.c",
  "north" : __DIR__"river.c",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
