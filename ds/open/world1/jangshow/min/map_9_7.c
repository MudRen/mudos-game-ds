inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_7",
	"east" : __DIR__"map_9_8",
	"north" : __DIR__"map_8_7",
	"west" : __DIR__"map_9_6",
	]));
        set("objects",([
        __DIR__"ball":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

