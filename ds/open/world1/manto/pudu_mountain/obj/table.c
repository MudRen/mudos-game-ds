
inherit  ITEM;
void  create()
{
        set_name("石桌",({"table"}));
        set_weight(200000);
set("long","石桌之上，縱橫交錯著道道劃痕，縱橫之痕深淺不同，卻俱是圓潤挺直，無一曲折不均。\n");
        if(clonep()) set_default_object(__FILE__);
        else
        {
                set("unit",  "張");
                set("material",  "stone");
                set("value",  2000);
                set("no_get",  1);
                set("amount",30);
        }
        setup();
}

