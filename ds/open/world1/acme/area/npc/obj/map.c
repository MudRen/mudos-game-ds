inherit ITEM;
void create()
{
        set_name("天城地圖",({"skycity_map","map"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
       else {
         set("long",@long

       這是一張由過往旅客所繪製的天城地圖。
        __________________∩________________
       |                 ／                 |
       |  ξ天城ξ     □                   |  ∩=城門
       |               ∣                   |  ●=客棧
       |   ㊣      ０–□                   |  ㊣=當舖
       |   ∣          ∣                   |  ０=藥舖
       |   □          □      △           |  ＄=錢莊
       |   ∣          ∣      ∣           |  △=布莊
       ∩–□–□–□–□–□–□–□–□–∩
       |       ∣      ∣              ∣   |
       |       ●      □–□          ＄   |
       |               ∣                   |
       |               □                   |
       |               ∣                   |
       |_______________∩___________________|
long
);
       set("unit","張");
       }
    setup();
}
