
inherit ROOM;

void create()
{
 set("short","���O");
        set("long",
"���H�����M��V�������O�C\n"
        );

         set("exits", ([
         "east": __DIR__"seven_l6",
         "west":__DIR__"seven_l2",
         "north":__DIR__"seven_l1",
         "south": __DIR__"seven_l3",
         "northwest": __DIR__"seven_l4",
         "northeast": __DIR__"seven_l5",
         "southwest": __DIR__"seven_l3",
         "southeast": __DIR__"grass",
       
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
