inherit NPC;
void create()
{
  set_name("公孫無忌", ({ "Gon-sun Wugi","Wugi","wugi" }) );
  set("gender", "男性" );
  set("long",@LONG
你稍微抬頭才發現公孫無忌站在你面前。無忌身長過人，兩道銳利的
橫眉明顯是嬤嬤的遺傳，除此之外身材略微削瘦。公孫輩中的老二。
LONG
);      
  set("age",25);
  set("level",18);
  set("race","human");
  setup();
}