#include <ansi.h>
inherit NPC;
void create()
{
  set_name("婁東玉", ({ "lou dong-yu","dong","yu","lou" }) );
  set("gender", "女性" );
  set("long",@LONG
與琴操並稱春風樓才女的婁東玉，能歌能舞，尤擅熱情的胡人舞蹈，
是故許多人慕名而來，只為一睹婁東玉的舞姿。
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
}