inherit ROOM;
void create()
{
	set("short", "�l��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_37",
	"south" : __DIR__"map_9_36",
	"north" : __DIR__"map_7_36",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

