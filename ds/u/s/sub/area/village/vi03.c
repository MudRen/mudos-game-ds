// Room: /u/s/sub/area/village/vi03.c

inherit ROOM;

void create()
{
	set("short", "�H�ۤp��");
	set("long", @LONG
�o�̪��a���O�ѸH�۩��E�����A�۷����[�C�F�䤣���B�٥i�H�ݨ�
�X���p�Фl�A�٤��ɫ_�X�\�\�����ϡA�M�Ťѥ�´���@�T���R���e���A�u
�O�C���Ӧ��C�i�H�ݨ즳�ǩ~���b��W���ʡA��B���R���F���x����^�C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"vi02",
  "east" : __DIR__"vi04.c",
]));

	setup();
	replace_program(ROOM);
}
