// Room: /u/d/darkfool/area1/l2.c

inherit ROOM;

void create()
{
	set("short", "��D-���Ϯ��]");
	set("long", @LONG
�|�P�R�������A�A���I��Y���o�{������Ǫ��F�@�Ƥp�p����A��n
������Ϯ��]�]�O���e�A�n���b�ﱵ�n���J�Ϯ��]���H�@��A�ݵۥi�R��
�p��A�߱��]ı�o��A�F�_�ӡC�A�b�q�Q���ӬO�Ϯ��]�̪��H�ت��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"l1",
  "south" : __DIR__"l3",
]));

	setup();
	replace_program(ROOM);
}
