inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_9",
	"west" : __DIR__"map_11_7",
	"south" : __DIR__"map_12_8",
	"north" : __DIR__"map_10_8",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

