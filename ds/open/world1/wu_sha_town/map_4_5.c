inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_6",
	"west" : __DIR__"map_4_4",
	"south" : __DIR__"map_5_5",
	"north" : __DIR__"map_3_5",
	"up": __DIR__"seacoun39",
]));
 set("objects", ([__DIR__"../npc/fish" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
 if( interactive(this_player()) )
  for(int x=0;x<sizeof(all_inventory(this_player()));x++)
   if( all_inventory(this_player())[x]->query("id") == "torch" )
    all_inventory(this_player())[x]->water_effect();
}
