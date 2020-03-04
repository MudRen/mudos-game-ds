#include <npc.h>
inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("杜小龜", ({ "du-gui","gui" }) );
        set("long",@long
杜小龜是一個年紀幼小的孩童，身上背著一個大箱子，正沿著碼頭叫
賣船票。
long
);
        set_race("human");
        set("age", 9);
        set_attr("str",5);
        set_attr("cps",2);
        set("chat_chance", 5);
        set("chat_msg", ({
                "杜小龜大聲喊道：「各位先生、小姐，往鯨魚島的船票一張只要八折200戒尼哦..」 \n",
                "杜小龜瘦小的身材在擁擠的人群被卡的寸步難行....\n",
                "杜小龜看著你問道：「你要買船票嗎？？」\n",
        }));
        set("merchandise", ([
                __DIR__"obj/boat_ticket":30,
                  "/d/batogiya_dtl/npc/obj/boat_ticket2" : 30,
        ]));

        set("title","船票販賣員");
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


