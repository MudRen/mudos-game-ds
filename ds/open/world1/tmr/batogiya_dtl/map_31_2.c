inherit ROOM;
void create()
{
	set("short", "�D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_32_2",
	"north" : __DIR__"map_30_2",
	"east" : __DIR__"map_31_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

