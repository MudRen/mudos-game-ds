inherit ROOM;
void create()
{
	set("short", "ĵ�ë�");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_17",
	]));
	set("objects", ([
	__DIR__"../npc/malo_guard_18" : 1,
	]) );
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

