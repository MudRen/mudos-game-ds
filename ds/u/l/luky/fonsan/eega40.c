// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "��������n����f");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"west": __DIR__"eega39",
	"south": __DIR__"eega45",
	"north": __DIR__"eega26",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
