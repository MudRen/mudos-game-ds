inherit ROOM;
void create()
{
	set("short", "���s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_29",
	"south" : __DIR__"map_10_28",
	"north" : __DIR__"map_8_28",
	"west" : __DIR__"map_9_27",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

