inherit ROOM;
void create()
{
	set("short", "�L���p��");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_17_14",
	"north" : __DIR__"map_16_15",
	"east" : __DIR__"map_17_16",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

