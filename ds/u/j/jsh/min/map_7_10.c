inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_10",
	"east" : __DIR__"map_7_11",
	"north" : __DIR__"map_6_10",
	"west" : __DIR__"map_7_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

