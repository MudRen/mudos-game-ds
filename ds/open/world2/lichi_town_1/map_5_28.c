inherit ROOM;
void create()
{
	set("short", "�ѹD");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_29",
	"south" : __DIR__"map_6_28",
	"north" : __DIR__"map_4_28",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
