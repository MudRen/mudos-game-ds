// Room: /u/s/slency/area/ugelan/church6.c

inherit ROOM;

void create()
{
	set("short", "�@���e�`�p�|");
	set("long", @LONG
�o�̬O�@�������@���e�e�`���p�|�A�B�B�i�H�ݨ��\�h�ȫȦb���C
���A���e���賓�ݥh�A��¶�b�H�������վB���Ӯc�A���G�R���F���K��
�Pı�A�p�G�����|�A�ٯu�Q�i�c�h�ݤ@�ݩO�I
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"church5",
  "north" : __DIR__"church7",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
