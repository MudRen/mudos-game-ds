
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "明教"
#define CLUB_ID "ming"

inherit FINGER;

void create()
{
        set_name(HIR"聖─火─令"NOR,({"Plate of Holy Fire","plate"}));
        set_weight(9999999);
        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("value",0);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("no_get",1);
                set("no_give",1);
                set("unit","只");
                set("long",@LONG
這是用精剛練成的紅色令牌，上面透著紅光是教中鎮教之寶
由奇巧匠人所製，只要出示令牌，大江南北暢行無阻。

在前任林教主遠赴海外鑽研精深技藝后，此令牌就留在此處
供後人景仰追思。
LONG
                );
        }
        set("club_id",CLUB_ID);
        set("club",CLUB_NAME);
        set("sub_club",({"風雷堂","闇燄堂","天樞堂","青木堂"}));
        set("armor_prop/shield", 1);
        setup();
}
