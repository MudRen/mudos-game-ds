inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_12",
	"east" : __DIR__"map_7_13",
	"north" : __DIR__"map_6_12",
	"west" : __DIR__"map_7_11",
	]));
        set("objects",([
        __DIR__"magma":5,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

