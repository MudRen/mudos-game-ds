inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_14",
	"west" : __DIR__"map_2_13",
	"south" : __DIR__"map_3_14",
	"east" : __DIR__"map_2_15",
	]));
				set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/fetish_wizard" : 2, 
          __DIR__"npc/wild_toast.c" : 2, 
	]) );
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

