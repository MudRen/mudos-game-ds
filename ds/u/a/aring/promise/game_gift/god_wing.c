//徵文比賽eq 200.10.14 by Promise@DS
#include <armor.h>
#include <ansi.h>
inherit HANDS; 
void create()
{
        set_name(HIW"天使之翼"NOR,({"the wing of angel","wing","angel","the","of","t","w","o","a"}) );
        set("long",HIW"    這是一個造型奇特的手套，那不知明的材質和凹凸不平的外表，
更突顯了它的不平凡，在那之上汎著淡淡的銀白色光芒，有著彷彿能
射透一切黑暗的光華，那柔和的光芒在手套的表面淡淡的散發著，好
像隨時都可能熄滅，但無論是在多熾烈的太陽底下一樣還是可以清楚
的看到它的光輝，不過令人奇怪的是，為什麼這手套只有左手的部分
，而沒有右手的部分。
\n"NOR);
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",2);
         set("material","silver");
         set("unit", "個" );
         set("no_sell",1); 
         set("no_give",1);
         set("no_auc",1);
         set("no_drop",1);         }
        set("armor_prop/armor", 1);
        set("wear_msg","
      [0;1m�[1m�[1m�[1mi[1m�[1mh[1m�[1mg[1m�[1mf[1m�[1me[1m�[1md[1m�[1me[1m�[1mf[1m�[1mg[1m�[1m�[0m "HIG"當"NOR"$N"HIG"將"HIW"天使之翼"HIG"拿起
[0;1;32m [1m [1m [1m [1;37m�[1m�[1;47m�[1m�[1m�[1mi[1m�[1mi[1m�[1m�[1m�[1mh[1m�[1mg[1m�[1mf[1m�[1me[1m�[1md[1m�[1m�[1;40m�[1m�[1m [0m"HIW"天使之翼"HIG"的光芒越來越曜眼
[0;1;32m [1m [1;37m�[1m�[1;47m�[1m�[1m�[1mi[1m�[1m�[1m�[1mi[1m�[1mg[1m�[1mf[1m�[1me[1m�[1md[1m�[1mc[1m�[1m�[1;40m�[1m�[1;32m [1m [1m [0m"HIG"當你再次看清的時候
[0;1m�[1m�[1;47m�[1m�[1m�[1mi[1m�[1m�[1m�[1m�[1;40m�[1m�[1;47m�[1mh[1m�[1mg[1m�[1me[1m�[1mc[1m�[1mi[1;40m�[1m�[1;32m [1m [1m [1m [1m [0m"HIG"$N的左手已經化成一片羽翼
[0;1m�[1m�[1m�[1mi[1m�[1mi[1;47m�[1m�[1;40m�[1m�[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m�[1m�[1;32m [1m [1m [1m [1m [1m [1m [0m"HIG"並散發著和原來一樣淡淡的光輝\n"NOR);
     set("unequip_msg",HIG"當$N將"HIW"天使之翼"HIG"脫下時，左手的羽翼化為點點光芒散去，回復到原有的樣子。\n"NOR);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

