// 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CFish�ICyberZoo"NOR);
	set("long", @LONG
�o�ж������ܦh���u���~�����~�A���A�J�Ӥ@�ݡA�~�o�{���ǭ�ӬO
�@�ǥj�N�������ƥۡC���M�g�L�h�~�A���Ϊ��٨S���ܡC�A���Tı�o�j��
�M�O�ܼF�`���A���M�i��ܦh�~�e�s�b�b�o�@�ɪ��F��O�s�o���򧴷�C
���n�i�^������]�i���������a��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoo9",
]));
	set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/traveller" : 2,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
