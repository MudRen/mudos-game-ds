inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_8",
	"west" : __DIR__"map_8_6",
	"south" : __DIR__"map_9_7",
	]));
 set("objects", ([__DIR__"../npc/clam" :1 ,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

