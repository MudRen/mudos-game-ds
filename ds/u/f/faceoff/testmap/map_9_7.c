inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_8",
	"south" : __DIR__"map_10_7",
	"north" : __DIR__"map_8_7",
	]));
set("objects", ([__DIR__"npc/eel" :1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

