inherit ROOM;

void create()
{
        set("short", "防具店");
        set("long", @LONG
這裡是港都商店街中的武器店，店門口上方掛著一面木盾，店裡擺著各式盔
甲、防具，琳琅滿目讓你眼花繚亂，簡直可以當作博物館了。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"east" : __DIR__"room7",  
  "west" : __DIR__"room5", 
  "south": __DIR__"room9",
  "north": __DIR__"room7", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


