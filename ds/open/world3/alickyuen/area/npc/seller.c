#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name(YEL"�^������H"NOR , ({ "robot" }) );
        set("level",10);
        set("race","�����H");
        set("age", 30);
         set("no_fight",1);
        set("long","�o�Ӿ���H�O�t�d�^�����u�@�C\n");
        set("chat_chance",8);
        set("chat_msg",({
           "�b�Ǫ���z��M�T�_:�^���U���U�˪����~�I\n",
           "����H���D:�w��,�w��~\n",
        }) );
        set("storeroom",__DIR__"item/shop1.c");
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}
