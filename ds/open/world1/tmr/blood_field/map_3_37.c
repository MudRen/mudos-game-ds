inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_2_37",
	"west" : __DIR__"map_3_36",
	"south" : __DIR__"map_4_37",
	"east" : __DIR__"map_3_38",
	]));
	
	set("objects", ([
		__DIR__"npc/ents" : 2, 
		__DIR__"npc/wendigo.c" : 2, 
		__DIR__"npc/hulks.c" : 2, 
	]) );
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

