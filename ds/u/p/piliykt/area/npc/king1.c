#include <ansi.h>
inherit NPC;
void create()
{
        set_name("劉煜",({ "liu ui","liu","ui" }) );
        set("title",HIY "趙王" NOR);
        set("long",@LONG
你眼前這個人, 可是當今皇帝, 親賜封趙王的劉煜, 看他一身華貴的
衣飾, 便知道他可是個有錢有勢的人, 他似乎好像有煩惱.
LONG    
);

        set("race","人類");
        set("age",50);
        set("level",15);
        set("attitude","friendly");
        set_skill("dodge",30);
        set_skill("unarmed",30);
        set_skill("parry",20);
         set("chat_chance", 10);
        set("chat_msg_combat", ({
                "劉煜說道：該怎麼辦！怎麼辦！誰來幫幫我！\n",
                (:command("sigh"):),
         }) );
set("talk_reply", @LONG
怎麼辦...我的女兒不見了...
LONG );
set("inquiry/女兒", @LONG
我的女兒叫趙書宇,她忽然失蹤了,你可以幫我找她嗎??
LONG );
setup();
add_money("coin",2000);           
}

