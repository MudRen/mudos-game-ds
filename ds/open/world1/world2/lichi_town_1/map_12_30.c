inherit ROOM;
void create()
{
	set("short", "�x�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_31",
	"south" : __DIR__"map_13_30",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
