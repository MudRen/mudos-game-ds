inherit NPC;
void create()
{
  set_name("菀兒", ({ "Wan-er","Wan","wan","er" }) );
  set("gender", "女性" );
  set("long",@LONG
菀兒是春風樓的侍女，近兒個才進來。菀兒沒有湘兒窈窕多姿，不過
寫的一首好詞，又能歌唱，穿著一襲鵝黃水袖帶碎花長裙，別有一番
風情。
LONG
);      
  set("age",20);
  set("level",12);
  set("race","human");
  setup();
  carry_object(__DIR__"armor/03")->wear();
}