inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_36_40",
	"south" : __DIR__"map_37_41",
	"north" : __DIR__"map_35_41",
	"east" : __DIR__"map_36_42",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

