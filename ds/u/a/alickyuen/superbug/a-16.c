// Room: /u/s/superbug/train/a-16.c

inherit ROOM;

void create()
{
	set("short", "�h����[�n��]");
	set("long", @LONG
�o�̬O�h���Ϫ��n����f�A�@��i�o�̧A�����۫H�b���Ӫ��@�ɸ���
���o�˪��a��A�·t����D�M���a���U���O�A�Pı�ϩ��Ө�F�t�@�ӥ@��
�A�A�榣���[�ָ}�B�Ʊ�໰�����}�o�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-15.c",
]));
set("objects", ([
__DIR__"npc/guard" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
