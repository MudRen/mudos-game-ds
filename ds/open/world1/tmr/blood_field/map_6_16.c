inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_5_16",
	"west" : __DIR__"map_6_15",
	"east" : __DIR__"map_6_17",
	]));
	set("outdoors","land");
	set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/fetish" : 1, 
          __DIR__"npc/fetish_wizard" : 1, 
          __DIR__"npc/ents2" : 1, 
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

