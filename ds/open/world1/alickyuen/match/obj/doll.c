/*      File : /open/world1/alickyuen/match/obj/doll.c        
        Author: Alickyuen@DS 
        Last Modify: 2002-5-25
        Special Thanks To: Acme@DS        */

#include <ansi2.h>

#define START_ROOM "/open/world1/alickyuen/match/exit.c"

inherit ITEM;


void create()
{
        set_name("替死娃娃"HIW"[比賽專用]"NOR, ({ "match doll", "doll", "undead_item" }) );
        set_weight(100);
        set("value", 0);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
        set("unit", "隻");
        set("long", @long
一個詭異的洋娃娃，粉紅色的裙子上有著許多白色的小圓點，
充滿的神秘的靈氣...你似乎看到她在眨眼睛！？
它是這次比賽的監察人，當你輸後，它會帶你去到安全的地方。
long);
        set("undead_msg", " ");
        set("wimpy_msg", " ");
        set("start_place", START_ROOM);

        setup();
}

