inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_7",
	"east" : __DIR__"map_10_8",
	"north" : __DIR__"map_9_7",
	"west" : __DIR__"map_10_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

