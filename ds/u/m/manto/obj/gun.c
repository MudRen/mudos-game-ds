#include <mudlib.h>
#include <weapon.h>
#include <ansi.h>

inherit BOW;

string *name    = ({ HIW"ＡＫ－４７"NOR});  
void create()
         {
          set_name("ＡＫ－４７", ({"gun"}) );
          set_weight(1);
          if( clonep() )
                set_default_object(__FILE__);
          else {
               set("unit", "把");
               set("long","\n");
               seteuid(getuid());
               }
          init_bow(30);
          setup();
}

void init()
{
  add_action("fire", "shot");
}
int query_auto_load()
{
return 1;
}

int fire(string str)
{
  object target,targetenv,ob;
  ob=this_object();
  if(this_player() -> query("id") != "manto" && this_player() -> query("id") != "uchimaha")
  return notify_fail("指紋核對不符，無法使用此槍枝!\n");
  if(!str || str == "") 
    {
      write(HIW"你試射了一槍來測試彈道, 看來這槍正處在最佳的狀況。\n"NOR);
      tell_room(environment(this_player()), HIC+this_player()->query("name")
                +HIW"舉起"+(string)ob -> query("name")+"試射了一槍, 看來又有人要被暗算了。\n"NOR,
                ({this_object(), this_player()}));
      return 1;
    }
  target=present(str,environment(this_player()));
  if(!target) {
  write(HIC+"大近視眼﹐看清楚目標再射擊﹗\n"+NOR);
  return 1;}
  targetenv=environment(target);
  write( HIW"你隨意的對"HIC + (string)target -> query("name") + HIW"擊出一彈"
         + ", "NOR + RED"準確地貫穿了他的腦袋﹗\n"NOR );
  tell_room(environment(this_player()),""+HIC
            +(string)this_player()->query("name")
            +HIW"舉起"+(string)ob -> query("name")+"，對著"HIC + (string)target -> query("name")
            +HIW"的眉心發出一顆子彈﹗\n"NOR , ({this_player() , target}));

  tell_room(environment(target) , HIW"忽然一聲槍響, 只見一顆子彈準確地貫穿了"HIC
            + (string)target -> query("name")
            + HIW"的額頭正中央﹗\n"NOR , ( { this_player() , target } ) );
     
  tell_object(target,
              HIW"忽然一聲槍響, 一顆子彈已經貫穿了你的額頭正中央﹗\n"NOR +
              "( 你"+RED"受傷過重﹐已經有如風中殘燭﹐隨時都可能斷氣。"NOR
              +" )\n");

  target -> set("env/immortal" , 0);
  this_object() -> destruct();
  target->set_temp("temp/death_type","[刺殺身亡]"); 
  target -> die();  

  return 1;
}
int query_autoload() { return 1; }

