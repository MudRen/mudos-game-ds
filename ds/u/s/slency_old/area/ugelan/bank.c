// Room: /u/s/slency/area/ugelan/bank.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIW"�վB���Ȧ�"NOR);
	set("long", @LONG
�o�̬O���a�̤j���@�a�Ȧ�A���Ѭd�߱b�ػP�����s�ڪ��~�ȡA�A
�i�H�ݨ��\�h�H�b�o�̳B�z�@�Ǩ��W���]�ȡA�����Ȧ�̪��A�A���W�a
�Ӧh���{�������O�������|�A���F���تA�ȡA�A�i�H��B����A�ݭn��
�O, �J��K�S�i���C���I�A�������a�Ȧ�Ҵ��Ѫ��A�ȽЬd�ߤu�@�H��
�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road8",
]));
	set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/banker" : 1,
 __DIR__"npc/roken" : 1,
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
