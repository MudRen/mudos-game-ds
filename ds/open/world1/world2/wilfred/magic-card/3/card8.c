inherit __DIR__"std_card.c";
void create()
{
  set("short","青樓女子");
  set("pow", ({1,1,1,1}) );
  set("lv",1);
  set("ver",3);
  set("ver_n","武神");
  set("num",8);
  set("long",@LONG
平常在樓層之上觀看風景的一個青樓女子，她一臉憂愁的樣子
，似乎有著無限的煩惱，拿起她手中的那個箏，不時的彈起那弦，
鼓起一陣陣的傷感與悲傷，你可以問她有關 song 的事，她會跟你
她所會唱的歌曲。
LONG
);
  setup();
}
