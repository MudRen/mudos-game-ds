#include <ansi2.h>
inherit ITEM;
mapping color = ([
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR,
"$BLINK$" : BLINK,
"$CLR$" : CLR,

"$HBRED$" : HBRED,
"$HBGRN$" : HBGRN,
"$HBYEL$" : HBYEL,
"$HBBLU$" : HBBLU,
"$HBMAG$" : HBMAG,
"$HBCYN$" : HBCYN,
"$HBWHT$" : HBWHT,
"$BBLK$" : BBLK,
"$BRED$" : BRED,
"$BGRN$" : BGRN,
"$BYEL$" : BYEL,
"$BBLU$" : BBLU,
"$BMAG$" : BMAG,
"$BCYN$" : BCYN,
]);

void create()
{
  set_name("Whoami"HIB"玩具"HIW"一"HIB"號機"NOR, ({ "whoami toy","toy" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","用 change 指令可以改 name nickname title goto dest clone leave long 的 msg");
  setup();
}

void init()
{
  add_action("do_change","change");
}

int do_change(string arg)
{
  object target, me = this_player();
  int i;
  string trg, order, carg;
  string *source_color;
  string *target_color;
  
  
  if( !arg ) return notify_fail("change <id> <nickname, name, ...> to <想改成的東西>\n");
  if( sscanf(arg, "%s %s to %s", trg, order, carg) == 3 )
    {
     target = present(trg, environment(me));
     if( !target ) target = present(trg, me);
     if( !target ) return notify_fail("這裡沒有 " + trg + "。\n");
    } else if( sscanf(arg, "%s to %s", order, carg) == 2 ) {
     target = me;
    }
  
  if( !carg ) return notify_fail("沒輸入字串是不會動的喔！\n");
  if( !order ) return notify_fail("沒輸入命令是不會動的喔！\n");

  source_color = keys(color);
  target_color = values(color);
  for(i=0;i<sizeof(source_color);i++)
  carg = replace_string(carg, source_color[i], target_color[i]);

  switch( order )
  {
          case "goto" :     
               target->set("env/msg_min" , carg + NOR);
               break;
          case "leave" :
               target->set("env/msg_mout" , carg + NOR);
               break;
          case "clone" :
               target->set("env/msg_clone" , carg + NOR);
               break;
          case "name" :
               target->set("name" , carg + NOR);
               break;
          case "dest" :
               target->set("env/msg_dest" , carg + NOR);
               break;
          case "nickname" :
               target->set("nickname" , carg + NOR);
               break;
          case "title" :
               target->set("title" , carg + NOR);
               break;
          case "long" :
               target->set("long", carg + NOR);
               break;
  }
  message_vision(NOR"$N的"+ order +" msg被$n修改了。\n", target, me); 
  me->save();
  return 1;
}
int query_autoload() { return 1; }

