
inherit ROOM;

void create()
{
	set("short", "�@�Ҹ�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega13",
	"west": __DIR__"eega11",
	]));
	setup();
	replace_program(ROOM);
}
