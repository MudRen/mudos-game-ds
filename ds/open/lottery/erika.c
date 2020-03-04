#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
        set_name( "繪理香", ({ "sawajiri erika", "erika"}));
        set("long", @LONG
繪理香血型A型，身高160cm，繪理香名字由來是花的名字，杜鵑花
科的一種(Erica)。外表雖有如少女般的清純，但性格卻是粗枝大葉，
繪理香本人曾說自己的個性很男孩子氣。

存貨請用 <list>
要買東西用 <buy 編號 ticket>、<buy 物品>、<buy 數量 物品>
要對獎用 <reward>
LONG
        );
        set("level", 1);
        set("title", HIG"獎卷商"NOR);
        set("gender", "女性");
        set("race", "人類");
        set("age", 42);
        set("exp",1000);
                set("attitude", "peaceful");   //溫和的 NPC。
                set("sell_list", ([     
             TICKET    : 1, 
                ]) );

  set("no_kill",1);
  set("no_fight",1);
  set("chat_chance", 1 );  //動作機率
  set("chat_msg", ({       //動作內容
        "繪理香甜甜的笑著：「這位大老闆, 要不要買點彩卷<buy>啊？我賣的彩卷<list>中獎率很高喔！！」\n",
        (:command("smile"):),
        }) );

    setup();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_reward","reward");
}
