
inherit ROOM;

void create()
{
 set("short","草叢");
        set("long",
"讓人分不清方向的雜草叢。\n"
        );

         set("exits", ([
         "east": __DIR__"seven_l2",
         "west":__DIR__"seven_l1",
         "north":__DIR__"seven_l5",
         "south": __DIR__"seven_l3",
         "northwest": __DIR__"seven_l4",
         "northeast": __DIR__"seven_d4",
         "southwest": __DIR__"seven_l6",
         "southeast": __DIR__"seven_l7",
       
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
