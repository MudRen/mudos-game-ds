
inherit ROOM;

void create()
{
 set("short","���O");
        set("long",
"���H�����M��V�������O�C\n"
        );

         set("exits", ([
         "east": __DIR__"seven_l1",
         "west":__DIR__"seven_l2",
         "north":__DIR__"seven_l4",
         "south": __DIR__"seven_l5",
         "northwest": __DIR__"grass",
         "northeast": __DIR__"seven_l3",
         "southwest": __DIR__"seven_l6",
         "southeast": __DIR__"seven_l4",
       
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
