inherit ROOM;
void create()
{
	set("short", "�p���J�f");
	set("long", @LONG
�o�̬O�@�ӹ��R�p�����J�f�A�o�̦��@���γ�����s�n�A�O�A���I
�Pı�M�R�A�ӥB�o�̦��۫Ҥ�����몺�p�e�M�y���g�L�A�Z���O�H��
�G�H����O�˪L�A�ҨӨ쪺�a��A�ө��F��h�O���׼w���̭����h�A�o
�̦��G���@�ǯ��O�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"forest4",
  "east" : __DIR__"village",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
