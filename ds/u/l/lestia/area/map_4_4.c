inherit ROOM;
void create()
{
	set("short", "�F�۱�");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_3",
	"north" : __DIR__"map_3_4",
	"south" : __DIR__"map_5_4",
	"east" : __DIR__"map_4_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

