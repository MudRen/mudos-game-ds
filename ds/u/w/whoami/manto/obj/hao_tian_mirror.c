inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIC"昊天鏡"NOR, ({ "hao tian mirror", "mirror" }));
        set_weight(2000);
        set("long",@LONG
銅鏡大如磨盤，像是古銅所制，鏽跡斑斑，看起來年代久遠。鏡面黑
幽幽的，人站在正面也不能顯出影像，說是鏡子還不如說像個無底的
黑洞更准確些。背面篆刻了些像蝌蚪一樣的古怪文字，也不知道是甚
麼人在甚麼時代弄上去的，反正這鏡子因此就透出了神秘感，傻瓜也
知道這樣的東西是寶物。
LONG
);
  if( clonep() )
    set_default_object(__FILE__);
else
  {
   set("unit", "隻");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
}
  setup();
}

void init()
{
  add_action("do_use","use");
}

int do_use()
{
  object z,me,env;
  me=this_player();
  env = environment(me);
  if(!objectp(z=present("mirror",this_player()) ) )
    return notify_fail("你沒有東西可以使用。\n");
  if( me->is_fighting() )
    return notify_fail("你正在戰鬥中，無暇分心。\n");

message("world:world1:vision",
HIY"\n"+me->query("name")+""NOR+HIW"悠悠然的開口：「"NOR+WHT"我想知道。。。"NOR+HIW"」\n\n"NOR
        ,users() );
       call_out("quest1",4);
  return 1;
}

void quest1()
{
        message("world:world1:vision",
WHT"\t\n『死去的人和活著的人，究竟是誰。。。比較悲傷？』\n"NOR
        ,users() );
       call_out("quest2",3);
        return;
}

void quest2()
{
        message("world:world1:vision",
WHT"\t\n『遺忘的人和記得的人，究竟是誰。。。比較痛苦？』\n"NOR
        ,users() );
       call_out("quest3",3);
        return;
}

void quest3()
{
        message("world:world1:vision",
WHT"\t\n『等待的人和期待的人，究竟是誰。。。比較難熬？』\n"NOR
        ,users() );
       call_out("quest4",3);
        return;
}

void quest4()
{
        message("world:world1:vision",
WHT"\t\n『想不起來的人和想得起來的人，究竟是誰。。。比較快活？』\n"NOR
        ,users() );
       call_out("quest5",3);
        return;
}

void quest5()
{
        message("world:world1:vision",
WHT"\t\n『所有人和某個人，究竟是誰。。。比較重要？』\n"NOR
        ,users() );
        return;
}

