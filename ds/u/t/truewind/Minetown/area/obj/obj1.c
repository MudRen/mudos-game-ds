#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("一輛巨大的漂浮車", ({ "huge float-vehicle","vehicle" }));
        set("long", @long
一輛巨大的運輸用車輛，正在空中漂浮著...。車身漆黑，看不清
楚裡頭的設備或者其他人員。
long
);       
        setup();
}