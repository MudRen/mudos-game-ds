#include <path.h>
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIB "劉"HIM"周不愛"NOR, ({ "oldgirl" }) );
        set("gender", "女性" );
        set("age", 70);
        set("long","這位是king的奶奶，慈祥的面貌讓你深刻感受到她的慈愛，老奶奶
的臉上還有不少的縐紋，顯露出經歷了不少風霜，實在是一位令人敬佩的人，
當然她最疼愛的人還是king了，king也實在是一個幸福的小孩。\n
");
        set("level",70);
        set("attitude", "friendly");

        set("sell_list",([
                __DIR__"obj/pill" : 99999,
                __DIR__"obj/pill2" : 99999,
                __DIR__"obj/ttoopp": 99999,
                ALWAYS+"torch" : 5,
                ALWAYS+"newspaper" : 10,
        ]) );
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "老奶奶面露微笑的說﹕這位" + RANK_D->query_respect(
ob) + "﹐king不在喔！進來喝杯茶﹐休息一下吧。\n");
                        break;
                case 1:
                        say( "老奶奶拉拉衣服道﹕這位" + RANK_D
->query_respect(ob) + "﹐請進請進。\n");
 break;
case 2:
       say( "老奶奶說道﹕這位" + RANK_D->query_respect(ob) + "
來喝看看天山包種茶ㄛ！！好喝ㄟ！！快來。\n");
break;
}
}

