inherit ITEM;

void create()
{
    set_name("秘銀礦", ({"mercury mine", "mine"}));
    if( !clonep() ) {
        set("long", @LONG
秘銀礦是種比黃金還珍貴的金屬，但數量也非常稀有。
只需要一點點秘銀礦，隨隨便便的打鐵師傅，也能打造
出神兵利器。
LONG
);
        set("value", 10000);
        set("unit", "個");
        set("weight", 1000);
      } else
        set_default_object(__FILE__);
    setup();
}

