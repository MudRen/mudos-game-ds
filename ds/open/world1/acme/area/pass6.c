// Room: /u/a/acme/area/pass6.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O�Ѥs���s�}�U�A���Ѥs�����ӥh���O�@���T�򪺤s���A�C�Ѫ�
�Ѥs�A������h�A�O�H���m���ɡA�u�Q�b���h�ݤ@�|�A�@�@�o���������s
�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : COMINGING_PAST"area/river3.c" ,
  "eastup" : __DIR__"pass5",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
