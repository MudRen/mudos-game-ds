#include <ansi.h>
inherit ITEM;

string *chest_list = ({
"/open/world1/tmr/area/npc/obj/manto","/open/world1/tmr/area/npc/obj/soup",
"/open/world1/tmr/area/npc/obj/bag","/open/world1/tmr/area/npc/obj/game",
"/open/world1/japan-susi","/open/world1/korea-pickles",
"/open/world1/promise/yang-doll","/open/world1/promise/gold-box",
"/open/world1/promise/exp","/open/world1/promise/opp",
"/open/world1/promise/wu-doll","/open/world1/promise/lee-doll",
"/open/world1/promise/you-doll","/open/world1/promise/liu-doll",
"/open/world1/promise/shan-doll","/open/world1/promise/ling-doll",
"/open/world1/promise/bonze-doll","/open/world1/promise/bonze2-doll",
"/open/world1/promise/yang-doll",
});
void create()
        {
         set_weight(5);
         set_name(HIY"�����c"NOR,({"gold box","box"}));
         set("no_give", 1);
         set("no_sell", 1);
         set("no_put", 1);
         set("long", "�t�õL��Ⱦ����@�ӽc�l�C\n");
         set("unit", "��");
         setup();
}

void init()
{
        add_action("do_open","open");
}

    int do_open(string arg)
{
  object me = this_player();
  object ob,ob1,ob2;

        if( !arg || arg=="" ) return notify_fail("�A����S�o�تF��!!\n");
        if( arg=="box" ) {
        if( random(100) > 2 )
         {
          ob1= new(chest_list[random(sizeof(chest_list))]);
          ob1->set_amount(1);
          message("world:world1:vision","\n\t"HIW+me->query("name")+"���}�����c�l�A�~�M�o��F"HIR+ob1->name()+"�C\n\n"NOR,users());
;
          ob1->move(me);
         } else {
          ob2= new("open/ghost/room/obj/kp");
          ob2->set_amount(1);
          message("world:world1:vision","\n\t"HIW+me->query("name")+"���}�����c�l�A�~�M�o��F"HIR+ob2->name()+"�C\n\n"NOR,users());

          ob2->move(me);
     }
    destruct(this_object());
    return 1; 
}

}

