// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
          set_name( HIY "蛋黃酥娃娃" NOR,({"mooncake doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
中秋節的傳統食品是月餅，月餅是圓形的，象徵團圓，反映了人們對家人團聚
的美好願望。在民間，每逢八月中秋都有祭月的風俗。「八月十五月兒圓，中秋
月餅香又甜」，這句名諺道出中秋之夜城鄉人民吃月餅的習俗。月餅最初是用來
祭奉月神的祭品，後來人們逐漸把中秋賞月與品嚐月餅， 作為家人團圓的象徵，
慢慢月餅也就成了節日的禮品。
LONG
                );
                set("undead_msg",HIY"\n\t就在千鈞一髮之際，$N身上的$n突然冒出刺眼的光芒，抵消住了這致命一擊!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }



