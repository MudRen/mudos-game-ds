inherit ITEM;

void create()
{
    set_name("佛心真經", ({"buddha book", "book"}));
    if( !clonep() ) {
        set("long", @LONG
佛心真經是佛門中三大經書之一，傳聞裡頭記載的佛學
包含這宇宙間的萬物生存之道，內容可說是深奧難解。
LONG
);
        set("value", 10);
        set("unit", "個");
        set("weight", 10);
      } else
        set_default_object(__FILE__);
    setup();
}

