inherit ROOM;
void create()
{
	set("short", "���D");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_6",
	"east" : __DIR__"map_8_8",
	"south" : __DIR__"map_9_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

