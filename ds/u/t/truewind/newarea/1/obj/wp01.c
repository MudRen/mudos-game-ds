#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(HIM"鴛鴦握",({"Yuan-yang stiletto","stiletto"}) );
        set("long","一把特別鑄造的匕首，刀身薄而長，割透空氣不發出一絲聲響。\n"+
        "握柄上刻著兩隻交頸的鴛鴦，十分恩愛的模樣。\n");
          set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
              set("value",1500);
              set("limit_dex",25);
        }
              set(HIC"wield_msg","一道金屬的藍光亮了一下。\n");
          init_dagger(25);
        setup();        
}

