inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_31_31",
	"south" : __DIR__"map_32_32",
	"north" : __DIR__"map_30_32",
	"east" : __DIR__"map_31_33",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

