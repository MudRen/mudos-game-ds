inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_15",
	"east" : __DIR__"map_10_16",
	"north" : __DIR__"map_9_15",
	"west" : __DIR__"map_10_14",
	]));
        set("objects",([
        __DIR__"magma":5,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

