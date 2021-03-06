inherit ROOM;

void create()
{
        set("short", "錟都城中央水塘的噴水口");
        set("long", @LONG
這裡是中央水塘的中央位置，你正站在一塊大石頭上，你低下頭來可
以清楚的看見水底的魚群在水中自由自在的遊來遊去十分寫意。而你眼前
的噴水柱正在不斷的變換花樣，這些來自西方的玩意兒深深吸引了你的目
光，就算你的衣服已經被噴水池的水花給噴濕了，但是你依然沒感覺，仍
舊沉醉在眼前的美景之中。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"city5",
                "south" : __DIR__"city8",
                "east" : __DIR__"city6",
                "north" : __DIR__"city3",
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

