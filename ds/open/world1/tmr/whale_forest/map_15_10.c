inherit ROOM;
void create()
{
	set("short", "�L���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_16_10",
	"west" : __DIR__"map_15_9",
	"east" : __DIR__"map_15_11",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

