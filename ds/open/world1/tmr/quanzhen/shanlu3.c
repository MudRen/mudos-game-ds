// shanlu3.c �s��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�s�������Y�A�n���n�����@���p��L�A��ӦV�F�A�N�O��
�n�s���s�}�F�C
LONG
	);
	set("outdoors", "zhongnan");
	set("objects", ([
        CLASS_D("quanzhen")+"/lu" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
		"eastup"    : __DIR__"shanjiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
