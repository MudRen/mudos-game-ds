inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_3",
	"west" : __DIR__"map_4_2",
	"south" : __DIR__"map_5_3",
	"east" : __DIR__"map_4_4",
	]));
			set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/hulks" : 2, 
          __DIR__"npc/fetish_wizard" : 2, 
	]) );
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
