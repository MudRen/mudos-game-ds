#include <ansi.h>

inherit ITEM; 

void create()
{
        set_name("停車場招牌", ({ "parking board","board" }));
        set("long", @long
這是比爾酒店門口的招牌，上頭用星際通用語寫著
       "Crazy Bill Parking Lot"
long
);       


        setup();
}
