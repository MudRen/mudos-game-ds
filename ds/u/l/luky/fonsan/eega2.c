
inherit ROOM;

void create()
{
	set("short", "���Ҹ�");
	set("long", "�o�O�@������]�S�����ũж��C\n");
	set("outdoor","land");
	set("exits", ([
	"north": __DIR__"eega1",
	"east": __DIR__"eega4",
	"south": __DIR__"eega3",
	]));
	setup();
	replace_program(ROOM);
}
