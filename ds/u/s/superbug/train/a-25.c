// Room: /u/s/superbug/train/a-25.c

inherit ROOM;

void create()
{
	set("short", "�ǯS�t����");
	set("long", @LONG
�o�̬O�@���c�歹�������A�j�������H�𶢮ɳ��|�ӳo�̦Y�ǪF��A
���K���ѡA�C�C���o���ܦ���ӳh���ϤH���E�����a��A�]�O�p�D����
�̬y�q���a��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-11.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
