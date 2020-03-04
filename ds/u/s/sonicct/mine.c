#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("地雷", ({ "land mine","mine" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long","這是一顆殺傷力強大的地雷，小心別踩到了。\n");
           set("no_sell",1);
           set("no_give",1);
           set("unit","顆");
           set("value",1000);
        }
setup();
}
void init()
{
  object me;
  me=this_player();
  add_action("do_touch","touch");
  if(me->environment() ) return 0;
  call_out("die",1,me);
}
void do_touch(string arg)
{
  object me;
  string uid;
  me=this_player();
  if(arg != "on")
  {
   notify_fail("什麼？\n");
  }
  else {
     this_object()->set_name(HIR"(熱烈引爆中)"NOR+" 地雷", ({ "land mine","mine" }));
     this_object()->set("touch/on",1);
     uid=me->query("id");
     this_object()->set("touch/id", uid );
     notify_fail("你將地雷的保險打了開來。\n");
  }
}
void die()
{
       int i,max;
       object me,obj;
       me=this_player();
       obj=this_object();
       i=random(5000)+1;
       if( (me->query("id")) == (obj->query("touch/id")) ) return 0;
       if(obj->query("touch/on")<1) return 0;
       if(i<30)
         {
           notify_fail("你感覺到附近怪怪的。\n");
         }
         else {
           message_vision("剎那間，一陣「隆∼隆∼∼」轟然巨響，塵灰四溢。\n",me);
           message_vision("突然間$N慘叫一聲，原來是誤觸地雷，只見$N的一隻腳朝你的方向飛了過來。\n",me);
           max=me->query("hp");
           me->set("hp",max-i);
           destruct(this_object());
         }
}
