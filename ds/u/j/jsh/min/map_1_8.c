inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_2_8",
	"east" : __DIR__"map_1_9",
	"west" : __DIR__"map_1_7",
	]));
        set("objects",([
        __DIR__"magma":5,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

