inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_5",
	"west" : __DIR__"map_12_3",
	"south" : __DIR__"map_13_4",
	"north" : __DIR__"map_11_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
