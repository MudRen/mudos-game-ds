//聖誕活動第一名 志狼(ttoopp) 禮物 -by tmr-

#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
          set_name(HIY "皇者面罩" NOR ,({ "ttoopp mask","mask"}) );
          set("long",@LONG
聖誕活動第一名 志狼所得獎的禮物。
這是一個只有擁有皇者之氣的人才可穿上的面具。

在面罩的額頭地方，刻了二個字「豬頭」，
在右下角也有幾個小字「流影(Acme) 題」，
因為有了這幾個字，使這個面罩價值不翡。
LONG
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件" );
                set("value",2500);
                set("valme",2);
                set("no_sac",1);
                set("armor_prop/armor", 5);
                set("armor_prop/con",1);
                  set("wear_msg","$N穿上皇者面罩之時，有一種高高在上的感覺。\n" );
                set("remove_msg","當$N脫下皇者面罩時，高高在上的感覺頓時消失了許\多。\n" );
        }
        setup();
}

int query_autoload() { return 1; }

