inherit ROOM;
void create()
{
        set("short", "工作室");        
set("long",@LONG
這裡是鐵匠舖的工作室，你看到眼前的鐵匠師傅十分的認真，而且
也有著非常純熟的技巧，而他打鐵的動作每一下都給人十分有力的感覺
，打鐵聲鏘∼鏘∼的響著，令人不由自主的信賴著他，看來該是受過很
久的訓練。
LONG
        );
        set("exits", ([
  "east" : __DIR__"po8s",
]));
set("objects", 
([__DIR__"npc/fix-smith" : 1,
        ]));
set("light",1);        
set("no_clean_up", 0);
        setup();
}







