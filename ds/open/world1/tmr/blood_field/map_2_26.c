inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_26",
	"west" : __DIR__"map_2_25",
	"south" : __DIR__"map_3_26",
	"east" : __DIR__"map_2_27",
	]));
	set("outdoors","land");
	set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/hulks" : 2, 
          __DIR__"npc/fetish_wizard" : 2, 
	]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

