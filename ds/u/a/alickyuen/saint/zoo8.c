// 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�DShop�ICyberzoo"NOR);
	set("long", @LONG
�o�̬O�ʪ��餺���@���ө��A�D�n���O��@�Ǥ�H�Τp�����C�H�A��
�̨��w�諸�n��O���ʪ��Y���}�ƤF�C�A�i�H�R�@�Ǩӵ��ʪ��Y���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zoo7",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zseller" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
