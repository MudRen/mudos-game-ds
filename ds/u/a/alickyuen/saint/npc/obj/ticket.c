//updated
inherit ITEM;
void create()
{
        set_name("動物園入場卷", ({ "ticket" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
                        "一張入場卷，上頭有動物園的標示。\n"
                        "上面寫了一些字：「新張開幕,免費入場！！」\n"
                        "看來你是給那奸商騙了錢...... \n");
                set("value", 50);
                  set("no_sac",1);
        }
}