inherit ROOM;
void create()
{
	set("short", "�׫�");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_17_35",
	"north" : __DIR__"map_16_34",
	"west" : __DIR__"map_17_33",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

