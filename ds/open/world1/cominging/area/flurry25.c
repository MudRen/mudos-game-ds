inherit ROOM;

void create()
{
	set("short", "�������Y");
	set("long", @LONG
�o�̬O�������������Y�A���D�W���ǤH�s�b���ʡA���L���ܤp�p�n
�A���ߨ����@�몺���A�����D������ϡA�b���񪺫Τl�̿O�������q��
���A�դѦ��դѡA�ߤW��p�դѡA�����@�~�b���U�ӻȨ�n��h�ֵ۩O
�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry26.c",
]));
	set("no_clean_up", 0);
	set("objects",([
  __DIR__"npc/thief.c" : 3,
]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
