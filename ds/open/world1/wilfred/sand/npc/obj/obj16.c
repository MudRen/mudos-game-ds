inherit ITEM;
void create()
{
  set_name("八卦鏡",({"eight mirror","mirror"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",@LONG
一面光亮平滑的鏡子，上頭八個方位寫了
『 乾、巽、坎、艮、坤、震、離、兌 』
八個對應的文字。
LONG
);
    set("value",1000);
  }
  setup();
}
