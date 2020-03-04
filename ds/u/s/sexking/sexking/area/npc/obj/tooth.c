#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"大地之牙"NOR,({ "the earch's tooth","tooth", }));
        set_weight(1000);
        set("armor_prop/str",1);
        if( clonep() )
        set_default_object(__FILE__);
        else
        {
                set("long",HIG"一個彎月型狀巨牙，表面發出"HIC"冷冷的光"HIG"，你隱約\n的感受到其強大力量，但也感到莫名的情感流露。\n"NOR);
                set("unit","個");
                set("value",1000);
        }
        setup();
}
void init()
{
 add_action("do_l","l");
 add_action("do_look","look");
}
int do_l(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg!="冷冷的光" )
      {
                notify_fail("你要看什麼?\n");
                return 0;
      }
write(HIC"這冷冷的光十分迷人，裡面似乎有一個[封]字，令人百思不得其解。\n"NOR,this_player());
return 1;
 } 
int do_look(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg!="冷冷的光" )
      {
                notify_fail("你要看什麼?\n");
                return 0;
      }
write(HIC"這冷冷的光十分迷人，裡面似乎有一個[封]字，令人百思不得其解。\n"NOR,this_player());
return 1;
 } 
