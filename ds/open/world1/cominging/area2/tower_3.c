#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�u�ö�"HIB"�^��"NOR);
	set("long", @LONG

�A�Ө�F�u�ö𪺳��ݡA�b����u���@�D���ܸy����������A���b
�A���䪺�O�@�ӭӯ��^�^�諸�u�áA�@�y�Y�¤������A���ɪ�����b��
�ϥ|�P���󪺲����A�n�䪺�˪L���G���Ǥj���A�ҥH��������A�ݤ�
�M���A�������a�観�@�Ӷ�Χ�o���C

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower_2.c",
]));
	set("objects",([
  __DIR__"npc/fort_g.c": 3,
]));
	set("item_desc",([
  "��Χ�o��" : "�@�Ӷ�Ϊ���o���Ať���O���~�īI�J�ɡA�N�|�o�g�T�ϡA�������i�h�ٳƪ��A�A\n"
		+"�ҥH���Ϫ��çL�����n�g�L�Y�檺�D��A�H�K�@�ѧ�o���|�~��ӳy����áC\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	set("level","tower_3");
	setup();
	replace_program(ROOM);
}