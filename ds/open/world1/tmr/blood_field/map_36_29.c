inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_35_29",
	"west" : __DIR__"map_36_28",
	"east" : __DIR__"map_36_30",
	]));
		set("outdoors","land");
			set("objects",([
			__DIR__"npc/cat" : 2, 
			__DIR__"npc/hulks" : 2, 		
		]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

