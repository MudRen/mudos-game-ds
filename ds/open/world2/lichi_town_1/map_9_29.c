inherit ROOM;
void create()
{
	set("short", "���s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_30",
	"south" : __DIR__"map_10_29",
	"north" : __DIR__"map_8_29",
	"west" : __DIR__"map_9_28",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

