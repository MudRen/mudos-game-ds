inherit ROOM;
void create()
{
	set("short", "����");
	set("long",@LONG
�o�̬O�@���p����A�b�o�@������W�èS������F��A�j�h�u�O�@
�ǩЫΡB�ؿv�}�F�A�ӥB�b�o�̪��H�Ϥ]��o�����j��W���w�R�h�F�A
�_��O�B�F����j��A�n��O�@������������C
LONG
	);
	set("exits", ([
  "north" : __DIR__"bwest3.c",
  "south" : __DIR__"sidestreet1.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
