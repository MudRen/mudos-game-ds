#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("羅漢護手" ,({ "luo-han wrists","wrists" }) );
        set("long",@LONG
一對質感極好的護手，上頭用小楷寫滿小字，你仔細的看，才發現上
頭寫的是一篇經文，你讀著讀著，心情似乎平靜不少了。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(1000);
                set("material", "linen");
                set("unit", "對");
                set("value",1200);
                set("volume",3);
        }
                set("armor_prop/armor", 10);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
        setup();
}

