
inherit ROOM;

void create()
{
 set("short","���O");
        set("long",
"���H�����M��V�������O�C\n"
        );

         set("exits", ([
         "east": __DIR__"grass",
         "west":__DIR__"seven_l6",
         "north":__DIR__"seven_l1",
         "south": __DIR__"seven_l2",
         "northwest": __DIR__"seven_l3",
         "northeast": __DIR__"seven_l7",
         "southwest": __DIR__"seven_l4",
         "southeast": __DIR__"seven_l5",
       
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
