inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_28",
	"west" : __DIR__"map_4_27",
	"south" : __DIR__"map_5_28",
	"east" : __DIR__"map_4_29",
	]));
	set("outdoors","land");
	
	set("objects", ([
		__DIR__"npc/ents" : 1, 
		__DIR__"npc/wendigo.c" : 2, 
		__DIR__"npc/hulks.c" : 2, 
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

