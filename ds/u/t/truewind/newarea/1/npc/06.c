inherit NPC;
void create()
{
  set_name("湘兒", ({ "Xiao-er","Xiao","er","xiao" }) );
  set("gender", "女性" );
  set("long",@LONG
湘兒是琴操的好姊妹，春風樓的侍女，最擅長的事情是喝酒，另外還
吹得一管好蕭。她穿著一襲露肩淡綠背心，繡花長裙，笑嘻嘻的招待
著春風樓的客人。
LONG
);      
  set("age",20);
  set("level",14);
  set("race","human");
  setup();
  carry_object(__DIR__"armor/06")->wear();
}