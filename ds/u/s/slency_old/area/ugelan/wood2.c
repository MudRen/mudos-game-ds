// Room: /u/s/slency/area/ugelan/wood2.c

inherit ROOM;

void create()
{
	set("short", "�˪L�p�|");
	set("long", @LONG
�o�̬O�K�񴵴˪L���@���p�|�A�p���Ǫ����F����A�ݰ_�ӫ�
�[���S�H�ӹL���ˤl�A���B����찪�j�@�K�A�U���̭������G�U��
�U���t�A���F���ΰ����s�s�a�s�ۡA��y�˪L�X�G�O�Uţ���R, �A
���o�����_�믫�A�M�ߪ`�N���Ǫ��ܤơA��y�˪L�B�b�@�����R��
������^���C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"secretwood1",
  "south" : __DIR__"wood3",
  "east" : __DIR__"wood1",
  "northwest" : __DIR__"wood8",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
