// Room: /u/s/superbug/train/a-2.c

inherit ROOM;

void create()
{
	set("short", "�h����[�_��]");
	set("long", @LONG
�o�̬O�h���Ϫ��_��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A����
��O�@���ޢ�СA�q�̭����ɪ��ǥX�ټM�����֡A�٦��n�����n�x�n�A��
�n�i;�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"a-1.c",
  "north" : __DIR__"a-3.c",
  "west" : __DIR__"a-18.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
