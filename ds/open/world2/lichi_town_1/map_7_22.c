inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_23",
	"south" : __DIR__"map_8_22",
	"north" : __DIR__"map_6_22",
	"west" : __DIR__"map_7_21",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
