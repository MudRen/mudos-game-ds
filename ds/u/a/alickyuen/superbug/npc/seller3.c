#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�ӤH" , ({ "seller" }) );
        set("level",10);
        set("race","�H��");
        set("age", 30);
        set("long","�A���e���o��A���b�o���G���ө�������A�A�i�H��L�ݬݦ������A�R�C\n");
        set("sell_list",([
__DIR__"eq/ecloth.c" : 1,
        ]) );
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
