inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_32_35",
	"west" : __DIR__"map_31_34",
	"north" : __DIR__"map_30_35",
	"east" : __DIR__"map_31_36",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

