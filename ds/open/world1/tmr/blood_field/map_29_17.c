inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_28_17",
	"west" : __DIR__"map_29_16",
	"south" : __DIR__"map_30_17",
	"east" : __DIR__"map_29_18",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

