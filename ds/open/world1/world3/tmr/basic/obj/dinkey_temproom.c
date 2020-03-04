#include <path.h>
inherit ROOM;
int do_move(int flag);

void create()
{
        set("short", "電車裡");
        set("long", @LONG
你正處在舊世界電車裡，二旁頗為破爛的座椅上只有稀稀落落的幾個
人、或坐或躺的正等著電車發動。車內半冷不熱的空調，讓你覺得想找個
位子好好的休息一番。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "out" : FUTURE+ "tmr/basic/train_station1",
        ]));
        set("world", "future");
        set("light",1);
        set("no_clean_up", 0);

        setup();
}

int do_move(int flag)
{
        tell_room(__DIR__"dinkey_temproom","嗶嗶嗶！電車快速的關上車門，迅速的開向目的地\n");
        tell_room(__DIR__"dinkey_temproom","\n你覺得車身一陣晃動，嗶的一聲，車門又開啟了...\n");
        if(flag==1)
                set("exits", ([ "out" : "/u/s/superbug/train/3.c" ]));
        else 
                set("exits", ([ "out" : FUTURE+ "tmr/basic/train_station1"]));

        return 1;
}


