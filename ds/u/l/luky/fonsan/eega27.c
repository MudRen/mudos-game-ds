// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�n�����ਤ");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega28",
	"south": __DIR__"eega41",
	]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
