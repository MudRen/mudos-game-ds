// Room: /u/s/slency/area/ugelan/royalty.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"�y�c�ʼs���z"NOR);
	set("long", @LONG
�o�̬O�Ӯc�j���e���s���A���e���F�\�h�ͽáA�A�����i�H�q�j��
�K���_�ؤ��樣�Ӯc��������o�ؿv�A�a�M�j���`��A���L�A���M�Ԥ�
��Q�i�c�@�s�s���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"royalty3",
  "south" : __DIR__"pontlevis",
]));
	set("objects", ([ /* sizeof() == 1 */	
       __DIR__"npc/guard2" : 4,
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
