inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_4",
	"east" : __DIR__"map_7_5",
	"north" : __DIR__"map_6_4",
	"west" : __DIR__"map_7_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

