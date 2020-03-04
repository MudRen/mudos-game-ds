// Room: /u/s/slency/area/ugelan/god1.c
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m�i[2;37;0m�иt���а�j��[1;37m�j[2;37;0m");
	set("long", @LONG
�o�̬O�иt���а󪺤j���f�A�q��W��Ӫ��J��A���a���W�A�A��
�m������˹��A�K�i�Q�����������C���O�۷���Y���t���A�L�L�a�A�i
�Hť�����֪��۫ߦb�Ť��n���A�j�a�b�ǳ�Ũ�۳o�ɥ��Y�ؿv�A�@����
�O�p�������Y�¿p�A���訫�i�H�^�쫰���C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "�j��" : "�J��Q����o���@���j���C
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church4",
  "east" : __DIR__"god2",
]));
	create_door("east", "�j��", "west", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
