// Room: /u/d/darkfool/area1/34.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�A�w�g�����D�����Y�F�A�o�̷Pı�W�S�O�����t�A�������X��
�Фl�ݨӤ]�O�ܤ[�S��H�F�A���X���Ʀܦ]���Ӥ[�S�O�i���ø񴳴�
�A�A�ݵۺ��a���U���ƨ��ƥh�A�ôb�o�̨쩳������S�O�A�~���̦n
���G�N��ѤF�o�Ө����C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"33",
]));

	setup();
	replace_program(ROOM);
}
