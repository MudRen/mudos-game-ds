// Room: /u/s/slency/area/ugelan/god2.c
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"�i"NOR"�иt���а�"HIW"�j"NOR);
	set("long", @LONG
�o�̬O�����̤j���@�y�а�, �A�i�H�ݨ��۷�h���H���b�o�̰�§
��, �b�m���������g���U, �а�̥��ué��, �t�X�W�j���ޭ��^���t
��, ���t����^��[�@�p, �C�ӤH���ۤߪ��P����Ĳ, �A���T�]�P���
�p���Y, ���̭����i�H��а�᭱���Ъ١C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"god1",
  "in" : __DIR__"god3",
]));
	create_door("west", "�j��", "east", DOOR_CLOSED);
	set("item_desc",(["�m�����":"�۷���R������, ����U���C��, �b�Ӷ����Ӯg�U, ��o�Q�����R\n"]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
