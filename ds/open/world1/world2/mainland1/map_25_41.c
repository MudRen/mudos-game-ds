inherit ROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_25_40",
	"south" : __DIR__"map_26_41",
	"north" : __DIR__"map_24_41",
	"east" : __DIR__"map_25_42",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

