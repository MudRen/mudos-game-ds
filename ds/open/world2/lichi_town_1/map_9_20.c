inherit ROOM;
void create()
{
	set("short", "�s�u�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_21",
	"south" : __DIR__"map_10_20",
	"north" : __DIR__"map_8_20",
	"west" : __DIR__"map_9_19",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cat_2" : 1,
	]) );
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

