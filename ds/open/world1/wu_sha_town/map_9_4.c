inherit ROOM;
void create()
{
	set("short", "���y");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_4",
	"north" : __DIR__"map_8_4",
	])); 
set("objects", ([__DIR__"../npc/eel" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

