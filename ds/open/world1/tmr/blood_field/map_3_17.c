inherit ROOM;
void create()
{
	set("short", "���s����");
        set("long", @LONG
�A�����b���s���������A�|�}�����j���A�������������C
LONG
);
	set("exits",([
	"north" : __DIR__"map_2_17",
	"west" : __DIR__"map_3_16",
	"south" : __DIR__"map_4_17",
	"east" : __DIR__"map_3_18",
	]));
	set("outdoors","land");
	set("objects", ([
		__DIR__"npc/ents2" : 1, 
	]) );
        setup();
        set("map_long",1);     //show map as long
}

