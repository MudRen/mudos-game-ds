// Room: /u/s/slency/area/ugelan/church5.c

inherit ROOM;

void create()
{
	set("short", "�@���e�`�p�|");
	set("long", @LONG
�o�̬O�@�������@���e�e�`���p�|�A���a�������A�A�O�ȹC��ͪ�
�n�a�I�A���e���O�C��A�K�O����A�R���F�L���ֱ��e�N�A���_�O�@��
�p�|�A���n�q�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"church6",
  "south" : __DIR__"church1",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
