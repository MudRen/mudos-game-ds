inherit ROOM;

void create()
{
        set("short", "錟都城中央水塘的步道南側");
        set("long", @LONG
這裡是錟都城中央水塘步道的南側，而你站的地方是一塊石階，往北的
方向有一排的石階，連到一塊大石上，供人觀賞噴水池時一塊立足之地。而
往東和往西則是分別連到兩塊沙洲上，供油人休憩。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"city7",
                "south" : __DIR__"city39",
                "east" : __DIR__"city9",
                "north" : __DIR__"city1",
                                        ]));
                
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/fish":4 ,        
                                ]));           
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

