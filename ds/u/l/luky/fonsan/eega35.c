// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�n����");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega36",
	"west": __DIR__"eega34",
	"north": __DIR__"eega100",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
