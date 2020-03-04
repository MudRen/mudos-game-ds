inherit ROOM;

void create()
{

set("short","東大街");
set("long", @LONG
這裡是神木村的東大街中央部分, 在這條街上有許多從海邊而來的外
地人, 在你的北邊有一間建築雄偉的房屋, 好像是神木村的村長所住, 在
你的南邊有一家武館, 你可以到武館逛一逛. 
LONG
);
set("outdoors", "land");
set("exits", ([                
"north" : __DIR__"rr_2.c",        
"west" : __DIR__"road_10.c", 
"east" : __DIR__"rr_3.c", 
"south" : __DIR__"rr_4.c", 
        ]));

 setup();
}

