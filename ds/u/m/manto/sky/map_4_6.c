inherit ROOM;
void create()
{
	set("short", "��D��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_6",
	"west" : __DIR__"map_4_5",
	"east" : __DIR__"map_4_7",
	"north" : __DIR__"map_3_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
