#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("奇的訊息顯示器",({"msg's box","box"}) );
        set("long","這是奇用來顯示msg 給user() 知道的機器。\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","個");
                set("value",100);
        }
        setup();

}
void init()
{
        add_action("do_show","show");
}


int do_show()
{
        message("world:world1:vision",
HIG"奉天承運，奇爺昭曰:\n\n"
+HIW"今兒個天氣好晴朗，處處好風光，舉足熙熙然以舒養心性。\n"
+HIW"然人生自古誰無死，患吾後繼無人，今見"+HIY" 遊龍俠(kkeenn) \n"HIW
 +"乖巧聰明，"+HIW"望其用心學習，發揚 DS 。\n\n" NOR

+CYN "(遊龍俠的權限從 (apprentice) 升成 (admin) 。)\n\n" NOR
      ,users() );







return 1;
}

