inherit ROOM;
void create()
{
	set("short", "�H�ۤp��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_6_8",
	"north" : __DIR__"map_4_8",
	"west" : __DIR__"map_5_7",
	"east" : __DIR__"map_5_9",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

