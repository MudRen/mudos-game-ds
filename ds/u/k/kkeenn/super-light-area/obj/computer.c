#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"電腦"NOR,({"computer"}) );
set_weight(20);
   set("long","
目前在螢幕上浮現的選項有(push number):
[36m1[0m:                       [35m 武器之間[0m.[35m [0m
字幕出整齊的排列出:
「在這裡你可以盡情的開槍，沒人會阻止你，只是後果自負。」
                                     Copyright(C) ---超•光子練習場(Super-light-area)---
");
        if( clonep() )
                set_default_object(__FILE__);
 else { 
 set("unit", "個");
 set("no_get",1);
 set("value", 1); 
 set("no_sac",1);
 }
setup();
}
