// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "���q��P�n�����e�f");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega24",
	"south": __DIR__"eega42",
	"east": __DIR__"eega30",
	"west": __DIR__"eega28",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
