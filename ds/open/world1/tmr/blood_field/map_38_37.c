inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_37_37",
	"south" : __DIR__"map_39_37",
	]));
	set("outdoors","land");
		set("objects",([
			__DIR__"npc/fetish" : 2, 
			__DIR__"npc/cat" : 2, 		
		]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

