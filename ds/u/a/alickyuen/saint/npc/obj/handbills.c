//updated
inherit ITEM;
void create()
{
        set_name("傳單", ({ "handbills" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
                        "一張宣傳單張，上頭有一個標誌。\n"
                        "上面寫了一些字：\n"
                        "『各位人士，本店新張開幕，所有蛋糕一律九折，特價酬賓。\n"
                        "幻彩蛋糕屋示』\n");

                set("value", 0);
                  set("no_sac",1);
        }
}