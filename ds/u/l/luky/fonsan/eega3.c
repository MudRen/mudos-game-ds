
inherit ROOM;

void create()
{
	set("short", "���Ҹ�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega2",
	]));
	setup();
	replace_program(ROOM);
}
