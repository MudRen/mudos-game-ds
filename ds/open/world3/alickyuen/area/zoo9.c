// 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CFish�ICyberZoo"NOR);
	set("long", @LONG
�W��ӡA�A�����e�@�G�A�]���A�ݨ�F�ܦh�����A�����a���A�T����
���L�L�L�ݱo�A���Ἲ�áC��M�A�ݨ즳�H��i�F�������A��Өe�̭n��
�\�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoo10",
  "down" : __DIR__"zoo7",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
