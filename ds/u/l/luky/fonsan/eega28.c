// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�n����");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega29",
	"west": __DIR__"eega27",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
