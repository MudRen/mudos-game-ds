
inherit ROOM;

void create()
{
	set("short", "�@�Ҹ�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"west": __DIR__"eega19",
	]));
	setup();
	replace_program(ROOM);
}
