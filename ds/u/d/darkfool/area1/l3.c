// Room: /u/d/darkfool/area1/l3.c

inherit ROOM;

void create()
{
	set("short", "�Ϯ��]�e");
	set("long", @LONG
�b�A���e�q�ߪ��o�y�ؿv���N�O��W���Ϯ��]�F�A�y���j��嶮
�A�ᦳ���P�C��_�B�N���t���Υ����T��O�H�۰g�A�A���T���J�I��
�A�Q���۫سy�̨s���O����ҼˡC���}�O���W���j���N�i�H�i��̭�
�h�F�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"l2",
]));

	setup();
	replace_program(ROOM);
}
