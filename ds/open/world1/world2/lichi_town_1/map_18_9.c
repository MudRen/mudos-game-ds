inherit ROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_18_10",
	"north" : __DIR__"map_17_9",
	"west" : __DIR__"map_18_8",
	]));
	set("objects", ([
	__DIR__"../npc/beast_rat_3" : 2,
	]) );
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

