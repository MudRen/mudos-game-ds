inherit ITEM;
void create()
{
        set_name("木牌", ({ "wood sign","sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",
"這一面老舊的木牌，上頭刻畫了易經八卦圖。\n"
"               ________           \n"
"             ／  _∣_  ＼         \n"
"           ／＼／ ∣ ＼／＼       \n"
"          ∣__∣_┌┐_∣__∣      \n"
"          ∣  ∣ └┘ ∣  ∣      \n"
"           ＼／＼_∣_／＼／       \n"
"             ＼___∣___／         \n"
        );
        set("no_get",1);
        set("no_sac",1);
        }
     setup();
}
