#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"Naboo ��������"NOR);
	set("long", @LONG
�o�ONaboo���������ߡA�A�i�H�b�o�̬ݨ��_�䦳�@�y������
�Ӯc�C�ѩ�o�̳Q�˪L�]��ۡA�ҥH���A�@�زM�s�۵M���Pı�C��
�F���i�H�q��Naboo���̤j���˪L�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road7",
  "west" : __DIR__"road10",
  "north" : __DIR__"road4",
  "south" : __DIR__"road3",
]));
		 set("objects",([
 	 __DIR__"npc/police":2,
	__DIR__"npc/obj/pot":1,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);

}
