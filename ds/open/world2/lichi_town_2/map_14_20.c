inherit ROOM;
void create()
{
	set("short", "�D�㩱");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_13_20",
	"west" : __DIR__"map_14_19",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

