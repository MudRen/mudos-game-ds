inherit ROOM;
void create()
{
	set("short", "��D");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_7",
	"south" : __DIR__"map_10_6",
	"north" : __DIR__"map_8_6",
	"west" : __DIR__"map_9_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

