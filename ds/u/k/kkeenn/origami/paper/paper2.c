#include <ansi.h>
#include <armor.h>
inherit CLOTH;
int check(object me);
void create()
{
  set_name("���Y�P��", ({ "none paper", "paper" }) );
  set("long", " 
    �o�O�@�i�w�Q�馨�۴����F�P���Z�Ҫ��ƨ��P�ȡC
"HIG"�ƨ��Gchange xxx"NOR"
xxx ����z���ƨ����F�W�١A�Фp�ߨϥΡA�קK�~�ơC
"NOR);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");
    set("long", " 
"NOR);
    set("value",0);
    set("no_drop",1);
    set("no_sell",1);
    set("no_get",1);
    set("no_sac",1);
    set("no_give",1);
  }
   setup();
}
int query_autoload() { return 1; }
void init()
{ 
    object me= this_player();
    add_action("do_change", "change");
    if( !me ) return;
    if( !userp(me) ) return;
    check(me);
}
int check(object me)
{
  object ob = this_object();
if(me->query("family/name"))
   { 
this_object()->set_name(me->query("family/color")+"��"+me->query("family/name")+"�P��", ({me->query("family/id")+" paper", "paper" }) );
  }  
  add_action("do_wear","change");
  add_action("do_nowear","wear");
}
int do_wear(string arg) 
{
object obj,me;
int i = this_player()->query("max_ap") / 100 * this_player()->query("family/level");obj = this_object();
me  = this_player();
if(!arg) return notify_fail("�A�Q�ƨ���...�H\n"); 
if( arg != me->query("family/id")) return notify_fail("�A����ƨ�����"+ arg +"�աI\n"); 
if(me->query_temp("change")) return notify_fail("�A�w�g�b�ƨ����A�F�I\n");
message_vision(HIG"$N�j�ܤ@�n�G�۴��ƨ��Z�� - "HIW+me->query("family/color")+me->query("family/name")+HIG" - �I\n"NOR,me);
if( environment(obj) == me )
  {
obj->set_name(me->query("family/color")+me->query("family/name")+"�Z",({"armor"}));
obj->set("armor_prop/name", ({ me->query("family/color")+me->query("family/name") }) );
obj->set("armor_prop/armor",me->query("family/level") * 3);
call_out("back",i,me,obj);
  }
obj->set("long", "�o�O�@����F�Z�ҡC"NOR);
me->set_temp("change",1);
obj->wear();
 return 1;
}
void back(object me,object obj)
{
obj = this_object();
me  = this_player();
write(HIW"�L�q���i�D�A�GBeep�I�A���ƨ��෽�w�g�κɡI\n"NOR);
obj->unequip();
obj->set_name(me->query("family/color")+"��"+me->query("family/name")+"�P��", ({me->query("family/id")+" paper", "paper" }) );
obj->delete("armor_prop/name");
me->delete_temp("change");
obj->set("long", " 
    �o�O�@�i�w�Q�馨�۴����F�P���Z�Ҫ��ƨ��P�ȡC
"HIG"�ƨ��Gchange xxx"NOR"
xxx ����z���ƨ����F�W�١A�Фp�ߨϥΡA�קK�~�ơC
"NOR);
message_vision(HIG"$N���ƨ��෽�κɡA�ܦ^���q�H�F�C\n"NOR,me);
return;
}
int do_nowear(string arg) 
{
object me;
me  = this_player();
if(arg == "paper" || arg == me->query("family/id")+" paper" || arg == "all")
 {
  if(!me->query_temp("change")) 
   {
   write("�o��˳Ʒl�a�F�A�ä���˳�\n");
   return 1;
   }
 }
}

