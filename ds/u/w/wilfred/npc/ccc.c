inherit NPC;
void create()
{ set_name("變變人",({"banban"}));
  set("long",@LONG
不要亂來~~~~~~ 人家可是很純潔的~~~~~~
      如果要使我作動作, 請用 p xxx
      要改我的中文名字, 請用 cn xxx
      要改我的英文名字, 請用 en xxx
LONG
);
  set("age",10);
  set("gender","男性");
  set("level",1);
  setup(); }
void init()
{
if(geteuid(this_player()) != "wilfred") return;
 add_action("p","p");
  add_action("cn","cn");
  add_action("en","en"); }
int p(string str)
{ command(str);
  return 1; }
int cn(string str)
{   set_name(str,({query("id")}));
  return 1; }
int en(string str)
{  set_name(query("name"),({str}));
  return 1; }
