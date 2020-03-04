inherit ROOM;

void create()
{
        set("short", "步靈市集");
        set("long", @LONG
卡來卡去卡來卡去，步靈市集裡的人似乎都不停息的穿梭在這幾 
賣防具的工頭所擺設的攤子前，這裡的竹架上掛著一件又一件的用鐵
做成的鐵用品，連軒轅烈身上的硬皮甲都是他的傑作。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"store5",
  "south" : __DIR__"store4",  
])); 
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"storeman6" : 1, 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

