inherit ROOM;
void create()
{
	set("short", "��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_5",
	"south" : __DIR__"map_8_4",
	"north" : __DIR__"map_6_4",
	"west" : __DIR__"map_7_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

