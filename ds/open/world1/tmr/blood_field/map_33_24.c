inherit ROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_33_23",
	"south" : __DIR__"map_34_24",
	]));
	set("outdoors","land");
			set("objects",([
			__DIR__"npc/cat" : 2, 
			__DIR__"npc/hulks" : 2, 		
		]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

