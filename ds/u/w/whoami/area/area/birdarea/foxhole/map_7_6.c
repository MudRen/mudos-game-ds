inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_6_6",
	"south" : __DIR__"map_8_6",
	"east" : __DIR__"map_7_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
