inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_5_17",
	"south" : __DIR__"map_6_18",
	"north" : __DIR__"map_4_18",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

