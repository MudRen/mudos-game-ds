inherit ROOM;
void create()
{
	set("short", "�F�۩v����");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_4",
	"north" : __DIR__"map_3_5",
	"south" : __DIR__"map_5_5",
	"east" : __DIR__"map_4_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

