#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIR"德洛克"NOR,({"joshua fireseed","fireseed","joshua"}) );
        set("title",MAG"魔鬼火砲商"NOR);
        set("long","一名星球間通緝的超級殺人魔, 聽說他上次在公年
3002年逃獄時, 順利的搶到一艘軍火艦, 現下火力
充足幹起販賣軍火的勾當了！\n");
        set("sell_list",([
__DIR__"wp/mag.c"  : 5,
__DIR__"wp/cannon.c"  : 5,
__DIR__"wp/mag_clip.c"  : 5,
__DIR__"wp/cannon_clip.c"  : 5,
__DIR__"wp/pistol.c"  : 5,
__DIR__"wp/pistol_clip.c"  : 5,
__DIR__"wp/tranquilizer.c"  : 5,
__DIR__"wp/anesthetize.c"  : 5,
__DIR__"wp/anesthetize_clip.c"  : 5,
        ]) );
        set("age", 29);
        set("level", 67); 
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
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
     message("world:world3:vision",
HIG"\n【星際消息】"+HIW"重犯-"HIR"德洛克"HIW"被"+ob->name(1)+"逮補歸案了！！\n\n"+NOR,users());
        write("因為你協助星際戰警破案, 所以聲望急速上升了!!");
           ob->add("popularity",5);
        ::die();
        return;
}

