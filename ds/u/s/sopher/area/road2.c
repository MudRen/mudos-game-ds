#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG"眠之森林"NOR);
        set ("long", @LONG
走道這，草木漸漸稀疏了，似乎終於可以脫離這
可怕的森林了！這裡有一面牌子(sign)
LONG);  
        
        set("exits", ([
        "south": __DIR__"road3",
        "north": __DIR__"road1",
        ]) );
        set("outdoors","workroom.c");
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "sign": "
           由於此森林自古已危險出了名，各位請人民
           自愛，勿踏出本牌以外的區域，以免發生危險。
           經過軍團調查，近一年來至少已經有300件死亡
           命案，好自為之。
                   
           魔龍軍團長    瓦爾加布@

           火龍曆255年7月7日
   ", ]) ); 
        setup();
        replace_program(ROOM);
}
