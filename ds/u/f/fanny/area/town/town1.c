// Room: /u/f/fanny/area/town/town1.c

inherit ROOM;

void create()
{
	set("short", "�i���p��");
	set("long", @LONG
�g�L���~�[�A�ש��L�i���k���j�A�M�J���G���A�O�@�T�X�_
���M���e���A�񲴱�h�g�a���m�A�~���k�M�A���S���j�����c�ءA�o
�]�������o�������򪺥t�@���֤g�C
LONG
	);
	set("world", "undefine");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"town2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
