
inherit ROOM;

void create()
{
	set("short", "�@�Ҹ�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"east": __DIR__"eega7",
	"west": __DIR__"eega5",
	"south": __DIR__"eega21",
	]));
	setup();
	replace_program(ROOM);
}
