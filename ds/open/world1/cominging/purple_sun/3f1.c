// �����s�ĤT�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�I��I��I��A�A�ש�q�~�Y���F�W�ӡA�o�̪��a�դS��o������
�F�\�h�A�������L�����A��M�n���p�F�h�A�A�V���V���A�����D�|���|
�@���p�߶^�F�U�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"3f2.c",
  "down" : __DIR__"2f3.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
