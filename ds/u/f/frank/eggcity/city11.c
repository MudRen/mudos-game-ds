inherit ROOM;

void create()
{
        set("short", "錟都城南武門");
        set("long", @LONG
走出了陰暗的森林步道區，在你眼前的是錟都城的城門─北武門，雄
偉的城門高聳入雲，結實的大門是用一層厚重的金鐵鍍上，堅固的程度叫
人想用手指敲敲看。在這裡你看到的是人來人往的，還有小販在那叫賣呢
，好不熱鬧，不過站在城門口的官兵倒是，蠻格格不入這熱鬧的氣氛，一
臉冷酷的對往的人，仔細盤查，像是再審犯人似的，令人不舒服。
LONG
        );
        set("exits", ([                 
                "north" : __DIR__"city45",
                                        ]));
                
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/citysoldier":3 ,
                __DIR__"npc/cityguard":2 ,
                                        ]));           
        

        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

