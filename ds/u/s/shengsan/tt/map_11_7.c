inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_6",
	"east" : __DIR__"map_11_8",
	"north" : __DIR__"map_10_7",
	"south" : __DIR__"map_12_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
