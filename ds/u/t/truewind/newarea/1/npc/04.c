inherit NPC;
void create()
{
  set_name("公孫惡", ({ "Gon-sun Er","Er","er" }) );
  set("gender", "男性" );
  set("long",@LONG
公孫輩中的老大，一身橫肉，善使狼牙剛鎚，專門趕走在春風樓鬧事
的客人。他穿著一件青色短衣，內襯軟剛甲，看起來不好惹的樣子。
LONG
);      
  set("age",22);
  set("level",19);
  set("race","human");
  setup();
}