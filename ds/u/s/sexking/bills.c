inherit ITEM;
void create()
{
        set_name("夢幻七域傳單", ({ "ds bills","ds","bills" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
                        "這是一張廣告傳單，上面寫著歡迎參觀夢幻七域網站。\n"
                        "我們須要你的支持：\n"
                        "請到:。\n"
                        "home.pchome.com.tw/computer/dreamseven參觀吧!\n");

                set("value", 0);
                  set("no_sac",1);
        }
}


