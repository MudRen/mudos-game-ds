// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "���q��");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega6",
	"south": __DIR__"eega23",
	]));
	setup();
	replace_program(ROOM);
}
