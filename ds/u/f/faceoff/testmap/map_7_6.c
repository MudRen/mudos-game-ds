inherit ROOM;
void create()
{
	set("short", "�t�G");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_5",
	"south" : __DIR__"map_8_6",
	]));
 set("objects", ([__DIR__"npc/shark" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

