inherit ROOM;

void create()
{
        set("short", "商店街－防具店");
        set("long", @LONG
這裡是港都商店街中的武器店，店門口上方掛著一面木盾，店裡擺著各式盔
    甲、防具，琳琅滿目讓你眼花繚亂，簡直可以當作博物館了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room39",
  "southwest" : __DIR__"room43",
  //"north" : __DIR__"room34",
  "east" : __DIR__"room41",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

