inherit ROOM;
void create()
{
	set("short", "�D�㩱");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_20",
	"south" : __DIR__"map_14_19",
	"north" : __DIR__"map_12_19",
	"west" : __DIR__"map_13_18",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
