inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_9_34",
	"west" : __DIR__"map_10_33",
	]));
	set("outdoors","land");
			set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/fetish_wizard" : 2, 
          __DIR__"npc/wild_toast.c" : 2, 
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

