inherit ROOM;
void create()
{
        set("short", "泊浪村內側");        
        set("long",@LONG
這裡是泊浪村廣場北側，由於屬於內側看起來人較少，平常是不會
有人來這裡的，看起來十分的冷清，晚上此地給人荒涼的感覺，所以村
人們夜晚皆都十分少到此地，聽說偶而會有人在此聚會。
LONG
        );
        set("exits", ([  
"south" : __DIR__"po11",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








