inherit ROOM;
void create()
{
	set("short", "���㩱");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_14",
	"north" : __DIR__"map_7_13",
	"west" : __DIR__"map_8_12",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

