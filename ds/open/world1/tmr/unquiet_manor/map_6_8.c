inherit ROOM;
void create()
{
	set("short", "�H�ۤp��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_8",
	"north" : __DIR__"map_5_8",
	"west" : __DIR__"map_6_7",
	"east" : __DIR__"map_6_9",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

