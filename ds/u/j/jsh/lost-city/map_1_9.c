inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_1_10",
	"west" : __DIR__"map_1_8",
	"south" : __DIR__"map_2_9",
	"north" : __DIR__"map_0_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

