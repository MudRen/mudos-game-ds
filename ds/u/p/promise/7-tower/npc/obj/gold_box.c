#include <ansi.h>
inherit ITEM;

string *else_list = ({
"/open/world1/tmr/area/npc/obj/manto","/open/world1/tmr/area/npc/obj/soup",
"/open/world1/tmr/area/npc/obj/bag","/open/world1/tmr/area/npc/obj/game",
"/open/world1/japan-susi","/open/world1/korea-pickles",
__DIR__"gold-box",__DIR__"exp",__DIR__"opp",
});

string *book_list = ({
__DIR__"int_b",__DIR__"str_b",__DIR__"con_b",__DIR__"dex_b",
});
void create()
        {
         set_weight(5);
         set_name(HIY"�����c"NOR,({"gold box","box"}));
         set("long", "�t�õL��Ⱦ����@�ӽc�l�C\n");
         set("unit", "��"); 
         set("value",3000);         setup();
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
        if( random(100) > 1 )
         {
          ob1= new(else_list[random(sizeof(else_list))]);
          ob1->set_amount(1);
          message("world:world1:vision","\n\t"HIW+me->query("name")+"���}�����c�l�A�~�M�o��F"HIR+ob1->name()+"�C\n\n"NOR,users());
;
          ob1->move(me);

         } else {
          ob2= new(book_list[random(sizeof(book_list))]);

          ob2->set_amount(1);
          message("world:world1:vision","\n\t"HIW+me->query("name")+"���}�����c�l�A�~�M�o��F"HIR+ob2->name()+"�C\n\n"NOR,users());

          ob2->move(me);
     }
    destruct(this_object());
    return 1; 
}

}

