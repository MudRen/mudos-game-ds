inherit ROOM;
void create()
{
	set("short", "�s�u�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_21",
	"south" : __DIR__"map_4_20",
	"north" : __DIR__"map_2_20",
	"west" : __DIR__"map_3_19",
	]));
	set("objects", ([
	__DIR__"../npc/malo_guard_18" : 1,
	]) );
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

