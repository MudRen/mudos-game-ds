inherit ROOM;

void create()
{
	set("short", "�s�}�U");
	set("long", @LONG
�A�{�b�w�g�֭n��F�F�����s���s�}�U�A�b���U�����|���X�����q
����ƹL�ӡA�`���@�Ǫ᪺�ؤl�N�O�o�ˤl�q���Q���j�ܦ��a�Ať��
�o�@�����s�������A�]���o�����Y���Y�{�`�`�Q�H�ҲV�c���A�G��W�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"psin7.c",
  "south" : __DIR__"psin5.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
