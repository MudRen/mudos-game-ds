inherit ROOM;

void create()
{
	set("short", "�D���Y");
	set("long", @LONG
�o�̬O�e���������̥D�n�����Y�A�b�o�̦��\�h���ж��A�ӦU�ө�
�����O�e���������n�淥�����H�A�ר�O�b�A���e���x�����ЩM���k��
���@�Ϫ��ж��A�o�̪��a�O�ܰ��b�A���G�g�`�M�~�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"flurry46.c",
  "north" : __DIR__"flurry50.c",
  "west" : __DIR__"flurry47.c",
  "east" : __DIR__"flurry49.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
