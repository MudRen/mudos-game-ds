// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("light",1);
	set("exits", ([
	"north": __DIR__"eega25",
	"south": __DIR__"eega40",
	]));
	setup();
	replace_program(ROOM);
}
