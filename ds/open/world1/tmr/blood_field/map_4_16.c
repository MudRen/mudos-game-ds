inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_16",
	"west" : __DIR__"map_4_15",
	"south" : __DIR__"map_5_16",
	"east" : __DIR__"map_4_17",
	]));
	        set("objects", ([
                __DIR__"npc/ents2" : 1, 
        ]) );

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

