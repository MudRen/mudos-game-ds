inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_8",
	"west" : __DIR__"map_11_6",
	"south" : __DIR__"map_12_7",
	"north" : __DIR__"map_10_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

