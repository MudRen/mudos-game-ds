inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_21",
	"south" : __DIR__"map_5_20",
	"north" : __DIR__"map_3_20",
	"west" : __DIR__"map_4_19",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

