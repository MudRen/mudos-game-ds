#include <path.h>
inherit ROOM;
void create()
{
	set("short", "�¦�p�D��");
	set("long", @LONG
�A�����b�@���¦⪺�p�D���W�A�P�򪺭����º������A�s�b�դѳ�
�|�Q�ѤѪ��j��쵹�B�����A�b��_�観�@���դj���s���A�j���N�O
�ǻ����Ѥs�a�I����n��O�@�Ӽ��x������C
LONG
	);
	set("exits", ([
  "northwest" : ACME_PAST+"area/pass6.c",
  "southwest" : __DIR__"wildroad4.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
