inherit ROOM;
void create()
{
	set("short", "���s��}");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_32",
	"east" : __DIR__"map_4_34",
	]));
	set("outdoors","land");
	
	set("objects", ([
		__DIR__"npc/ents" : 1, 
		__DIR__"npc/wendigo.c" : 2, 
		__DIR__"npc/wild_toast.c" : 2, 
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

