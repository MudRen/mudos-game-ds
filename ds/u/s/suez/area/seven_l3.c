
inherit ROOM;

void create()
{
 set("short","草叢");
        set("long",
"讓人分不清方向的雜草叢。\n"
        );

         set("exits", ([
         "east": __DIR__"grass",
         "west":__DIR__"seven_l1",
         "north":__DIR__"seven_l6",
         "south": __DIR__"seven_l5",
         "northwest": __DIR__"seven_l1",
         "northeast": __DIR__"seven_l2",
         "southwest": __DIR__"seven_l3",
         "southeast": __DIR__"seven_l4",
       
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
