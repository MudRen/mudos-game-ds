// Modify with AreaMaker1.0
// Room32.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̬O�@���H�ϵ}�֪���L�C�𸭫D�`�Z�K�A�Y�ϬO�դѤ]����
�ݨ춧���C�n�䦳�@�ʥ��j���Ѻ_��A�W���٦��Ӹ��ۡA�i�O�����
�S���ݨ��i�Ļe�A�����D�e�̬O�a������ͪ��C  
LONG
	);
	set("exits", ([
	        "north": __DIR__"room22",
		"east": __DIR__"room33",
		"south": __DIR__"room42",
		"west": __DIR__"room31",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

