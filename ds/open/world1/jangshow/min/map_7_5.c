inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_5",
	"east" : __DIR__"map_7_6",
	"north" : __DIR__"map_6_5",
	"west" : __DIR__"map_7_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

