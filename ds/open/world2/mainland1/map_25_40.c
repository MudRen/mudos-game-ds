inherit ROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_25_39",
	"south" : __DIR__"map_26_40",
	"north" : __DIR__"map_24_40",
	"east" : __DIR__"map_25_41",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

