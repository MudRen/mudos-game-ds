#include <ansi.h>
inherit NPC;
void create()
{
  set_name("秋田犬", ({ "akita","dog" }));
  set("long",@long
屬於大型犬，是獵獸犬與土犬交配而得到的犬種，上被毛為粗的中短
毛，下被毛短而密生，毛色有紅色、紅芝麻色、白色、白芝麻色、黑
芝麻色、並有虎毛斑，尾巴內側的毛為白色，當尾巴向上捲曲與身體
的毛色成對比，顯得十分美麗。
long);      
  set("race","野獸");
  set("age",3);
  set("level",7);
  set("limbs", ({ "頭部","尾巴","身體","前腳","後腳" }) );
  set("verbs", ({ "bite", "claw"}));
  set("chat_chance", 5);
  set("chat_msg",({
  "秋田犬抬起頭來，朝你搖了搖尾巴。\n",
  "秋田犬低頭跟在你後面，不時聞聞你的腳跟。\n",
  (: command("dog"):),
  }));
  setup();
}
