inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_9",
	"west" : __DIR__"map_9_7",
	"south" : __DIR__"map_10_8",
	"north" : __DIR__"map_8_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

