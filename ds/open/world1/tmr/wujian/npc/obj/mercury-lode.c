#include <ansi.h>
        
inherit ITEM;

void create()
{
    set_name("秘銀礦脈", ({"mercury lode", "lode"}));
    if( !clonep() ) {
        set("long", @LONG
秘銀礦是種比黃金還珍貴的金屬，但數量也非常稀有。
而這個秘銀礦脈可以挖掘(dig)出秘銀礦，不過你當然
得先有把鐵鋤之行。
LONG
);
        set("value", 10000);
          set("no_steal",1);
        set("unit", "座");
        set("weight", 1000000);
        set("no_get",1);
      } else
        set_default_object(__FILE__);
    setup();
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg) {

        object hoe;
        object mercury, me;

        me = this_player();
        if( me->is_busy())
                return notify_fail("你正忙著。\n"); 
        if( !arg )
                return notify_fail("你想要挖掘什麼？\n"); 
        if( arg != "lode" && arg != "秘銀礦脈" ) 
                return notify_fail("你無法挖掘這樣東西。\n"); 

        hoe = present("_IRON_HOE_", me);
        if( !objectp(hoe) )
                return notify_fail("你身上沒有可以挖掘礦脈的工具。\n");
        
        switch( random(4) ) {
                case 0:
                        message_vision( YEL "$N"YEL"拿起鐵鋤對著$n"YEL"敲敲打打，忙了半天，終於挖出一塊祕銀。\n" NOR, me, this_object());        
                        mercury = new(__DIR__"mercury-mine");
                        mercury->move( me );
                        add("times",1);
                        break;
                case 1:
                        message_vision( YEL "$N"YEL"拿起鐵鋤對著$n"YEL"敲敲打打，忙了半天，什麼也沒有。\n" NOR, me, this_object() );        
                        break;
                default:
                        message_vision( YEL "$N"YEL"拿起鐵鋤對著$n"YEL"敲敲打打，流了滿身汗，什麼也沒有。\n" NOR, me, this_object() );        
                        break;
        }

        me->start_busy(2);

        if( query("times" ) > 3 + random(6) ) {
                message_vision( HIW "$n"HIW"的礦源已經枯\竭了。\n" NOR, me, this_object() );
                destruct( this_object() );
        }
        return 1;
}
