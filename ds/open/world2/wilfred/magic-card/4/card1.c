inherit __DIR__"std_card.c";
void create()
{
  set("short","地精");
  set("pow", ({2,1,3,1}) );
  set("lv",1);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",1);
  set("long",@LONG
全身上下散發著令人難以忍受的惡臭, 這就是地精給人最普遍的印象
他們通常像小狗一樣的跟在當權者的後面狗腿, 一個落單的地精就跟
蟑螂一樣好解決。
LONG
);
  setup();
}