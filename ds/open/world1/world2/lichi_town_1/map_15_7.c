inherit ROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_8",
	"south" : __DIR__"map_16_7",
	"north" : __DIR__"map_14_7",
	"west" : __DIR__"map_15_6",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

