inherit __DIR__"std_card.c";
void create()
{
  set("short","龍人法師");
  set("pow", ({1,1,4,2}) );
  set("lv",2);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",14);
  set("long",@LONG
全身佈滿爬蟲類的鱗片, 擁有不低的智慧與強壯的體格, 有些龍人在
死後甚至會變成石塊或是發出毒氣, 龍人法師擁有黑暗之后付與的黑
暗魔法, 但與精靈與人類的法師比起來, 仍就遜色不少, 相傳龍人是
惡龍對善龍的蛋下了詛咒而孵化出來的。
LONG
);
  setup();
}