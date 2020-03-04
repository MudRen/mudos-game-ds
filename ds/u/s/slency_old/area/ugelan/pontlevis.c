// Room: /u/s/slency/area/ugelan/pontlevis.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"�Q��"NOR);
	set("long", @LONG
�o�̬O��V�Ӯc�@���e���@�y�j�ΦQ���A�e���M�ӵ۪����⪺���
�A�N�Q���ӱo�{�{�o���A�A���e�観�\�h�ͽþn�u�b�c���e�A���ݦp��
����աA�A�S���T��o�վB���Ұ�q�ȤF�X���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"royalty",
  "south" : __DIR__"road5",
]));
	set("item_desc", (["�Q��" : "�@�y�������Q���A�A�����ݨ�Q���U���@�B�g�C�i�H���ߡC\n" 
	]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
}	
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	if(arg != "�Q��") return 0;
	this_player()->move(__DIR__"underpontlevis");
	return 1;
}
