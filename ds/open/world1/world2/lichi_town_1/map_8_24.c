inherit ROOM;
void create()
{
	set("short", "�s�u�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_25",
	"south" : __DIR__"map_9_24",
	"north" : __DIR__"map_7_24",
	"west" : __DIR__"map_8_23",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
