#include <ansi.h>
inherit NPC;
mapping *combat_action = ({
        ([      "action":               "$N用它的利嘴朝$n的$l一陣猛咬",
                "attact_type":  "bar",  
                "damage_type":  "咬傷",
        ]),
        ([      "action":               "$N突然張開翅膀向$n的方向掃了過去",
                "attact_type":  "bar",
                "damage_type":  "撞傷",
        ]),
        ([      "action":               "$N對準$n的$l猛然吐出一道火焰",
                "attact_type":  "bio",
                "damage_type":  "燒傷",
        ]),
    ([  "action":       "$N瘋狂的舞動利爪狂抓$n的$l",
                "attact_type":  "bar",
                "damage_type":  "抓傷",
        ]),
});
void do_clean();

void create()
{
       set_name( HIR"火鳳凰"NOR ,({ "fire phoenix","phoenix","fire" }) );
       set("title",HIC "神鳥" NOR);
         set("long",@LONG
火鳳凰是一隻傳說中的生物, 兩眼發紅, 全身長滿了火羽毛, 翅膀張
開可達五尺長, 喜歡火熱的地方, 而且全身還會發出火焰, 讓靠近牠
的任何一物, 都燒成灰燼.
LONG    
);
         set("race", "野獸");    
         set("attitude", "aggressive");
         set("gender", "牠");
         set("age",35);
         set("level",60);
         add("addition_armor",90);
         add("addition_damage",60);
        set("chat_chance", 13);
        set("chat_msg",({ 
        "火鳳凰身上發出雄雄的烈火。\n",
        "附近忽然有一陣熱氣讓人喘不過氣來。\n",
        "附近忽然有一陣熱氣讓人喘不過氣來。\n", 
        "火鳳凰發出陣陣的怒吼聲。\n",
         }));      
setup();
carry_object(__DIR__"eq/cloth_2.c")->wear();
       
set("actions", (: call_other, __FILE__, "query_action" :));
 }
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob ) 
         {
                 ::die();
                 return;
         }
         message("world:world1:vision",
HIY"\n【武林消息】"+HIW "傳說中的 " HIR"神鳥 "HIR"火鳳凰 "NOR"死在 "+ob->name(1)+" 的手中。\n\n"+NOR
        ,users());

            ob->add("popularity",2); //聲望
         ::die();
         return;
}

