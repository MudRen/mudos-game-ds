inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_5",
	"south" : __DIR__"map_10_6",
	"east" : __DIR__"map_9_7",
	"north" : __DIR__"map_8_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

