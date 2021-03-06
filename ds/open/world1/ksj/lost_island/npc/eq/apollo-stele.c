#include <ansi.h>
inherit ITEM;
        
void create()
{
  set_name(HIY"太陽神石碑"NOR, ({"apollo stele","stele"}) );
  set("long",@LONG
一個三人高的大石碑，發出耀眼的光芒，石碑上刻著奇怪的文字，文
字間夾雜著一些凹槽，看樣子好像是要放入什麼東西(putting)？
LONG
);
  set_weight(1000);
//  set_max_capacity(4);
//  set_max_encumbrance(50000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "座");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_putting","putting");
}

int do_putting(string str)
{
  object me=this_player();
  object ob;

  if(str=="armor")
  {
    if(!ob=present("gold armor",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("armor_ok")==1)
    {
      write("黃金鎧甲已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金鎧甲嵌放在石碑上的盔甲狀凹槽中。\n"NOR,me);
    set_temp("armor_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="leggings")
  {
    if(!ob=present("gold leggings",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("leggings_ok")==1)
    {
      write("黃金脛甲已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金脛甲嵌放在石碑上的脛甲狀凹槽中。\n"NOR,me);
    set_temp("leggings_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="earring")
  {
    if(!ob=present("gold earring",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("earring_ok")==1)
    {
      write("黃金耳環已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金耳環嵌放在石碑上的耳環狀凹槽中。\n"NOR,me);
    set_temp("earring_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="boots")
  {
    if(!ob=present("gold boots",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("boots_ok")==1)
    {
      write("黃金長靴已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金長靴嵌放在石碑上的靴狀凹槽中。\n"NOR,me);
    set_temp("boots_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="finger")
  {
    if(!ob=present("gold finger",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("finger_ok")==1)
    {
      write("黃金戒指已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金戒指嵌放在石碑上的戒指狀凹槽中。\n"NOR,me);
    set_temp("finger_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="mask")
  {
    if(!ob=present("gold mask",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("mask_ok")==1)
    {
      write("黃金面具已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金面具嵌放在石碑上的面具狀凹槽中。\n"NOR,me);
    set_temp("mask_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="necklace")
  {
    if(!ob=present("gold necklace",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("necklace_ok")==1)
    {
      write("黃金項鏈已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金項鏈嵌放在石碑上的項鏈狀凹槽中。\n"NOR,me);
    set_temp("necklace_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="shield")
  {
    if(!ob=present("gold shield",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("shield_ok")==1)
    {
      write("黃金盾牌已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金盾牌嵌放在石碑上的盾牌狀凹槽中。\n"NOR,me);
    set_temp("shield_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="waist")
  {
    if(!ob=present("gold waist",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("waist_ok")==1)
    {
      write("黃金腰帶已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金腰帶嵌放在石碑上的腰帶狀凹槽中。\n"NOR,me);
    set_temp("waist_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="wrists")
  {
    if(!ob=present("gold wrists",me))
      return notify_fail("這樣東西是不能放進去的。\n");
    if(this_object()->query_temp("wrists_ok")==1)
    {
      write("黃金護腕已經嵌上石碑了！\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N將黃金護腕嵌放在石碑上的護腕狀凹槽中。\n"NOR,me);
    set_temp("wrists_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }


}

void summon_apollo()
{
  object me,b,ob,env;
  me=this_player();
  ob=this_object();
  env=environment(ob); 

  if(ob->query_temp("armor_ok")==1 && ob->query_temp("shield_ok")==1 
  && ob->query_temp("boots_ok")==1 && ob->query_temp("leggings_ok")==1
  && ob->query_temp("waist_ok")==1 && ob->query_temp("mask_ok")==1
  && ob->query_temp("necklace_ok")==1 && ob->query_temp("earring_ok")==1
  && ob->query_temp("finger_ok")==1 && ob->query_temp("wrists_ok")==1)
  {
    message_vision(HIY"\n石碑化為光柱直沖天際，太陽神－阿波羅從天而降，將一件金色盔甲交給$N。\n"NOR,me);
    new(__DIR__"apollo-armor")->move(me);
    message("world:world1:vision",
    HIG"\n\t【遺世島】："+HIY"太陽神－阿波羅現身島上，將身上的盔甲賜與"+me->name(1)+"。\n\n"NOR,users());
    env->set_temp("give_armor",1);
    destruct(ob);
    return;
  }
  else
  {
    message_vision(HIY"\n石碑散發出數道金光。\n"NOR,me);
    return;
  }
}
