inherit ROOM;

void create()
{
        set("short", "步靈市集");
        set("long", @LONG 
你一來到這裡就聽到吵雜的叫賣聲，每個人都推擠著你，密的你
喘不過氣來，在此攤位的是賣牛肉麵的，看到他大刀揮揮，幾塊鮮嫩
的牛肉掉進滾水，香氣四溢，此攤是生意最好的一攤。

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"store1", 
  "west" : __DIR__"store4", 
  "north" : __DIR__"store5",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"sellman2" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

