inherit ROOM;
void create()
{
	set("short", "����X�f");
	set("long",@LONG
�A�ש󨫥X�F����A�S�A�ת��Pı��F�H�n�������A���F��O�B�F
�������s�����n��A�ө�����O�����󪺸̭��A�A���ܲM�����ݨ찼��
���ਤ�B���@�ǤH��ۤ@�ɤT�X�|�������ˤl�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"sidestreet3.c",
//  "east" : __DIR__"boo-lin3.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
