// Room: /u/s/slency/area/ugelan/wood1.c

inherit ROOM;

void create()
{
	set("short", "�諰��");
	set("long", @LONG
�o�̬O�վB�����譱�������A���F���K�O�վB�����F�A�ѳo�̩���
���i�H��F�վB��������ۦW���K�񴵴˪L�A�o�y�˪L�۫H�j�a���ռ�
��ԡA��C�ӤHť��o�ӦW�r�ɡA�`�O�y��a�աA��Ӧۨ�~�e�A�Z�O
�i�J���˪L���H�A���A�]�S���X�ӡA�o�O�H�h�ìO�_������r�~���b
���˪L�̡A����N�A�]�S���~�����i�J�o�y�O�H���媺�˪L�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood2",
  "east" : __DIR__"road12",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
