// Room: /open/world1/tmr/goat_maze/stairway3.c

inherit ROOM;

void create()
{
	set("short", "�Ϩk���g�c - �a������");
	set("long", @LONG
�A���b���@�����Y�Q�����a������A���褣���a���U�����A�b�·t
���{�p���Ǧ���s�C�A��b����W���n�T�A�@�n�n�a�j���b��ӪŶ��A
���K�X���޲�����m�C����즹�A�A�ߤ��q�ƪ�����w�g�W�L�ƦʨӶ�
�F�A���O�A�i�g�i�H�����o�{�U�����G���q��@�B�ܤj���s���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"stairway4",
  "up" : __DIR__"stairway2",
]));
	set("current_light", 2);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
