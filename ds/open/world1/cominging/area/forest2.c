inherit ROOM;
void create()
{
	set("short", "�˪L�~��");
	set("long",@LONG
�o�̬O�B�F���n�誺�j�˪L���_��A�b�o�̴˪L��o�󬰭Z���A�b
�_��O�˪L���X�f�A�Ӧb�n��O���֤߳B���˪L�A�o���Ǭ��D���p�ʪ�
���G�b�V�A�ܫ¡C
LONG
	);
	set("exits", ([
  "south" : __DIR__"forest3.c",
  "northeast" : __DIR__"forest.c",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
