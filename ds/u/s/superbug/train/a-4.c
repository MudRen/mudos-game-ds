// Room: /u/s/superbug/train/a-4.c

inherit ROOM;

void create()
{
	set("short", "�h����[�_��]");
	set("long", @LONG
�o�̬O�h���Ϫ��_����f�A�@��i�o�̧A�����۫H�b���Ӫ��@�ɸ���
���o�˪��a��A�·t����D�M���a���U���O�A�Pı�ϩ��Ө�F�t�@�ӥ@��
�A�A�榣���[�ָ}�B�Ʊ�໰�����}�o�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"a-3.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
