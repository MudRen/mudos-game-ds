inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_6",
	"west" : __DIR__"map_5_4",
	"south" : __DIR__"map_6_5",
	"north" : __DIR__"map_4_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

