inherit ITEM;
void create()
{
        set_name("貓眼石",({"cat's-eye","eye","cat's"}) );
        set("long",@LONG
這是一顆相當稀有的寶石，在寶石裡面有兩條黑色的細紋，完美的
弧度使得整寶石看起來跟貓的眼睛一樣美麗。
LONG);
        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
  else
   {
          set("value",50000);
          set("unit","顆");
        }
        setup();
}
