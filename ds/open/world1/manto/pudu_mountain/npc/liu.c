#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�B�p�c" , ({ "liu seller","seller" }) );
        set("level",20);
        set("race","�H��");
        set("age", 33);
         set("no_fight",1);
        set("long","�o��O�M���n�_�f�ͷN�R�檺�p�c�A���ۦѹ�A�O�ӥ��g���ͷN�H�C\n");
        set("chat_chance",8);
        set("chat_msg",({
           (:command("sweat"):),
        }) );
        set("storeroom",__DIR__"shop");
    set("no_kill",1);
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}


