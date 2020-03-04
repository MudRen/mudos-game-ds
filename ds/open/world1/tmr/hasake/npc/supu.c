#include <ansi.h>
inherit NPC;
int ask_me();
string* goods = ({
       __DIR__"obj/shoujuan",
       __DIR__"obj/yangpi",
       __DIR__"obj/madao",
       __DIR__"obj/shoujuan",
       __DIR__"obj/shoujuan",
       __DIR__"obj/shoujuan",
       __DIR__"obj/jiunang",
       __DIR__"obj/shoujuan",
});
void destob(object ob);
void create()
{
        set_name("蘇普", ({ "supu"}));
        set("gender", "男性");
        set("age", 21);
        set("long", "一個年輕的哈薩克牧羊人, 哈薩克第一勇士蘇魯克的兒子。\n");
        set("attitude", "heroism");
        set("level", 25);
        set("inquiry", ([
            "阿曼" : "阿曼是我的心上人，我每次殺了野狼都會送她狼皮。\n",
            "李文秀" : "她的歌唱得最好聽的了，有人說她比天鈴鳥唱得還好。
但這幾年來，我一直沒聽到她唱歌，一直沒在見到她。\n",
//            "摔跤" : (: ask_me :),
 //          "比試" : (: ask_me :),
            "計爺爺" : "就是計老人啊，他會釀又香又烈的美酒，會醫牛羊馬匹的疾病。\n",
            "蘇魯克" : "那是我阿爹，是哈薩克族的第一勇士！哈哈！\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"蘇普自豪地嚷道: 我也要學我阿爹成為哈薩克第一勇士。\n",
"蘇普自言自語: 從哪兒去弄一張上等的狼皮，送給阿曼呢? \n",
        }) );
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}
